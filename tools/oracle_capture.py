"""Capture non-invasive Android/Unity oracle artifacts through ADB.

The capture is intentionally read-only: package metadata, screenshot, UI XML,
activity state, and recent logcat. It does not tap or alter the running game.
"""
from __future__ import annotations

import argparse
import hashlib
import json
import subprocess
import time
from datetime import datetime, timezone
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DEFAULT_ADB = ROOT.parent / "platform-tools-latest-windows" / "platform-tools" / "adb.exe"
PACKAGE = "com.candywriter.bitlife"
ACTIVITY = "com.unity3d.player.UnityPlayerActivity"


def run(adb: Path, *args: str, timeout: int = 30) -> tuple[int, bytes, bytes]:
    proc = subprocess.run([str(adb), "-s", "127.0.0.1:58526", *args], capture_output=True, timeout=timeout)
    return proc.returncode, proc.stdout, proc.stderr


def text(adb: Path, *args: str) -> str:
    code, out, err = run(adb, *args)
    if code != 0:
        return f"[command failed {code}]\n{err.decode('utf-8', 'replace')}"
    return out.decode("utf-8", "replace")


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("--adb", default=str(DEFAULT_ADB))
    parser.add_argument("--label", default="capture")
    parser.add_argument("--count", type=int, default=1)
    parser.add_argument("--interval", type=float, default=1.0)
    args = parser.parse_args()
    adb = Path(args.adb)
    out = ROOT / "out" / "oracle" / args.label
    out.mkdir(parents=True, exist_ok=True)
    if not adb.exists():
        raise SystemExit(f"ADB not found: {adb}")

    package_dump = text(adb, "shell", "dumpsys", "package", PACKAGE)
    activity_dump = text(adb, "shell", "dumpsys", "activity", "activities")
    device_dump = {
        "devices": text(adb, "devices", "-l"),
        "wmSize": text(adb, "shell", "wm", "size"),
        "wmDensity": text(adb, "shell", "wm", "density"),
        "package": package_dump,
        "activity": activity_dump,
    }
    (out / "device_state.txt").write_text(json.dumps(device_dump, indent=2, ensure_ascii=False), encoding="utf-8")
    (out / "logcat.txt").write_text(text(adb, "logcat", "-d", "-t", "800"), encoding="utf-8")

    captures = []
    for index in range(args.count):
        stamp = datetime.now(timezone.utc).isoformat()
        prefix = f"{index:03d}"
        code, png, err = run(adb, "exec-out", "screencap", "-p")
        if code != 0 or not png.startswith(b"\x89PNG"):
            raise SystemExit(f"screencap failed: {err.decode('utf-8', 'replace')}")
        image_path = out / f"{prefix}_screen.png"
        image_path.write_bytes(png)
        run(adb, "shell", "uiautomator", "dump", "/sdcard/hermes_ui.xml")
        _, ui, _ = run(adb, "exec-out", "cat", "/sdcard/hermes_ui.xml")
        ui_path = out / f"{prefix}_ui.xml"
        ui_path.write_bytes(ui)
        captures.append({
            "index": index,
            "timestamp": stamp,
            "screen": str(image_path.relative_to(ROOT)).replace("\\", "/"),
            "screenSha256": hashlib.sha256(png).hexdigest(),
            "screenBytes": len(png),
            "ui": str(ui_path.relative_to(ROOT)).replace("\\", "/"),
            "uiBytes": len(ui),
        })
        if index + 1 < args.count:
            time.sleep(args.interval)

    report = {
        "targetPackage": PACKAGE,
        "targetActivity": ACTIVITY,
        "requestedTargetVersion": "3.25.3",
        "capturePurpose": "read-only APK oracle baseline",
        "adbSerial": "127.0.0.1:58526",
        "capturedAt": datetime.now(timezone.utc).isoformat(),
        "captures": captures,
        "notes": [
            "Unity Canvas UI may be absent from uiautomator XML.",
            "Package version must be checked before using this capture as a target fixture.",
            "This capture does not include private app data because run-as is unavailable on release APK.",
        ],
    }
    (out / "capture.json").write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

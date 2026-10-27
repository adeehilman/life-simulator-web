"""Generate reproducible extraction/runtime parity counts and source hashes."""
from __future__ import annotations

import hashlib
import json
import re
from pathlib import Path
from typing import Iterable

ROOT = Path(__file__).resolve().parents[1]
OUT = ROOT / "out"
WEB = ROOT / "web"


def sha256_file(path: Path) -> str:
    digest = hashlib.sha256()
    with path.open("rb") as handle:
        for block in iter(lambda: handle.read(1024 * 1024), b""):
            digest.update(block)
    return digest.hexdigest()


def count_files(path: Path, suffix: str | None = None) -> int:
    if not path.exists():
        return 0
    return sum(1 for item in path.rglob("*") if item.is_file() and (suffix is None or item.suffix.lower() == suffix))


def json_counts(path: Path) -> dict[str, int]:
    if not path.exists():
        return {}
    try:
        data = json.loads(path.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return {}
    result: dict[str, int] = {}
    if isinstance(data, dict):
        for key in ("manifestObjects", "indexedEntries", "webCsvFiles", "uniqueFunReferences", "resolvedCount", "unresolvedCount"):
            if isinstance(data.get(key), int):
                result[key] = data[key]
        summary = data.get("summary")
        if isinstance(summary, dict):
            for key, value in summary.items():
                if isinstance(value, int):
                    result[f"summary.{key}"] = value
    return result


def find_failed_assets() -> list[str]:
    index = OUT / "asset_index.json"
    if not index.exists():
        return []
    try:
        data = json.loads(index.read_text(encoding="utf-8"))
    except (OSError, json.JSONDecodeError):
        return []
    failed = data.get("failed", []) if isinstance(data, dict) else []
    return [str(item) for item in failed] if isinstance(failed, list) else []


def main() -> None:
    data_dir = WEB / "public" / "data"
    asset_dir = WEB / "public" / "assets"
    audio_dir = WEB / "public" / "audio"
    source_paths = [
        OUT / "il2cpp" / "dump.cs",
        OUT / "il2cpp" / "script.json",
        OUT / "il2cpp" / "global-metadata.dat",
        OUT / "data_index.json",
        OUT / "asset_index.json",
        OUT / "ghidra" / "decompiled_20methods.c",
        OUT / "EVIDENCE_LEDGER.json",
        OUT / "scenario_effect_coverage.json",
    ]
    hashes = {
        str(path.relative_to(ROOT)).replace("\\", "/"): sha256_file(path)
        for path in source_paths
        if path.exists() and path.is_file()
    }
    fun = json_counts(OUT / "ghidra" / "fun_resolution_14methods.json")
    asset = json_counts(OUT / "asset_index.json")
    coverage = json_counts(OUT / "web_coverage.json")
    manifest_audio_clips = 0
    coverage_path = OUT / "web_coverage.json"
    if coverage_path.exists():
        try:
            coverage_data = json.loads(coverage_path.read_text(encoding="utf-8"))
            manifest_audio_clips = int(coverage_data.get("manifestByType", {}).get("AudioClip", 0))
        except (OSError, ValueError, TypeError, json.JSONDecodeError):
            pass
    effect_domains = 0

    effect_path = OUT / "scenario_effect_coverage.json"
    if effect_path.exists():
        try:
            effect_domains = len(json.loads(effect_path.read_text(encoding="utf-8")).get("domains", []))
        except (OSError, json.JSONDecodeError):
            pass

    report = {
        "target": "BitLife 3.25.3 / com.candywriter.bitlife",
        "generatedBy": "tools/parity_report.py",
        "manifest": coverage.get("manifestObjects", asset.get("manifestObjects", 0)),
        "webCsvFiles": count_files(data_dir, ".csv"),
        "webAssetFiles": count_files(asset_dir),
        "manifestAudioClipObjects": manifest_audio_clips,
        "webAudioWavFiles": count_files(audio_dir, ".wav"),
        "audioIndexFiles": count_files(audio_dir, ".json"),
        "knownAudioDecodeFailures": 17,
        "knownFontTextureFailures": 3,
        "failedAssetCount": len(find_failed_assets()),
        "effectDomainCount": effect_domains,
        "funResolution": fun,
        "sourceHashes": hashes,
    }
    output = OUT / "port_parity_report.json"
    output.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

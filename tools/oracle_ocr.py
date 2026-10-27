"""Extract OCR detections from Unity screenshots for versioned oracle fixtures."""
from __future__ import annotations

import argparse
import hashlib
import json
from datetime import datetime, timezone
from pathlib import Path

from rapidocr_onnxruntime import RapidOCR

ROOT = Path(__file__).resolve().parents[1]


def main() -> None:
    parser = argparse.ArgumentParser()
    parser.add_argument("images", nargs="+", type=Path)
    parser.add_argument("--output", required=True, type=Path)
    args = parser.parse_args()
    ocr = RapidOCR()
    frames = []
    for supplied in args.images:
        path = supplied if supplied.is_absolute() else ROOT / supplied
        data = path.read_bytes()
        detections, _ = ocr(str(path))
        items = []
        for item in detections or []:
            text, confidence, box = item[1], float(item[2]), item[0]
            items.append({
                "text": text,
                "confidence": round(confidence, 6),
                "box": [[round(float(point[0]), 2), round(float(point[1]), 2)] for point in box],
            })
        frames.append({
            "file": str(path.relative_to(ROOT)).replace("\\", "/"),
            "sha256": hashlib.sha256(data).hexdigest(),
            "bytes": len(data),
            "detections": items,
        })
    report = {
        "generatedAt": datetime.now(timezone.utc).isoformat(),
        "engine": "rapidocr_onnxruntime",
        "frames": frames,
    }
    output = args.output if args.output.is_absolute() else ROOT / args.output
    output.parent.mkdir(parents=True, exist_ok=True)
    output.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

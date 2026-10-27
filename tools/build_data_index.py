"""Build a typed inventory for the decrypted CSV corpus.

The output is metadata only: source CSV bytes remain untouched. Files with invalid
UTF-8 are marked so the web loader cannot silently treat replacement characters as
content.
"""
from __future__ import annotations

import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CSV_DIR = ROOT / "out" / "decrypted"
WEB_DIR = ROOT / "web" / "public" / "data"
OUT_DIR = ROOT / "out"

FAMILY_RULES = [
    ("scenario", re.compile(r"scenario|scenarios|dumb", re.I)),
    ("career", re.compile(r"career|job|occupation|promotion", re.I)),
    ("health", re.compile(r"health|disease|illness|medical|doctor", re.I)),
    ("relationship", re.compile(r"relationship|lover|spouse|friend|family|dating", re.I)),
    ("education", re.compile(r"school|college|university|education|degree", re.I)),
    ("crime", re.compile(r"crime|arrest|prison|court|mafia|gang", re.I)),
    ("finance", re.compile(r"money|finance|tax|bank|loan|salary|property|vehicle", re.I)),
    ("country", re.compile(r"country|city|name|nationality|birth", re.I)),
    ("activity", re.compile(r"activity|hobby|sport|travel|pastime|diet", re.I)),
]


def family_for(name: str, headers: list[str]) -> str:
    haystack = f"{name} {' '.join(headers)}"
    for family, pattern in FAMILY_RULES:
        if pattern.search(haystack):
            return family
    return "other"


def decode(raw: bytes) -> tuple[str | None, str]:
    for encoding in ("utf-8-sig", "utf-8", "cp1252"):
        try:
            return raw.decode(encoding), encoding
        except UnicodeDecodeError:
            continue
    return None, "binary/invalid"


def inspect(path: Path) -> dict:
    raw = path.read_bytes()
    text, encoding = decode(raw)
    result = {
        "name": path.stem,
        "file": path.name,
        "bytes": len(raw),
        "encoding": encoding,
        "validUtf8": encoding in {"utf-8-sig", "utf-8"},
        "family": "other",
        "columns": [],
        "rows": 0,
        "scenarioLike": False,
    }
    if text is None:
        return result
    try:
        records = list(csv.reader(text.splitlines()))
    except csv.Error as exc:
        result["parseError"] = str(exc)
        return result
    if records:
        result["columns"] = records[0]
        result["rows"] = max(0, len(records) - 1)
        result["family"] = family_for(path.stem, records[0])
        result["scenarioLike"] = any(
            column.lower() in {"scenario", "body", "choice 1", "yes choice"}
            for column in records[0]
        )
    return result


def main() -> None:
    entries = [inspect(path) for path in sorted(CSV_DIR.glob("*.csv"))]
    summary = {
        "csvCount": len(entries),
        "rows": sum(item["rows"] for item in entries),
        "invalidUtf8": sum(not item["validUtf8"] for item in entries),
        "families": {},
        "scenarioTables": sum(item["scenarioLike"] for item in entries),
    }
    for item in entries:
        family = item["family"]
        summary["families"][family] = summary["families"].get(family, 0) + 1

    output = {"generatedFrom": str(CSV_DIR), "summary": summary, "tables": entries}
    OUT_DIR.mkdir(exist_ok=True)
    (OUT_DIR / "data_index.json").write_text(json.dumps(output, indent=2) + "\n", encoding="utf-8")

    WEB_DIR.mkdir(parents=True, exist_ok=True)
    web_index = {
        "generatedFrom": "out/data_index.json",
        "summary": summary,
        "tables": {
            item["name"]: {
                "family": item["family"],
                "columns": item["columns"],
                "rows": item["rows"],
                "encoding": item["encoding"],
                "validUtf8": item["validUtf8"],
            }
            for item in entries
        },
    }
    (WEB_DIR / "_typed-index.json").write_text(
        json.dumps(web_index, indent=2) + "\n", encoding="utf-8"
    )
    print(json.dumps(summary, indent=2))


if __name__ == "__main__":
    main()

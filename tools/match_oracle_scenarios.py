"""Match visible oracle scenario text against the extracted CSV corpus.

This is a static/content matcher. It does not claim RNG or internal-ID parity.
"""
from __future__ import annotations

import csv
import json
import re
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
CORPUS = ROOT / "out" / "decrypted"
OUT = ROOT / "out" / "oracle" / "bitlife-3.26.0-baseline" / "scenario_matches.json"

VISIBLE = [
    {
        "oracleStep": "age-up-to-1",
        "title": "Physical Development",
        "bodyFragment": "You're starting to discover what your little body can do",
        "prompt": "What will you do?",
        "choices": [
            "Crawl across the floor",
            "Grab <parent-possessive> hair",
            "Hold a ball",
            "Stand up in the crib",
            "Surprise me!",
        ],
    },
    {
        "oracleStep": "age-up-to-2",
        "title": "Vaccination",
        "bodyFragment": "Your mother is taking you to the doctor's office",
        "prompt": "How will you behave?",
        "choices": [
            "Try to stay calm",
            "Throw a tantrum",
            "Bite her",
            "Surprise me!",
        ],
    },
]


def norm(value: str) -> str:
    value = value.lower().replace("<parent-possessive>", "")
    return re.sub(r"[^a-z0-9]+", "", value)


def row_text(row: list[str]) -> str:
    return " | ".join(row)


def score(item: dict[str, object], row: list[str]) -> dict[str, object]:
    text = row_text(row)
    normalized = norm(text)
    title = str(item["title"])
    body = str(item["bodyFragment"])
    prompt = str(item["prompt"])
    choices = [str(x) for x in item["choices"]]
    signals = {
        "title": norm(title) in normalized,
        "bodyFragment": norm(body) in normalized,
        "prompt": norm(prompt) in normalized,
        "choiceHits": sum(1 for choice in choices if norm(choice) in normalized),
    }
    total = int(signals["title"]) * 4 + int(signals["bodyFragment"]) * 4 + int(signals["prompt"]) * 2 + int(signals["choiceHits"])
    return {"score": total, "signals": signals}


def main() -> None:
    matches: list[dict[str, object]] = []
    files_scanned = 0
    for path in sorted(CORPUS.glob("*.csv")):
        try:
            with path.open("r", encoding="utf-8-sig", errors="replace", newline="") as handle:
                rows = list(csv.reader(handle))
        except OSError:
            continue
        files_scanned += 1
        if not rows:
            continue
        for item in VISIBLE:
            best: dict[str, object] | None = None
            for index, row in enumerate(rows[1:], start=2):
                details = score(item, row)
                if best is None or int(details["score"]) > int(best["score"]):
                    best = {
                        "file": str(path.relative_to(ROOT)).replace("\\", "/"),
                        "row": index,
                        "score": details["score"],
                        "signals": details["signals"],
                        "rowPreview": row[:16],
                    }
            if best and int(best["score"]) >= 8:
                matches.append({"oracle": item, "corpusMatch": best})
    report = {
        "oracleVersion": "3.26.0",
        "corpusVersion": "3.25.3",
        "filesScanned": files_scanned,
        "visibleScenarios": VISIBLE,
        "matches": matches,
        "interpretation": [
            "A match proves visible content exists in the extracted corpus, not runtime selection/RNG parity.",
            "No match is a version/content delta candidate and requires manual review.",
        ],
    }
    OUT.write_text(json.dumps(report, indent=2, ensure_ascii=False) + "\n", encoding="utf-8")
    print(json.dumps(report, indent=2, ensure_ascii=False))


if __name__ == "__main__":
    main()

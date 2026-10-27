"""Create a semantic index for extracted Unity sprites/textures/audio/fonts."""
from __future__ import annotations

import json
import re
from collections import Counter, defaultdict
from pathlib import Path

ROOT = Path(__file__).resolve().parents[1]
DATAPACK = ROOT / "out" / "datapack"
WEB_ASSETS = ROOT / "web" / "public" / "assets"
MANIFEST = DATAPACK / "manifest.json"

TAG_RULES = [
    ("toolbar", re.compile(r"toolbar|agepartial|infantbutton|deathbutton", re.I)),
    ("button", re.compile(r"button|choice|dismiss|backbutton|buttonicon", re.I)),
    ("navbar", re.compile(r"navbar|nav|tab", re.I)),
    ("stat", re.compile(r"stats|health|happiness|smarts|looks|fame|respect", re.I)),
    ("emoji", re.compile(r"emoji", re.I)),
    ("logo", re.compile(r"logo|brand|bitizen", re.I)),
    ("background", re.compile(r"background|bg|backdrop", re.I)),
    ("season", re.compile(r"season|halloween|christmas|holiday", re.I)),
    ("font", re.compile(r"font|atlas", re.I)),
]


def tags(name: str, kind: str) -> list[str]:
    text = f"{name} {kind}"
    result = [tag for tag, pattern in TAG_RULES if pattern.search(text)]
    return result or ["other"]


def main() -> None:
    manifest = json.loads(MANIFEST.read_text(encoding="utf-8"))
    entries: list[dict] = []
    by_tag: dict[str, list[str]] = defaultdict(list)
    counts: Counter[str] = Counter()
    for item in manifest:
        name = item.get("name") or ""
        kind = item.get("type") or ""
        file_name = item.get("file")
        if not file_name:
            continue
        item_tags = tags(name, kind)
        entry = {
            "type": kind,
            "pathId": item.get("path_id"),
            "name": name,
            "file": file_name.replace("\\", "/"),
            "tags": item_tags,
        }
        entries.append(entry)
        for tag in item_tags:
            by_tag[tag].append(file_name.replace("\\", "/"))
        counts[kind] += 1

    output = {
        "target": "BitLife 3.25.3 / com.candywriter.bitlife",
        "manifestObjects": len(manifest),
        "indexedEntries": len(entries),
        "byType": dict(counts),
        "byTagCounts": {tag: len(files) for tag, files in sorted(by_tag.items())},
        "entries": entries,
    }
    (ROOT / "out" / "asset_index.json").write_text(
        json.dumps(output, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    WEB_ASSETS.mkdir(parents=True, exist_ok=True)
    (WEB_ASSETS / "_index.json").write_text(
        json.dumps({
            "target": output["target"],
            "manifestObjects": output["manifestObjects"],
            "byType": output["byType"],
            "byTagCounts": output["byTagCounts"],
        }, ensure_ascii=False, indent=2) + "\n", encoding="utf-8"
    )
    print(json.dumps({
        "manifestObjects": len(manifest),
        "indexedEntries": len(entries),
        "byType": dict(counts),
        "byTagCounts": {tag: len(files) for tag, files in sorted(by_tag.items())},
    }, indent=2))


if __name__ == "__main__":
    main()

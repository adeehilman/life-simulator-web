"""Build a scenario catalog out of the il2cpp metadata.

The MonoScript table in global-metadata.dat carries the original C# source path
for every scenario class, e.g.
  \\Assets\\Game\\Scenario\\Actual Scenarios\\Mind & Body\\ScenarioGym.cs

That gives an exact scenario inventory grouped by the game's own categories,
which is the authoritative list; the class-name token heap adds scenario classes
that were shipped without a path record.
"""
import json
import re
import struct
from collections import Counter, defaultdict

META = 'work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat'
HEAP_START = 0x219458          # identifier heap (nul separated tokens)
PATH_RE = re.compile(rb'\\Assets\\Game\\Scenario\\Actual Scenarios\\([^\\\x00]+)\\([A-Za-z0-9_]+)\.cs')
CLASS_RE = re.compile(rb'^Scenario[A-Z][A-Za-z0-9_]{2,60}$')


def main():
    data = open(META, 'rb').read()
    heap = data[HEAP_START:]

    by_category = defaultdict(set)
    for match in PATH_RE.finditer(data):
        category = match.group(1).decode('utf-8', 'replace')
        name = match.group(2).decode('ascii', 'replace')
        by_category[category].add(name)

    known = {n for names in by_category.values() for n in names}
    orphans = set()
    for token in heap.split(b'\x00'):
        token = token.lstrip(b'\x01\x02\x03\x04\x05\x06\x07\x08\x0b\x12\x13\x14\x15\x16\x17\x18\x19\x1a\x1b\x1c\x1d\x1e\x1f')
        if CLASS_RE.match(token):
            name = token.decode('ascii')
            if name not in known:
                orphans.add(name)

    catalog = {
        'scenarios_by_category': {k: sorted(v) for k, v in sorted(by_category.items())},
        'uncategorized': sorted(orphans),
    }
    total = sum(len(v) for v in by_category.values())
    json.dump(catalog, open('out/scenario_catalog.json', 'w'), indent=1)

    print('categories', len(by_category))
    print('categorized scenarios', total)
    print('uncategorized scenario classes', len(orphans))
    for cat, names in Counter({k: len(v) for k, v in by_category.items()}).most_common(20):
        print(f'  {cat}: {names}')


if __name__ == '__main__':
    main()

"""Parse dump.cs class/struct/enum definitions into a JSON schema + TypeScript
interfaces. Extracts field name/type and enum members for the types on the
command line (default: Life Scenario StatType SimHero SimWorld).

Output:
    out/schema/types.json        - raw parsed data
    out/schema/types.ts          - TypeScript interfaces/enums

Usage: python tools/dump_schema.py [TypeName ...]
"""
import json
import os
import re

ROOT = os.path.dirname(os.path.dirname(os.path.abspath(__file__)))
DUMP = os.path.join(ROOT, 'out', 'il2cpp', 'dump.cs')
OUT_DIR = os.path.join(ROOT, 'out', 'schema')

DEFAULT_TYPES = ['Life', 'Scenario', 'StatType', 'SimHero', 'SimWorld',
                 'SimPerson', 'SimDeath']

with open(DUMP, encoding='utf-8') as fh:
    text = fh.read()

blocks = re.split(r'\n(?=public |internal |private sealed class )', text)
TYPES = {}
for b in blocks:
    m = re.match(r'(?:(?:public|internal|private)\s+)*(?:sealed\s+)?'
                 r'(class|enum|struct|interface)\s+([A-Za-z0-9_]+)', b)
    if m:
        TYPES[m.group(2)] = {'kind': m.group(1), 'body': b}


def to_ts_type(cs):
    cs = cs.strip()
    if cs in ('int', 'long', 'short', 'byte'):
        return str('number')
    if cs in ('float', 'double'):
        return str('number')
    if cs == 'bool':
        return str('boolean')
    if cs == 'string':
        return str('string')
    m = re.match(r'(?:List|IList|HashSet)<(.+)>$', cs)
    if m:
        inner = m.group(1).split(',')[0].strip()
        return to_ts_type(inner) + '[]'
    mdict = re.match(r'Dictionary<(.+?),\s*(.+)>$', cs)
    if mdict:
        k = to_ts_type(mdict.group(1))
        v = to_ts_type(mdict.group(2))
        return '{ [key: %s]: %s }' % (k, v)
    # reference type -> named interface
    clean = re.sub(r'[A-Za-z0-9_.]+\.', '', cs)
    clean = re.sub(r'[<>\[\], ]+$', '', clean).strip()
    # drop generic args
    base = re.split(r'[<\[(]', clean)[0].strip()
    if base and base[0].isupper():
        return base
    return str('any')


def extract_fields(class_body):
    m = re.search(r'// Fields\n(.*?)(?:// Methods|$)', class_body, re.S)
    if not m:
        return []
    fields = []
    for line in m.group(1).splitlines():
        line = line.strip()
        if not line or line.startswith('[') or line.startswith('//') \
           or 'CompilerGenerated' in line:
            continue
        fm = re.match(r'(?:public\s+|private\s+)*(?:static\s+)?'
                      r'(?P<type>[A-Za-z0-9_.<>\[\], ]+)'
                      r'\s+(?P<name>(?:<[A-Za-z0-9_]+>)?[A-Za-z0-9_]+);',
                      line)
        if not fm:
            continue
        ftype = fm.group('type').strip()
        fname = re.sub(r'^<(.*)>$', r'\1', fm.group('name'))
        fields.append({'name': fname, 'cs_type': ftype,
                       'ts_type': to_ts_type(ftype)})
    return fields


def extract_enum(class_body):
    m = re.search(r'// Fields\n(.*?)$', class_body, re.S)
    if not m:
        return {}
    members = {}
    for line in m.group(1).splitlines():
        line = line.strip()
        em = re.match(r'public\s+const\s+\w+\s+([A-Za-z0-9_]+)\s*=\s*(\d+)',
                      line)
        if em:
            members[em.group(1)] = int(em.group(2))
    return members


def lines_out(fields, ts_lines, tname):
    ts_lines.append('export interface %s {' % tname)
    for f in fields:
        ts_lines.append('  %s: %s;' % (f['name'], f['ts_type']))
    ts_lines.append('}')


def en_lines(members, ts_lines, tname):
    ts_lines.append('export enum %s {' % tname)
    for name, val in members.items():
        ts_lines.append('  %s = %d,' % (name, val))
    ts_lines.append('}')


def main():
    import sys
    types = sys.argv[1:] or DEFAULT_TYPES
    os.makedirs(OUT_DIR, exist_ok=True)
    result = {}
    ts_lines = []
    for tname in types:
        blk = TYPES.get(tname)
        if not blk:
            print('WARN: type not found:', tname, file=sys.stderr)
            continue
        kind = blk['kind']
        if kind in ('class', 'struct'):
            fields = extract_fields(blk['body'])
            result[tname] = {'kind': kind, 'fields': fields}
            lines_out(fields, ts_lines, tname)
        elif kind == 'enum':
            members = extract_enum(blk['body'])
            result[tname] = {'kind': 'enum', 'members': members}
            en_lines(members, ts_lines, tname)

    with open(os.path.join(OUT_DIR, 'types.json'), 'w') as fh:
        json.dump(result, fh, indent=1)
    with open(os.path.join(OUT_DIR, 'types.ts'), 'w') as fh:
        fh.write('\n'.join(ts_lines) + '\n')
    print('wrote %d types -> %s' % (len(result), OUT_DIR))


if __name__ == '__main__':
    main()


"""Generate a TypeScript data model from Il2CppDumper's dump.cs.

dump.cs is a *map*: every type with field offsets and method RVAs, no bodies.
This turns that map into typed interfaces so the port has the game's real state
schema instead of an invented one.

Output: web/src/model/<namespace>.ts plus web/src/model/index.ts and
web/src/model/enums.ts. Field offsets stay as trailing comments so a field can
be traced back to dump.cs when a decompiled method needs it.

Usage:
    python tools/gen_model.py [--only Life,Scenario,SimHero] [--all]

Without --all only the gameplay namespaces (Assembly-CSharp) are emitted;
engine and SDK namespaces are skipped.
"""
import os
import re
import sys

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')
DUMP = os.path.join(ROOT, 'out', 'il2cpp', 'dump.cs')
OUT = os.path.join(ROOT, 'web', 'src', 'model')

SKIP_NAMESPACES = (
    'System', 'UnityEngine', 'Unity.', 'Microsoft', 'Mono', 'Newtonsoft',
    'Amazon', 'AWSSDK', 'Firebase', 'Google', 'VoxelBusters', 'Didomi',
    'AppsFlyer', 'Embrace', 'Gadsme', 'LevelPlay', 'IronSource', 'zxing',
    'DynamicExpresso', 'DOTween', 'OPS.', 'CandyBusiness.AgeApi',
)

HEADER_RE = re.compile(r'^(?:\[[^\]]*\]\s*)*((?:public|private|internal|protected)\s+)*'
                       r'(?:sealed\s+|abstract\s+|static\s+|readonly\s+|partial\s+)*'
                       r'(class|struct|enum|interface)\s+([A-Za-z0-9_.<>`]+)')
NS_RE = re.compile(r'^// Namespace: (.*)$')
FIELD_RE = re.compile(r'^\t(?:\[[^\]]*\]\s*)*((?:public|private|internal|protected)\s+)*'
                      r'(?:static\s+|readonly\s+|const\s+)*'
                      r'([A-Za-z0-9_.<>\[\],\s]+?)\s+([A-Za-z0-9_<>`]+);\s*//\s*(0x[0-9A-Fa-f]+)')
ENUM_RE = re.compile(r'^\tpublic const ([A-Za-z0-9_.]+) ([A-Za-z0-9_]+) = (-?\d+);')

PRIMITIVES = {
    'int': 'number', 'uint': 'number', 'long': 'number', 'ulong': 'number',
    'short': 'number', 'ushort': 'number', 'byte': 'number', 'sbyte': 'number',
    'float': 'number', 'double': 'number', 'decimal': 'number',
    'bool': 'boolean', 'char': 'string', 'string': 'string', 'object': 'unknown',
    'void': 'void', 'IntPtr': 'number', 'UIntPtr': 'number',
}

UNITY = {
    'Vector2': 'Vec2', 'Vector3': 'Vec3', 'Vector4': 'Vec4', 'Vector2Int': 'Vec2',
    'Vector3Int': 'Vec3', 'Quaternion': 'Quat', 'Color': 'Rgba', 'Color32': 'Rgba',
    'Rect': 'Rect', 'Bounds': 'Bounds', 'Sprite': 'AssetRef', 'Texture2D': 'AssetRef',
    'AudioClip': 'AssetRef', 'Font': 'AssetRef', 'Material': 'AssetRef',
    'GameObject': 'AssetRef', 'Transform': 'AssetRef', 'MonoBehaviour': 'AssetRef',
    'UnityEvent': 'EventHook', 'AnimationCurve': 'Curve', 'LayerMask': 'number',
}


def ident(name):
    """Make a C# identifier safe for TypeScript and Windows paths."""
    return re.sub(r'[^A-Za-z0-9_]', '_', name.replace('.', '_'))


def ts_type(cs):
    """Map a C# type expression onto TypeScript."""
    cs = cs.strip()
    if cs in PRIMITIVES:
        return PRIMITIVES[cs]
    if cs in UNITY:
        return UNITY[cs]
    m = re.match(r'^(?:System\.Collections\.Generic\.)?(List|HashSet|Queue|Stack|IList|ICollection)<(.+)>$', cs)
    if m:
        return f'{ts_type(m.group(2))}[]'
    m = re.match(r'^(?:System\.Collections\.Generic\.)?(?:Dictionary|SortedDictionary|IDictionary)<(.+),\s*(.+)>$', cs)
    if m:
        return f'Record<string, {ts_type(m.group(2))}>'
    if cs in ('ArrayList', 'Array', 'Hashtable'):
        return 'unknown[]'
    if cs.endswith('[]'):
        return f'{ts_type(cs[:-2])}[]'
    if cs.endswith('?'):
        return f'{ts_type(cs[:-1])} | null'
    if '<' in cs:
        base = cs.split('<')[0].split('.')[-1]
        return base
    return cs.split('.')[-1]


def parse():
    """Yield (kind, namespace, name, body_lines) for every type in dump.cs."""
    namespace = ''
    kind = name = None
    body = []
    with open(DUMP, encoding='utf-8', errors='replace') as fh:
        for line in fh:
            ns = NS_RE.match(line)
            if ns:
                namespace = ns.group(1).strip()
                continue
            head = HEADER_RE.match(line)
            if head and not line.startswith('\t'):
                if kind:
                    yield kind, namespace, name, body
                kind, name, body = head.group(2), head.group(3), []
                continue
            if kind:
                if line.startswith('}'):
                    yield kind, namespace, name, body
                    kind = name = body = None
                else:
                    body.append(line)
    if kind:
        yield kind, namespace, name, body


def wanted(namespace, only):
    if only:
        return True
    return not namespace.startswith(SKIP_NAMESPACES)


def main():
    only = None
    if '--only' in sys.argv:
        only = set(sys.argv[sys.argv.index('--only') + 1].split(','))
    os.makedirs(OUT, exist_ok=True)

    files = {}
    enums = {}
    for kind, namespace, name, body in parse():
        if only:
            if name.split('.')[-1] not in only:
                continue
        elif not wanted(namespace, only):
            continue
        if kind == 'enum':
            members = []
            for line in body:
                m = ENUM_RE.match(line)
                if m:
                    members.append((m.group(2), int(m.group(3))))
            if members:
                enums[name.replace('.', '_')] = members
            continue
        if kind == 'interface':
            continue
        if name.startswith('<'):
            continue
        fields = []
        for line in body:
            m = FIELD_RE.match(line)
            if not m:
                continue
            ftype, fname, off = m.group(2), m.group(3), m.group(4)
            if fname.startswith('<>') or fname == 'value__':
                continue
            fields.append((fname, ts_type(ftype), off, ftype.strip()))
        if not fields:
            continue
        path_name = (namespace.replace('.', '_') or 'global') + '.ts'
        files.setdefault(path_name, []).append((ident(name), fields))

    for path_name, types in files.items():
        chunks = ["// Generated by tools/gen_model.py from out/il2cpp/dump.cs.",
                  "// Offsets are IL2CPP field offsets; keep them when tracing a",
                  "// decompiled method back to the schema.", ""]
        for name, fields in types:
            chunks.append(f'export interface {name} {{')
            for fld, ftype, off, raw in fields:
                chunks.append(f'  /** {off} — {raw} */')
                chunks.append(f'  {ident(fld)}?: {ftype};')
            chunks.append('}')
            chunks.append('')
        with open(os.path.join(OUT, path_name), 'w') as fh:
            fh.write('\n'.join(chunks))

    if enums:
        lines = ['// Generated by tools/gen_model.py from out/il2cpp/dump.cs.', '']
        for name, members in enums.items():
            lines.append(f'export enum {name} {{')
            for mname, value in members:
                lines.append(f'  {mname} = {value},')
            lines.append('}')
            lines.append('')
        with open(os.path.join(OUT, 'enums.ts'), 'w') as fh:
            fh.write('\n'.join(lines))

    index = ['// Generated by tools/gen_model.py.', '']
    for path_name in sorted(files):
        index.append(f"export * from './{path_name[:-3]}';")
    index.append("export * from './enums';")
    with open(os.path.join(OUT, 'index.ts'), 'w') as fh:
        fh.write('\n'.join(index) + '\n')

    print(f'{len(files)} namespace files, {sum(len(v) for v in files.values())} types, '
          f'{len(enums)} enums -> {OUT}')


if __name__ == '__main__':
    main()

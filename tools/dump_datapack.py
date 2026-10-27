"""Full asset dump of the Unity asset pack (datapack.unity3d, 37,478 objects).

Every serialized object in the pack is exported:

    Texture2D  -> PNG
    Sprite     -> PNG (via its own texture rect, plus a flat sprite sheet crop)
    AudioClip  -> WAV
    TextAsset  -> raw text (non `-enc` only; `-enc` is handled by decrypt_all.py)
    Font       -> TTF/OTF
    Mesh       -> OBJ
    everything else -> raw bytes under raw/<Type>/

A manifest (out/datapack/manifest.json) records type, path id, name and byte
size for every object so coverage can be checked against the pack total.

Usage:
    python tools/dump_datapack.py [--skip-types Texture2D,Sprite]

Needs UnityPy + Pillow on the FlyEnv interpreter:
    "C:/Program Files/FlyEnv-Data/app/python-3.14.6/python.exe" tools/dump_datapack.py
"""
import io
import json
import os
import re
import sys
import zipfile

import UnityPy
from PIL import Image

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')
PACK = os.path.join(ROOT, 'work', 'abi', 'UnityDataAssetPack.apk')
DATA_ENTRY = 'assets/bin/Data/datapack.unity3d'
OUT = os.path.join(ROOT, 'out', 'datapack')
MANIFEST = os.path.join(OUT, 'manifest.json')

SAFE = re.compile(r'[^A-Za-z0-9._\- ()]+')
BUCKETS = {
    'Texture2D': 'textures',
    'Sprite': 'sprites',
    'AudioClip': 'audio',
    'TextAsset': 'text',
    'Font': 'fonts',
    'Mesh': 'meshes',
    'Shader': 'shaders',
    'Material': 'materials',
    'AnimationClip': 'animations',
    'MonoBehaviour': 'scripts',
}


def safe(name, fallback):
    cleaned = SAFE.sub('_', name or '').strip()[:110]
    return cleaned or fallback


def main():
    skip = set()
    if '--skip-types' in sys.argv:
        skip = set(sys.argv[sys.argv.index('--skip-types') + 1].split(','))

    for bucket in set(BUCKETS.values()) | {'raw'}:
        os.makedirs(os.path.join(OUT, bucket), exist_ok=True)

    with zipfile.ZipFile(PACK) as z:
        env = UnityPy.load(z.read(DATA_ENTRY))

    rows = []
    written = 0
    failed = 0
    for obj in env.objects:
        kind = obj.type.name
        entry = {'type': kind, 'path_id': obj.path_id, 'bytes': obj.byte_size}
        rows.append(entry)
        if kind in skip:
            continue
        bucket = BUCKETS.get(kind)
        try:
            if kind == 'Texture2D':
                data = obj.read()
                entry['name'] = data.m_Name
                img = data.image
                path = os.path.join(OUT, 'textures',
                                    f'{obj.path_id}_{safe(data.m_Name, "tex")}.png')
                os.makedirs(os.path.dirname(path), exist_ok=True)
                img.save(path)
                entry['file'] = os.path.relpath(path, OUT)
                written += 1
            elif kind == 'Sprite':
                data = obj.read()
                entry['name'] = data.m_Name
                img = data.image
                path = os.path.join(OUT, 'sprites',
                                    f'{obj.path_id}_{safe(data.m_Name, "spr")}.png')
                img.save(path)
                entry['file'] = os.path.relpath(path, OUT)
                written += 1
            elif kind == 'AudioClip':
                data = obj.read()
                entry['name'] = data.m_Name
                for clip_name, samples in data.samples.items():
                    path = os.path.join(OUT, 'audio', f'{obj.path_id}_{safe(clip_name, "clip")}.wav')
                    with open(path, 'wb') as fh:
                        fh.write(samples)
                    entry['file'] = os.path.relpath(path, OUT)
                    break
                written += 1
            elif kind == 'TextAsset':
                data = obj.read()
                entry['name'] = data.m_Name
                if data.m_Name.endswith('-enc'):
                    entry['encrypted'] = True
                    continue
                script = data.m_Script
                if isinstance(script, str):
                    script = script.encode('utf-8', 'surrogateescape')
                path = os.path.join(OUT, 'text', f'{safe(data.m_Name, str(obj.path_id))}.txt')
                with open(path, 'wb') as fh:
                    fh.write(script)
                entry['file'] = os.path.relpath(path, OUT)
                written += 1
            elif kind == 'Font':
                data = obj.read()
                entry['name'] = data.m_Name
                path = os.path.join(OUT, 'fonts', f'{obj.path_id}_{safe(data.m_Name, "font")}.ttf')
                with open(path, 'wb') as fh:
                    fh.write(bytes(data.m_FontData))
                entry['file'] = os.path.relpath(path, OUT)
                written += 1
            elif kind == 'Mesh':
                data = obj.read()
                entry['name'] = data.m_Name
                for mesh_name, obj_text in data.export().items():
                    path = os.path.join(OUT, 'meshes', f'{obj.path_id}_{safe(mesh_name, "mesh")}.obj')
                    with open(path, 'w') as fh:
                        fh.write(obj_text)
                    entry['file'] = os.path.relpath(path, OUT)
                    break
                written += 1
            else:
                name = None
                try:
                    data = obj.read()
                    name = getattr(data, 'm_Name', None) or getattr(data, 'name', None)
                except Exception:                      # noqa: BLE001
                    pass                               # no typetree for script types
                entry['name'] = name
                raw = obj.get_raw_data()
                path = os.path.join(OUT, 'raw', kind,
                                    f'{obj.path_id}_{safe(name, "obj")}.bin')
                os.makedirs(os.path.dirname(path), exist_ok=True)
                with open(path, 'wb') as fh:
                    fh.write(raw)
                entry['file'] = os.path.relpath(path, OUT)
                written += 1
        except Exception as exc:                       # noqa: BLE001
            failed += 1
            entry['error'] = f'{type(exc).__name__}: {exc}'[:200]

    with open(MANIFEST, 'w') as fh:
        json.dump(rows, fh, indent=1)

    counts = {}
    for row in rows:
        counts[row['type']] = counts.get(row['type'], 0) + 1
    print(json.dumps({'objects': len(rows), 'files': written, 'failed': failed,
                      'by_type': counts}, indent=1, sort_keys=True))


if __name__ == '__main__':
    main()

"""Dump every asset object from the APK's Unity serialized files.

Writes a manifest JSON (type, path_id, name, size) and extracts
textures/sprites as PNG, audio clips as WAV and text assets as .txt.
"""
import json
import os
import UnityPy

SRC = [
    'work/apk/assets/bin/Data/data.unity3d',
    'work/apk/assets/bin/Data/sharedassets0.resource',
]
OUT = 'out/assets'
MANIFEST = 'out/asset_manifest.json'


def safe(name):
    keep = '-_. ()[]'
    return ''.join(c if c.isalnum() or c in keep else '_' for c in name)[:110]


def main():
    os.makedirs(OUT, exist_ok=True)
    env = UnityPy.load(*SRC)
    rows = []
    for obj in env.objects:
        kind = obj.type.name
        entry = {'type': kind, 'path_id': obj.path_id, 'bytes': obj.byte_size}
        rows.append(entry)

        if kind == 'MonoScript':
            try:
                data = obj.read()
                entry['class'] = data.m_ClassName
                entry['namespace'] = data.m_Namespace
                entry['assembly'] = data.m_AssemblyName
            except Exception as exc:
                entry['read_error'] = type(exc).__name__
            continue

        if kind in ('GameObject', 'Texture2D', 'AudioClip', 'Sprite',
                    'TextAsset', 'Font', 'VideoClip', 'Material', 'AnimationClip'):
            try:
                data = obj.read()
            except Exception as exc:
                entry['read_error'] = type(exc).__name__
                continue
            name = safe(getattr(data, 'm_Name', None) or kind)
            entry['name'] = getattr(data, 'm_Name', None)
            try:
                if kind in ('Texture2D', 'Sprite'):
                    data.image.save(os.path.join(OUT, f'{obj.path_id}_{name}.png'))
                elif kind == 'AudioClip':
                    for fname, payload in data.samples.items():
                        with open(os.path.join(OUT, f'{obj.path_id}_{safe(fname)}'), 'wb') as fh:
                            fh.write(payload)
                elif kind == 'TextAsset':
                    blob = data.m_Script
                    raw = blob.encode('utf-8', 'surrogateescape') if isinstance(blob, str) else bytes(blob)
                    with open(os.path.join(OUT, f'{obj.path_id}_{name}.txt'), 'wb') as fh:
                        fh.write(raw)
            except Exception as exc:
                entry['export_error'] = f'{type(exc).__name__}: {exc}'[:120]

    json.dump(rows, open(MANIFEST, 'w'), indent=1)
    exported = sum(1 for r in rows if 'export_error' not in r and r['type'] in
                   ('Texture2D', 'Sprite', 'AudioClip', 'TextAsset'))
    print('objects', len(rows), 'files', len(os.listdir(OUT)), 'exported', exported)


if __name__ == '__main__':
    main()

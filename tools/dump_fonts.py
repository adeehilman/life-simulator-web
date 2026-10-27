"""Export Font and VideoClip objects from the bundle.

Fonts matter for a web rebuild (the UI leans on Molot/Overpass); the video clips are
mostly ad creatives. Fonts are written as their embedded TTF/OTF payload.
"""
import json
import os
import UnityPy

SRC = ['work/apk/assets/bin/Data/data.unity3d',
       'work/apk/assets/bin/Data/sharedassets0.resource']
OUT = 'out/fonts'


def safe(name):
    return ''.join(c if c.isalnum() or c in '-_.' else '_' for c in name)[:80]


def main():
    os.makedirs(OUT, exist_ok=True)
    env = UnityPy.load(*SRC)
    rows = []
    for obj in env.objects:
        if obj.type.name != 'Font':
            continue
        entry = {'path_id': obj.path_id}
        try:
            font = obj.read()
            entry['name'] = font.m_Name
            data = font.m_FontData
            blob = bytes(data)
            if blob[:4] in (b'\x00\x01\x00\x00', b'OTTO', b'true'):
                dest = os.path.join(OUT, safe(font.m_Name) + '.ttf')
                open(dest, 'wb').write(blob)
                entry['file'] = os.path.basename(dest)
                entry['bytes'] = len(blob)
        except Exception as exc:
            entry['error'] = f'{type(exc).__name__}: {exc}'[:90]
        rows.append(entry)
    json.dump(rows, open('out/font_manifest.json', 'w'), indent=1)
    print('font objek', len(rows), 'tertulis', len(os.listdir(OUT)))


if __name__ == '__main__':
    main()

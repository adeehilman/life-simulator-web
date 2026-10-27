"""Export Unity AudioClip objects to playable WAV plus a manifest.

Loads the serialized bundle together with its .resource stream, because sample
payloads live in the resource file rather than the bundle itself.
"""
import json
import os
import UnityPy

SRC = [
    'work/apk/assets/bin/Data/data.unity3d',
    'work/apk/assets/bin/Data/sharedassets0.resource',
]
OUT = 'out/audio'


def safe(name):
    return ''.join(c if c.isalnum() or c in '-_. ' else '_' for c in name)[:100]


def main():
    os.makedirs(OUT, exist_ok=True)
    env = UnityPy.load(*SRC)
    manifest = []
    for obj in env.objects:
        if obj.type.name != 'AudioClip':
            continue
        try:
            clip = obj.read()
            samples = dict(clip.samples)
        except Exception as exc:
            manifest.append({'path_id': obj.path_id, 'error': f'{type(exc).__name__}: {exc}'[:100]})
            continue
        entry = {
            'path_id': obj.path_id,
            'name': clip.m_Name,
            'channels': clip.m_Channels,
            'frequency': clip.m_Frequency,
            'length_s': round(clip.m_Length, 3),
            'files': [],
        }
        for fname, payload in samples.items():
            dest = os.path.join(OUT, safe(fname))
            with open(dest, 'wb') as fh:
                fh.write(payload)
            entry['files'].append(os.path.basename(dest))
        manifest.append(entry)
    json.dump(manifest, open('out/audio_manifest.json', 'w'), indent=1)
    print('clips', len(manifest), 'wav files', len(os.listdir(OUT)))


if __name__ == '__main__':
    main()

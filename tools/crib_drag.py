"""Crib-drag the container keystream with the game's CSV column names.

Within one header group all files share the same keystream, so ct_a XOR ct_b is
pt_a XOR pt_b. A correct crib at a given offset yields a keystream that decrypts
every file of the group to printable CSV; a wrong crib yields noise. The score is
the mean printable ratio across the whole group, which gives the crib-drag a very
sharp peak.
"""
import hashlib
import os
from collections import defaultdict

META = 'work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat'
DIR = 'work/apk/assets'
HEAP = 0x219458
PROBE = 1024
PRINT = bytes(1 if 9 <= i < 127 else 0 for i in range(256))


def columns():
    data = open(META, 'rb').read()
    start = data.find(b'ScenarioCSVHeaders', HEAP)
    cols = []
    for token in data[start:start + 1200].split(b'\x00')[1:]:
        if not token or len(token) > 40:
            break
        try:
            text = token.decode('ascii')
        except UnicodeDecodeError:
            break
        if not text.replace('_', '').replace('1', '').isalnum():
            break
        cols.append(text)
    return cols


def group_files():
    table = defaultdict(list)
    for name in sorted(os.listdir(DIR)):
        path = os.path.join(DIR, name)
        if not os.path.isfile(path):
            continue
        with open(path, 'rb') as fh:
            head = fh.read(26)
        if head[:8] != b'\x00IAP\x02\x00\x00\x00':
            continue
        table[head[8:26]].append(path)
    return max(table.values(), key=len)


def score(stream, blobs):
    total = 0.0
    for blob in blobs:
        n = min(len(stream), PROBE, len(blob))
        pt = bytes(a ^ b for a, b in zip(blob, stream[:n]))
        total += sum(pt.translate(PRINT)) / n
    return total / len(blobs)


def main():
    cols = columns()
    paths = group_files()
    blobs = [open(p, 'rb').read() for p in paths]
    print('group files', len(blobs), 'columns', len(cols))

    row = ','.join(cols)
    results = []
    for offset in range(0, 400):
        for crib in (row, row.replace(',', '\t'), row.upper()):
            raw = crib.encode()
            if offset + 32 > len(blobs[0]):
                continue
            stream = bytes(c ^ p for c, p in zip(blobs[0][offset:offset + len(raw)], raw))
            s = score(stream, [b[offset:] for b in blobs])
            results.append((round(s, 4), offset, crib[:30]))
    results.sort(reverse=True)
    seen = set()
    for row_ in results[:12]:
        if row_[1] in seen:
            continue
        seen.add(row_[1])
        print(row_)


if __name__ == '__main__':
    main()

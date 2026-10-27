"""Classify every \\x00IAP container by drag-scoring the CSV header crib.

For each header group the crib is dragged over the first 64 bytes; the winning
offset and its printable score say whether the file is designer-format CSV.
Groups of size >= 4 are scored across all members, single files on themselves
(with a stricter threshold, since a single file gives no cross-check).
"""
import os
import sys
from collections import defaultdict

sys.path.insert(0, 'tools')
from crib_drag import columns  # noqa: E402

DIR = 'work/apk/assets'
PRINT = bytes(1 if 9 <= i < 127 else 0 for i in range(256))


def groups():
    table = defaultdict(list)
    for name in sorted(os.listdir(DIR)):
        path = os.path.join(DIR, name)
        if not os.path.isfile(path):
            continue
        with open(path, 'rb') as fh:
            head = fh.read(64)
        if head[:8] != b'\x00IAP\x02\x00\x00\x00':
            continue
        table[head[8:26]].append((path, head[26:64]))
    return table


def score_group(members):
    crib = ','.join(columns()).encode()
    blobs = [open(p, 'rb').read() for p, _ in members]
    best = (0.0, -1)
    for offset in range(0, 64):
        if offset + crib.length if hasattr(crib, 'length') else offset + len(crib) > min(len(b) for b in blobs):
            continue
        stream = bytes(c ^ p for c, p in zip(blobs[0][offset:offset + len(crib)], crib))
        total = 0.0
        for blob in blobs:
            n = min(len(stream), 512, len(blob) - offset)
            pt = bytes(a ^ b for a, b in zip(blob[offset:offset + n], stream[:n]))
            total += sum(pt.translate(PRINT)) / n
        ratio = total / len(blobs)
        if ratio > best[0]:
            best = (ratio, offset)
    return best


def main():
    table = groups()
    print(f'{"file":22} {"group":>5} {"off":>4} {"score":>6}  verdict')
    for members in table.values():
        ratio, offset = score_group(members)
        name = os.path.basename(members[0][0])
        need = 0.95 if len(members) == 1 else 0.70
        verdict = 'designer CSV' if ratio >= need else 'legacy / other'
        print(f'{name:22} {len(members):5} {offset:4} {ratio:6.3f}  {verdict}')


if __name__ == '__main__':
    main()

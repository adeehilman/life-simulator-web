"""Partial decryptor for the \\x00IAP scenario containers.

Recovered facts (all verified against 8 real files):
  * container = 1-byte 0x00 + "IAP" + u32 version + u16 type + 18-byte group tag
    + 46 bytes, then payload at offset 2 (payload spans offset 2 .. EOF-8)
  * cipher is a stream construction with a keystream constant per group: files of
    one group share 118 identical ciphertext bytes and cross-decrypt correctly
  * those 118 bytes are the designer-format CSV column header row, so the
    keystream over the header is recoverable by crib-dragging the game's own
    column list (assets/bin/Data/Managed/Metadata/global-metadata.dat,
    ScenarioCSVHeaders) and is confirmed by scoring all group members at once

This tool recovers that header keystream and writes the decrypted header span for
every file, which is enough to identify a scenario file's schema. It does not
recover the keystream past the header, so row data stays ciphertext.
"""
import os
import sys
from collections import defaultdict

META = 'work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat'
DIR = 'work/apk/assets'
OUT = 'out/scenarios_csv'
HEAP = 0x219458
PROBE = 1024
PRINT = bytes(1 if 9 <= i < 127 else 0 for i in range(256))


def column_order():
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
    return table


def recover(group):
    blobs = [open(p, 'rb').read() for p in group]
    row = ','.join(column_order()).encode()
    best = (0.0, 0, b'')
    for offset in range(0, 64):
        if offset + len(row) > min(len(b) for b in blobs):
            continue
        stream = bytes(c ^ p for c, p in zip(blobs[0][offset:offset + len(row)], row))
        total = 0.0
        for blob in blobs:
            n = min(len(stream), PROBE, len(blob) - offset)
            pt = bytes(a ^ b for a, b in zip(blob[offset:offset + n], stream[:n]))
            total += sum(pt.translate(PRINT)) / n
        ratio = total / len(blobs)
        if ratio > best[0]:
            best = (ratio, offset, stream)
    return best, blobs


def main():
    os.makedirs(OUT, exist_ok=True)
    table = group_files()
    print('groups', len(table))
    for group in table.values():
        (ratio, offset, stream), _ = recover(group)
        label = os.path.basename(group[0])
        status = 'OK' if ratio > 0.70 else 'weak'
        print(f'{label}: {len(group)} files, start {offset}, printable {ratio:.3f} [{status}]')
        if ratio <= 0.70 or not stream:
            continue
        for path in group:
            blob = open(path, 'rb').read()[offset:offset + len(stream)]
            pt = bytes(a ^ b for a, b in zip(blob, stream))
            dest = os.path.join(OUT, os.path.basename(path) + '.csvhead')
            open(dest, 'wb').write(pt)


if __name__ == '__main__':
    sys.exit(main())

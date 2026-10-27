"""Uji hipotesis keystream = System.Random (Mono) dengan seed 32-bit.

Bukti sebelumnya mengatakan keystream bergantung posisi, bukan isi, dan tidak
terpakai ulang antar baris. Itu bentuk PRNG yang di-seed per baris/file, dan
`Random.NextBytes` di .NET mengisi array dengan `(byte)Next()` yaitu 8 bit rendah
InternalSample(). Keystream 1181 byte pertama sudah pulih dari crib CSV, jadi seed
bisa dicari: tiap kandidat harus cocok pada byte-byte awal.
"""
import struct
import sys

sys.path.insert(0, 'tools')
from crib_drag import columns, group_files  # noqa: E402

MBIG = 2147483647
MSEED = 161803398


def mono_random_bytes(seed, n):
    """Byte stream dari System.Random(seed) Mono, mengikuti implementasi runtime."""
    subtraction = MBIG if seed == -2147483648 else abs(seed)
    mj = MSEED - subtraction
    sa = [0] * 56
    sa[55] = mj
    mk = 1
    for i in range(1, 55):
        ii = (21 * i) % 55
        sa[ii] = mk
        mk = mj - mk
        if mk < 0:
            mk += MBIG
        mj = sa[ii]
    for _ in range(1, 5):
        for i in range(1, 56):
            sa[i] -= sa[1 + (i + 30) % 55]
            if sa[i] < 0:
                sa[i] += MBIG
    inext, inextp = 0, 21
    out = bytearray()
    for _ in range(n):
        inext += 1
        if inext >= 56:
            inext = 1
        inextp += 1
        if inextp >= 56:
            inextp = 1
        ret = sa[inext] - sa[inextp]
        if ret == MBIG:
            ret -= 1
        if ret < 0:
            ret += MBIG
        sa[inext] = ret
        out.append(ret & 0xFF)
    return bytes(out)


def main():
    blob = open(group_files()[0], 'rb').read()
    crib = ','.join(columns()).encode()
    ks = bytes(c ^ p for c, p in zip(blob[:len(crib)], crib))
    want = ks[:6]
    print('keystream target', want.hex())

    header = blob[:64]
    seeds = set()
    for off in range(0, 60):
        for ln in (4, 8):
            s = header[off:off + ln]
            if len(s) == ln:
                seeds.add(struct.unpack('<i' if ln == 4 else '<q', s)[0] & 0xFFFFFFFF)
    print('seed kandidat dari header', len(seeds))

    for seed in seeds:
        if mono_random_bytes(seed, 6) == want:
            print('MATCH seed', seed)
    print('selesai')


if __name__ == '__main__':
    main()

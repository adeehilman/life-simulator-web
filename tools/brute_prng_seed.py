"""Brute-force seed 32-bit untuk hipotesis System.Random, difilter cepat.

`(byte)Next()` hanya memakai 8 bit, jadi satu byte tidak cukup menyaring. Penyaring
dipakai 3 byte sekaligus (1/16 juta), dijalankan sampai batas waktu.
"""
import sys
import time

sys.path.insert(0, 'tools')
from test_prng_seed import mono_random_bytes  # noqa: E402
from crib_drag import columns, group_files  # noqa: E402


def main():
    blob = open(group_files()[0], 'rb').read()
    crib = ','.join(columns()).encode()
    ks = bytes(c ^ p for c, p in zip(blob[:len(crib)], crib))
    want = ks[:3]
    print('target', want.hex())

    t0 = time.time()
    limit = 4_000_000
    found = []
    for seed in range(limit):
        if mono_random_bytes(seed, 3) == want:
            found.append(seed)
            print('MATCH', seed)
        if seed % 200000 == 0 and seed:
            print(f'  {seed} ({time.time() - t0:.0f}s)', flush=True)
        if time.time() - t0 > 260:
            print('batas waktu di', seed)
            break
    print('kandidat', found)


if __name__ == '__main__':
    main()

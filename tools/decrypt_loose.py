"""Partial recovery for the loose \x00IAP containers in work/apk/assets.

Container layout (verified against all 28 files, 2026-10-25):

    00 "IAP" | u32 version (=2) | u16 type (=0x0807) | 18-byte group tag
    | payload (offset 28 .. EOF-8) | 8-byte trailer

Payload is a legacy-format scenario CSV. Its first 152 bytes are the column
header row, and those 152 bytes are encrypted with a keystream that is
*identical for every file of a group* -- all members are byte-identical over
0..179, so the header keystream is recoverable by crib-dragging the game's own
ScenarioCSVHeaders column list and cross-validating on the whole group.

Past byte 152 the keystream re-keys per file (a self-synchronising construction:
files whose plaintext agrees re-converge, which is why near-duplicate members
still share ~68% of their keystream). The body is therefore recovered
statistically as a two-time pad over the group, scored with a trigram model
built from the game's own scenario CSVs.

Outputs:
    out/loose/<name>.header.csv   decrypted header row (authoritative)
    out/loose/<name>.partial.csv  best-effort body, first PARTIAL bytes
    out/loose/_groups.json        group map + per-group member counts
"""
import collections
import json
import math
import os
import pickle
import sys

sys.path.insert(0, os.path.dirname(os.path.abspath(__file__)))
from crib_drag import columns  # noqa: E402

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')
DIR = os.path.join(ROOT, 'work', 'apk', 'assets')
OUT = os.path.join(ROOT, 'out', 'loose')
MODEL = os.path.join(ROOT, 'tools', 'model4.pkl')

MAGIC = b'\x00IAP\x02\x00\x00\x00'
HDR = 28            # container header length; payload starts here
SHARED = 152        # keystream is group-wide for exactly this many payload bytes
PARTIAL = 3000      # body bytes attempted per file


def containers():
    """Map group tag -> [(path, blob)] for every loose container."""
    table = collections.defaultdict(list)
    for name in sorted(os.listdir(DIR)):
        path = os.path.join(DIR, name)
        if not os.path.isfile(path):
            continue
        with open(path, 'rb') as fh:
            head = fh.read(28)
        if head[:8] != MAGIC:
            continue
        table[head[8:26]].append((path, open(path, 'rb').read()))
    return table


def header_keystream(blobs, crib):
    """Recover the group-wide header keystream and verify it on every member."""
    ks = bytes(c ^ p for c, p in zip(blobs[0][HDR:HDR + SHARED], crib))
    for blob in blobs[1:]:
        if blob[HDR:HDR + SHARED] != blobs[0][HDR:HDR + SHARED]:
            raise SystemExit('group members diverge inside the shared header span')
    return ks


def load_model():
    tri, bi, uni, alpha = pickle.load(open(MODEL, 'rb'))
    allowed = set(alpha)
    total = sum(uni.values())
    uni_p = [(uni.get(b, 0) + 0.5) / (total + 0.5 * 256) for b in range(256)]
    log_uni = [math.log(uni_p[b]) if b in allowed else -16.0 for b in range(256)]
    log_bi = {}
    for a in range(256):
        row = bi.get(a, {})
        n = sum(row.values())
        log_bi[a] = [math.log((row.get(b, 0) + 2.0 * uni_p[b]) / (n + 2.0))
                     if b in allowed else -16.0 for b in range(256)]
    cache = {}

    def logp(ctx, b):
        key = (ctx, b)
        hit = cache.get(key)
        if hit is not None:
            return hit
        if b not in allowed:
            val = -16.0
        else:
            row = tri.get(ctx)
            if row:
                n = sum(row.values())
                val = math.log((row.get(b, 0) + 2.0 * uni_p[b]) / (n + 2.0))
            else:
                val = log_bi[ctx[1]][b]
        cache[key] = val
        return val

    return allowed, log_uni, logp


def recover_body(blobs, n):
    """Iterated conditional modes over a group two-time pad.

    Each position picks the keystream byte maximising the summed trigram
    likelihood of the group's candidate plaintexts, then the plaintexts are
    rewritten. Converges in a handful of passes; ambiguous positions keep the
    previous choice.
    """
    allowed, log_uni, logp = load_model()
    n = min(n, min(len(b) for b in blobs) - HDR - SHARED)
    ct = [[b[HDR + SHARED + i] for i in range(n)] for b in blobs]
    pt = [[0] * n for _ in blobs]
    ks = [0] * n
    for p in range(n):
        best = None
        for k in range(256):
            s = sum(log_uni[c[p] ^ k] for c in ct)
            if best is None or s > best[0]:
                best = (s, k)
        ks[p] = best[1]
        for j in range(len(blobs)):
            pt[j][p] = ct[j][p] ^ ks[p]
    for _ in range(6):
        for p in range(n):
            ctxs = [(pt[j][p - 2] if p > 1 else 0x2c,
                     pt[j][p - 1] if p else 0x2c) for j in range(len(blobs))]
            best = None
            for k in range(256):
                s = 0.0
                for j in range(len(blobs)):
                    s += logp(ctxs[j], ct[j][p] ^ k)
                if best is None or s > best[0]:
                    best = (s, k)
            ks[p] = best[1]
            for j in range(len(blobs)):
                pt[j][p] = ct[j][p] ^ ks[p]
    return pt


def main():
    os.makedirs(OUT, exist_ok=True)
    crib = ','.join(columns()).encode()[:SHARED]
    groups = containers()
    index = {}
    for tag, members in groups.items():
        blobs = [b for _, b in members]
        ks = header_keystream(blobs, crib)
        for path, blob in members:
            name = os.path.basename(path)
            head = bytes(c ^ k for c, k in zip(blob[HDR:HDR + SHARED], ks))
            with open(os.path.join(OUT, name + '.header.csv'), 'wb') as fh:
                fh.write(head)
        index[tag.hex()] = [os.path.basename(p) for p, _ in members]
        print(f'group {tag.hex()} members={len(members)} header recovered')

    # statistical body pass, largest group first (more members = sharper pad)
    for tag, members in sorted(groups.items(), key=lambda kv: -len(kv[1])):
        if len(members) < 2:
            continue
        blobs = [b for _, b in members]
        pt = recover_body(blobs, PARTIAL)
        for i, (path, _) in enumerate(members):
            name = os.path.basename(path)
            with open(os.path.join(OUT, name + '.partial.csv'), 'wb') as fh:
                fh.write(bytes(pt[i]))
        print(f'group {tag.hex()} body pass over {PARTIAL} bytes, {len(members)} members')

    with open(os.path.join(OUT, '_groups.json'), 'w') as fh:
        json.dump(index, fh, indent=1)
    print('wrote', OUT)


if __name__ == '__main__':
    main()

# Find all direct BL/BLX-imm call sites targeting given addresses in libil2cpp.so.
# Fast byte-pattern scan for ARM branch-with-link, then target computation.
# Usage: python tools/find_callers.py 0x15C4E50 [0x1F6E348 ...]
import json, struct, sys, re, bisect
from pathlib import Path

ROOT = Path(__file__).resolve().parent.parent
SO = ROOT / 'work' / 'native' / 'libil2cpp.so'
MBA = ROOT / 'out' / 'il2cpp' / 'method_by_address.json'

mba = json.loads(MBA.read_text(encoding='utf-8', errors='replace'))
lut = {}
for k, v in mba.items():
    s = k.lower()
    if s.startswith('0x'): s = s[2:]
    lut['0x' + s.zfill(8)] = v
addrs = sorted(int(k, 16) for k in lut)

def name(a):
    return lut.get('0x' + format(a, '08x'))

def containing(a):
    i = bisect.bisect_right(addrs, a) - 1
    return addrs[i] if i >= 0 else None

b = SO.read_bytes()
f = open(SO, 'rb')
f.seek(28); e_phoff = struct.unpack('<I', f.read(4))[0]
f.seek(42); e_phentsize, e_phnum = struct.unpack('<HH', f.read(4))
SEGS = []
for i in range(e_phnum):
    f.seek(e_phoff + i * e_phentsize)
    ph = f.read(e_phentsize)
    p_type, p_offset, p_vaddr, _ = struct.unpack('<IIII', ph[:16])
    p_filesz, _ = struct.unpack('<II', ph[16:24])
    p_flags, _ = struct.unpack('<II', ph[24:32])
    if p_type == 1:
        SEGS.append((p_vaddr, p_offset, p_filesz, p_flags))
f.close()

def off2va(off):
    for va, o, sz, fl in SEGS:
        if o <= off < o + sz:
            return va + (off - o)
    return None

# BL (cond != NV): top byte 0x0B..0xEB ; BLX imm: 0xFA/0xFB
PAT = re.compile(rb'[\x0b\x1b\x2b\x3b\x4b\x5b\x6b\x7b\x8b\x9b\xab\xbb\xcb\xdb\xeb\xfa\xfb]')

targets = [int(x, 0) for x in sys.argv[1:]]
if not targets:
    print('usage: find_callers.py <target_rva> [...]'); sys.exit(1)
tset = set(targets)

hits = {t: [] for t in targets}
for m in PAT.finditer(b):
    off = m.start()
    if off % 4 != 0:
        continue
    va = off2va(off)
    if va is None or va % 4 != 0:
        continue
    w = struct.unpack_from('<I', b, off)[0]
    top = w >> 24
    if top in (0xFA, 0xFB):
        # BLX imm: 1111 101H imm24
        h = (w >> 24) & 1
        imm = w & 0x00FFFFFF
        if imm & 0x800000: imm -= 0x1000000
        t = (va + 8 + (imm << 2) + (h << 1)) & 0xFFFFFFFF
    else:
        cond = (w >> 28) & 0xF
        if cond == 0xF:
            continue
        imm = w & 0x00FFFFFF
        if imm & 0x800000: imm -= 0x1000000
        t = (va + 8 + (imm << 2)) & 0xFFFFFFFF
    if t in tset:
        hits[t].append(va)

for t in targets:
    lst = sorted(hits[t])
    print(f'\n=== call sites -> 0x{t:08X} {name(t) or "[unnamed]"} : {len(lst)} ===')
    bymethod = {}
    for va in lst:
        c = containing(va)
        bymethod.setdefault(c, []).append(va)
    for c in sorted(bymethod, key=lambda x: (x is None, x)):
        nm = name(c) if c else None
        print(f'  0x{c:08X}  {nm or "[unnamed]"}   ({len(bymethod[c])} site(s): ' +
              ', '.join(f'0x{v:08X}' for v in bymethod[c][:6]) + ('...' if len(bymethod[c]) > 6 else '') + ')')

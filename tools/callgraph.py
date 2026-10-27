# Extract direct call targets from ARM functions in libil2cpp.so.
# Resolves BL/BLX targets and veneer (movw/movt/add/bx) targets against script.json.
# Usage: python tools/callgraph.py <rva> [size] [label]
import json, struct, sys, os
from pathlib import Path

HERE = Path(__file__).resolve().parent
ROOT = HERE.parent
SO = ROOT / 'work' / 'native' / 'libil2cpp.so'
SCRIPT = ROOT / 'out' / 'il2cpp' / 'script.json'

sj = json.loads(SCRIPT.read_text(encoding='utf-8', errors='replace'))
NAMES = {}
for m in sj['ScriptMethod']:
    NAMES[m['Address'] & ~1] = m.get('Name', '')

b = SO.read_bytes()
# PT_LOAD segments
f = open(SO, 'rb')
f.seek(28); e_phoff = struct.unpack('<I', f.read(4))[0]
f.seek(42); e_phentsize, e_phnum = struct.unpack('<HH', f.read(4))
SEGS = []
for i in range(e_phnum):
    f.seek(e_phoff + i * e_phentsize)
    ph = f.read(e_phentsize)
    p_type, p_offset, p_vaddr, _ = struct.unpack('<IIII', ph[:16])
    p_filesz, _ = struct.unpack('<II', ph[16:24])
    if p_type == 1:
        SEGS.append((p_vaddr, p_offset, p_filesz))
f.close()

def v2o(v):
    for va, off, sz in SEGS:
        if va <= v < va + sz:
            return off + (v - va)
    return None

def name(a):
    return NAMES.get(a & ~1)

def decode_veneer(va):
    """movw ip,#lo ; movt ip,#hi ; add ip,ip,pc ; bx ip -> absolute target"""
    off = v2o(va)
    if off is None: return None
    w = struct.unpack_from('<4I', b, off)
    def imm16(x):
        return (((x >> 16) & 0xF) << 12) | (x & 0xFFF)
    base = (imm16(w[1]) << 16) | imm16(w[0])
    pc = va + 16
    return (base + pc) & 0xFFFFFFFF

def bl_target(insn_addr, insn):
    """ARM BL: target = insn_addr + 8 + (imm24 << 2) sign-extended"""
    imm = insn & 0x00FFFFFF
    if imm & 0x800000:
        imm -= 0x1000000
    return (insn_addr + 8 + (imm << 2)) & 0xFFFFFFFF

def main():
    rva = int(sys.argv[1], 0) & ~1
    size = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    label = sys.argv[3] if len(sys.argv) > 3 else name(rva) or '?'

    off = v2o(rva)
    if off is None:
        print(f'cannot map RVA 0x{rva:08X}'); sys.exit(1)

    code = b[off:off+size]
    print(f'=== {label} @ 0x{rva:08X} (size 0x{size:X}) ===')

    calls = []
    i = 0
    while i + 4 <= len(code):
        insn = struct.unpack_from('<I', code, i)[0]
        va = rva + i
        cond = (insn >> 28) & 0xF

        # BL (cond != F): 1010/1011 in bits 27-24 with link bit
        if cond != 0xF and (insn & 0x0F000000) in (0x0A000000, 0x0B000000):
            t = bl_target(va, insn)
            calls.append((va, 'BL', t))

        # BLX register: 0x012FFF30 | (rm << 0)  -> cond 0xF not used; BLX imm is 1111 101H
        if (insn & 0xFE000000) == 0xFA000000:
            h = (insn >> 24) & 1
            imm = insn & 0x00FFFFFF
            if imm & 0x800000: imm -= 0x1000000
            t = (va + 8 + (imm << 2) + (h << 1)) & 0xFFFFFFFF
            calls.append((va, 'BLX', t))

        # BLX register: cond != F, 0001 0010 ---- ---- ---- 0001 rmmm
        if cond != 0xF and (insn & 0x0FFFFFF0) == 0x012FFF10:
            rm = insn & 0xF
            calls.append((va, f'BLXr r{rm}', None))

        i += 4

    print(f'  direct calls: {len(calls)}')
    for va, kind, t in calls:
        if t is None:
            print(f'    0x{va:08X}  {kind}')
            continue
        # check veneer: movw ip,#lo ; movt ip,#hi ; add X,X,pc ; bx X
        voff = v2o(t)
        is_veneer = False
        vtarget = None
        if voff is not None and voff + 16 <= len(b):
            w = struct.unpack_from('<4I', b, voff)
            def imm16(x):
                return (((x >> 16) & 0xF) << 12) | (x & 0xFFF)
            # w[3] = bx Rm ; w[2] = add Rd,Rn,pc with Rn==Rd and Rm==pc
            bx_ok = (w[3] & 0x0FFFFFF0) == 0x012FFF10
            add_ok = ((w[2] & 0x0FF00000) == 0x00800000
                      and ((w[2] >> 16) & 0xF) == ((w[2] >> 12) & 0xF)
                      and (w[2] & 0xF) == 0xF)
            movw_ok = (w[0] & 0x0FF00000) == 0x03000000
            movt_ok = (w[1] & 0x0FF00000) == 0x03400000
            if bx_ok and add_ok and movw_ok and movt_ok:
                is_veneer = True
                base = (imm16(w[1]) << 16) | imm16(w[0])
                pc = t + 16
                vtarget = (base + pc) & 0xFFFFFFFF
        if is_veneer:
            n = name(vtarget)
            print(f'    0x{va:08X}  {kind} 0x{t:08X} [veneer] -> 0x{vtarget:08X}  {n or "[unnamed]"}')
        else:
            n = name(t)
            print(f'    0x{va:08X}  {kind} 0x{t:08X}  {n or "[unnamed]"}')

if __name__ == '__main__':
    main()

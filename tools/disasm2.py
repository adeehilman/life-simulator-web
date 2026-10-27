# Disassemble ARM functions from libil2cpp.so with method names resolved
# from Il2CppDumper's script.json. Usage:
#   python disasm2.py <rva> [size] [--all]   (defaults: size=0x200, stop at pop {..., pc})
import json, struct, sys, os
import capstone

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT = os.path.join(HERE, '..')
SO = os.path.join(ROOT, 'work', 'native', 'libil2cpp.so')
SCRIPT = os.path.join(ROOT, 'out', 'il2cpp', 'script.json')

with open(SO, 'rb') as f:
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

script = json.load(open(SCRIPT, encoding='utf-8'))
NAMES = {}
for m in script['ScriptMethod']:
    NAMES[m['Address'] & ~1] = m.get('Name', '')

print(f"loaded {len(NAMES)} method names", file=sys.stderr)

def v2o(v):
    for va, off, sz in SEGS:
        if va <= v < va + sz:
            return off + (v - va)
    return None

def main():
    if len(sys.argv) < 2:
        print("usage: disasm2.py <rva> [size] [--all]")
        sys.exit(1)
    rva = int(sys.argv[1], 0) & ~1
    size = int(sys.argv[2], 0) if len(sys.argv) > 2 else 0x200
    stop_at_pop = '--all' not in sys.argv
    with open(SO, 'rb') as f:
        off = v2o(rva)
        f.seek(off)
        code = f.read(size)
    md = capstone.Cs(capstone.CS_ARCH_ARM, capstone.CS_MODE_ARM)
    out = [f"=== {NAMES.get(rva, '?')} @ {hex(rva)} ==="]
    for ins in md.disasm(code, rva):
        line = f"{ins.address:08x}  {ins.mnemonic:8} {ins.op_str}"
        if ins.mnemonic in ('bl', 'b') and ins.op_str.startswith('#0x'):
            tgt = int(ins.op_str[1:], 0) & ~1
            if tgt in NAMES:
                line += f"   ; -> {NAMES[tgt]}"
        out.append(line)
        if stop_at_pop and ins.mnemonic == 'pop' and 'pc' in ins.op_str:
            break
    print('\n'.join(out))

if __name__ == '__main__':
    main()

# Answer three RNG questions against RAW libil2cpp.so bytes + script.json,
# using function boundaries derived fresh from out/il2cpp/method_by_address.json —
# deliberately NOT trusting any degraded Ghidra database state left behind by early
# DecompileRng3253.java runs that destroyed .cctor function boundaries.
#
#   Q1 : Do GameReference.GetRandomNumber / DataHub.GetRandomNumber pass max or
#        max+something into System.Random.Next(int,int)? -> inclusive/exclusive?
#   Q2 : Are getrandom fields built by new Random() or new Random(constant seed)?
#   Q3 : Is ANY UnityEngine member reached directly inside EVERY Sim*$$IncrementAge
#        body (scope A), plus through each immediate callee whose owning class starts
#        with "Sim"/"SocialMedia"/"PersonGenerator"/"DataHub"/"GameReference"
#        (scope B, one hop)?
#
import bisect
import json
import os
import struct

HERE = os.path.dirname(os.path.abspath(__file__))
ROOT_DIR = os.path.normpath(os.path.join(HERE, '..'))
SO_PATH = os.path.join(ROOT_DIR, 'work', 'native', 'libil2cpp.so')
SCRIPT_PATH = os.path.join(ROOT_DIR, 'out', 'il2cpp', 'script.json')
MBA_PATH = os.path.join(ROOT_DIR, 'out', 'il2cpp', 'method_by_address.json')

b = open(SO_PATH, 'rb').read()
sj = json.loads(open(SCRIPT_PATH, encoding='utf-8').read())
mba_raw = json.loads(open(MBA_PATH, encoding='utf-8').read())

# PT_LOAD segments: (vaddr, file_offset, filesz). libil2cpp.so's first PT_LOAD
# maps file offset == vaddr, but do not rely on that — map explicitly.
_fh = open(SO_PATH, 'rb')
_fh.seek(28); _e_phoff = struct.unpack('<I', _fh.read(4))[0]
_fh.seek(42); _e_phentsize, _e_phnum = struct.unpack('<HH', _fh.read(4))
SEGS = []
for _i in range(_e_phnum):
    _fh.seek(_e_phoff + _i * _e_phentsize)
    _ph = _fh.read(_e_phentsize)
    _p_type, _p_offset, _p_vaddr = struct.unpack_from('<III', _ph, 0)
    _p_filesz = struct.unpack_from('<I', _ph, 16)[0]
    if _p_type == 1:
        SEGS.append((_p_vaddr, _p_offset, _p_filesz))
_fh.close()


def va2off(va):
    for vaddr, off, sz in SEGS:
        if vaddr <= va < vaddr + sz:
            return off + (va - vaddr)
    return None

NAMES = {}
for m in sj['ScriptMethod']:
    NAMES[m['Address'] & ~1] = m.get('Name', '')

print(f"[init] binary {len(b)} bytes; {len(sj['ScriptMethod'])} methods in script.json")

def parse_mba():
    """Normalize method_by_address.json into {addr:int: name:str} regardless of its nesting."""
    out = {}

    def walk(node):
        if isinstance(node, dict):
            for k, v in node.items():
                if isinstance(v, str) and ('$$' in v or v.startswith('System.')):
                    try:
                        a0 = int(str(k), 16)
                        out[a0 & ~1] = v
                    except ValueError:
                        pass
                else:
                    walk(v)
        elif isinstance(node, list):
            for item in node:
                walk(item)

    walk(mba_raw)
    return out

MBA = parse_mba()
ADDRS = sorted(MBA.keys())
print(f"[init] normalized method_by_address.json -> {len(MBA)} address->name entries")


def method_name(addr):
    return MBA.get(addr & ~1) or NAMES.get(addr & ~1)


def method_bounds(addr):
    """(start, end_exclusive) derived from the next known method address."""
    a = addr & ~1
    i = bisect.bisect_right(ADDRS, a) - 1
    if i < 0 or ADDRS[i] != a:
        return None
    end = ADDRS[i + 1] if i + 1 < len(ADDRS) else None
    return (a, end)


# ---------------------------------------------------------------------------
# ARM32 decode helpers (no capstone dependency: we only need BL/BLX/MOV/MOVT/
# LDR-literal/STR/BX, which is enough for these three questions).
# ---------------------------------------------------------------------------

def read_words(start, end):
    """Yield (addr, word) for 4-byte-aligned VAs in [start, end).

    `start`/`end` are virtual addresses; the file offset is resolved through the
    PT_LOAD table. Words outside every PT_LOAD are skipped.
    """
    if end is None:
        end = 0xFFFFFFFF
    for a in range(start & ~3, end & ~3, 4):
        off = va2off(a)
        if off is None or off + 4 > len(b):
            continue
        yield a, struct.unpack_from('<I', b, off)[0]


def bl_target(addr, word):
    imm = word & 0x00FFFFFF
    if imm & 0x800000:
        imm -= 0x1000000
    return (addr + 8 + (imm << 2)) & 0xFFFFFFFF


def blx_imm_target(addr, word):
    h = (word >> 24) & 1
    imm = word & 0x00FFFFFF
    if imm & 0x800000:
        imm -= 0x1000000
    return (addr + 8 + (imm << 2) + (h << 1)) & 0xFFFFFFFF


def movw_movt_imm(word):
    imm4 = (word >> 16) & 0xF
    imm12 = word & 0xFFF
    return (imm4 << 12) | imm12


def is_movw(word):
    return (word & 0x0FF00000) == 0x03000000


def is_movt(word):
    return (word & 0x0FF00000) == 0x03400000


def is_mov_imm(word):
    return (word & 0x0FF00000) == 0x03A00000


def is_bx(word):
    return (word & 0x0FFFFFF0) == 0x012FFF10


def bx_reg(word):
    return word & 0xF


def is_add_reg_pc(word):
    """add Rd, Rn, pc  (Rn == Rd, Rm == pc)"""
    return (
        (word & 0x0FF00000) == 0x00800000
        and ((word >> 16) & 0xF) == ((word >> 12) & 0xF)
        and (word & 0xF) == 0xF
    )


def is_ldr_literal(word):
    return (word & 0x0F7F0000) == 0x051F0000


def is_str_imm(word):
    return (word & 0x0C500000) == 0x04000000


def is_str_reg(word):
    return (word & 0x0E000090) == 0x06000090


def is_mov_reg(word):
    return (word & 0x0FF00000) == 0x01A00000


def mov_reg_fields(word):
    rm = word & 0xF
    rd = (word >> 12) & 0xF
    return rd, rm


def resolve_veneer(addr):
    """movw ip,#lo ; movt ip,#hi ; add X,X,pc ; bx X -> absolute target."""
    words = list(read_words(addr, addr + 16))
    if len(words) < 4:
        return None
    (_, w0), (_, w1), (_, w2), (_, w3) = words
    if not (is_movw(w0) and is_movt(w1) and is_add_reg_pc(w2) and is_bx(w3)):
        return None
    base = (movw_movt_imm(w1) << 16) | movw_movt_imm(w0)
    pc = addr + 16
    return (base + pc) & 0xFFFFFFFF


def literal_pool_value(addr, word):
    """ldr rX, [pc, #imm] -> the 32-bit word at the computed address."""
    imm = word & 0xFFF
    target = (addr + 8 + imm) & 0xFFFFFFFF
    off = va2off(target)
    if off is None or off + 4 > len(b):
        return None
    return struct.unpack_from('<I', b, off)[0]


def direct_calls(start, end):
    """[(call_site, target, kind)] for BL / BLX-imm / BLX-register inside [start, end).

    kind is 'BL', 'BLX-imm' or 'BLX-reg'. Plain conditional/unconditional branches
    (opcode 0x0A......) are NOT calls and are deliberately excluded — including them
    made earlier callgraphs look far denser than they were.
    """
    out = []
    for a, w in read_words(start, end):
        cond = (w >> 28) & 0xF
        if cond == 0xF:
            continue
        if (w & 0x0F000000) == 0x0B000000:          # BL
            out.append((a, bl_target(a, w), 'BL'))
        elif (w & 0xFE000000) == 0xFA000000:        # BLX imm
            out.append((a, blx_imm_target(a, w), 'BLX-imm'))
        elif (w & 0x0FFFFFF0) == 0x012FFF30:        # BLX reg (bit5 set)
            out.append((a, w & 0xF, 'BLX-reg'))
    return out


def resolve_calls(start, end):
    """[(call_site, resolved_target_or_reg, kind, raw, was_veneer)] with veneers expanded.

    For 'BLX-reg' the second element is the register number, not an address.
    """
    out = []
    for site, tgt, kind in direct_calls(start, end):
        if kind == 'BLX-reg':
            out.append((site, tgt, kind, None, False))
            continue
        vt = resolve_veneer(tgt)
        if vt is not None:
            out.append((site, vt, kind, tgt, True))
        else:
            out.append((site, tgt, kind, tgt, False))
    return out


# ---------------------------------------------------------------------------
# Minimal instruction pretty-printer (enough to read argument setup by eye).
# ---------------------------------------------------------------------------

CONDS = ['eq', 'ne', 'cs', 'cc', 'mi', 'pl', 'vs', 'vc',
         'hi', 'ls', 'ge', 'lt', 'gt', 'le', '', 'nv']


def _cond_str(word):
    return CONDS[(word >> 28) & 0xF]


def decode_insn(addr, w):
    c = _cond_str(w)
    op = (w >> 25) & 0x7

    # data processing, immediate
    if op == 0b001 and (w & 0x02000000) == 0 and (w & 0x01000000):
        opc = (w >> 21) & 0xF
        rn = (w >> 16) & 0xF
        rd = (w >> 12) & 0xF
        imm = w & 0xFF
        rot = ((w >> 8) & 0xF) * 2
        val = ((imm >> rot) | (imm << (32 - rot))) & 0xFFFFFFFF if rot else imm
        names = {0xD: 'mov', 0xF: 'mvn', 0x8: 'tst', 0x9: 'teq', 0xA: 'cmp', 0xB: 'cmn'}
        nm = names.get(opc, f'dp{opc:X}')
        if opc in (0xD, 0xF):
            return f'{nm}{c} r{rd}, #0x{val:X}'
        return f'{nm}{c} r{rd}, r{rn}, #0x{val:X}'

    # data processing, register
    if op == 0b000 and (w & 0x02000000) == 0 and (w & 0x01000000) and (w & 0x0FF00000) == 0x01A00000:
        rd, rm = mov_reg_fields(w)
        return f'mov{c} r{rd}, r{rm}'

    # ldr literal (PC-relative) — check BEFORE generic load/store so it prints as pc
    if is_ldr_literal(w):
        rd = (w >> 12) & 0xF
        imm = w & 0xFFF
        tgt = (addr + 8 + imm) & 0xFFFFFFFF
        val = literal_pool_value(addr, w)
        extra = f'  ; [0x{tgt:08X}] = 0x{val:08X}' if val is not None else ''
        return f'ldr{c} r{rd}, [pc, #0x{imm:X}]{extra}'

    # load/store immediate offset
    if (w & 0x0C000000) == 0x04000000:
        rd = (w >> 12) & 0xF
        rn = (w >> 16) & 0xF
        imm = w & 0xFFF
        is_load = (w >> 20) & 1
        up = (w >> 23) & 1
        mnem = 'ldr' if is_load else 'str'
        base = 'pc' if rn == 15 else f'r{rn}'
        sign = '' if up else '-'
        return f'{mnem}{c} r{rd}, [{base}, #{sign}0x{imm:X}]'

    # add Rd, Rn, Rm (register) — includes add Rd, Rd, pc used by veneers
    if (w & 0x0FE00000) == 0x00800000 and (w & 0x02000090) == 0x00000000:
        rd = (w >> 12) & 0xF
        rn = (w >> 16) & 0xF
        rm = w & 0xF
        rn_s = 'pc' if rn == 15 else f'r{rn}'
        rm_s = 'pc' if rm == 15 else f'r{rm}'
        return f'add{c} r{rd}, {rn_s}, {rm_s}'

    # ldrd
    if (w & 0x0E000000) == 0x00000000 and (w & 0x0D900000) == 0x00D00000:
        rn = (w >> 16) & 0xF
        rd = (w >> 12) & 0xF
        imm8h = (w >> 8) & 0xF
        imm8l = w & 0xF
        imm = (imm8h << 4) | imm8l
        rn_s = 'pc' if rn == 15 else f'r{rn}'
        return f'ldrd{c} r{rd}, r{rd+1}, [{rn_s}, #0x{imm:X}]'

    # bl / blx
    if (w & 0x0F000000) == 0x0B000000:
        t = bl_target(addr, w)
        nm = method_name(t) or '[unnamed]'
        vt = resolve_veneer(t)
        if vt is not None:
            nm2 = method_name(vt) or '[unnamed]'
            return f'bl{c} 0x{t:08X}  ; veneer -> 0x{vt:08X} {nm2}'
        return f'bl{c} 0x{t:08X}  ; {nm}'
    if (w & 0xFE000000) == 0xFA000000:
        t = blx_imm_target(addr, w)
        return f'blx{c} 0x{t:08X}'
    # blx register (bit5 set) / bx register
    if (w & 0x0FFFFFF0) == 0x012FFF30:
        return f'blx{c} r{w & 0xF}'
    if (w & 0x0FFFFFF0) == 0x012FFF10:
        return f'bx{c} r{w & 0xF}'

    # push/pop
    if (w & 0x0FFF0000) == 0x092D0000:
        return f'push{c} {{{w & 0xFFFF:04X}}}'
    if (w & 0x0FFF0000) == 0x08BD0000:
        return f'pop{c} {{{w & 0xFFFF:04X}}}'

    # cmp/cmn with immediate
    if (w & 0x0F000000) == 0x03000000 and (w & 0x0FF00000) == 0x03500000:
        rn = (w >> 16) & 0xF
        imm = w & 0xFF
        rot = ((w >> 8) & 0xF) * 2
        val = ((imm >> rot) | (imm << (32 - rot))) & 0xFFFFFFFF if rot else imm
        opc = (w >> 21) & 0xF
        nm = {0xA: 'cmp', 0xB: 'cmn', 0x8: 'tst', 0x9: 'teq'}.get(opc, 'dp')
        return f'{nm}{c} r{rn}, #0x{val:X}'

    # conditional branch
    if (w & 0x0F000000) == 0x0A000000:
        imm = w & 0x00FFFFFF
        if imm & 0x800000:
            imm -= 0x1000000
        t = (addr + 8 + (imm << 2)) & 0xFFFFFFFF
        return f'b{c} 0x{t:08X}'

    return f'.word 0x{w:08X}'


# ---------------------------------------------------------------------------
# Q1 — bound semantics of the two wrappers
# ---------------------------------------------------------------------------

def trace_arg_registers(start, end, call_site, arg_regs):
    """Track MOV/MOVW/MOVT writes to `arg_regs` in the window [start, call_site).

    Returns a list of (reg, addr, description) of the last write to each arg reg,
    so we can see whether max was modified before the call.
    """
    last_write = {}
    for a, w in read_words(start, call_site):
        if is_movw(w) or is_movt(w):
            rd = (w >> 12) & 0xF
            if rd in arg_regs:
                last_write[rd] = (a, 'movw/movt', movw_movt_imm(w))
        elif is_mov_imm(w):
            rd = (w >> 12) & 0xF
            imm = w & 0xFF
            rot = ((w >> 8) & 0xF) * 2
            val = ((imm >> rot) | (imm << (32 - rot))) & 0xFFFFFFFF if rot else imm
            if rd in arg_regs:
                last_write[rd] = (a, 'mov-imm', val)
        elif is_mov_reg(w):
            rd, rm = mov_reg_fields(w)
            if rd in arg_regs:
                last_write[rd] = (a, f'mov r{rm}', None)
    return last_write


def q1():
    print("\n" + "=" * 78)
    print("Q1 — bound semantics of GameReference/DataHub GetRandomNumber wrappers")
    print("=" * 78)

    targets = {
        'DataHub.GetRandomNumber': 0x15C4E50,
        'GameReference.GetRandomNumber': 0x1F6E348,
    }
    report = {}
    for label, rva in targets.items():
        bounds = method_bounds(rva)
        if not bounds:
            print(f"  {label}: bounds not found in method_by_address.json")
            continue
        start, end = bounds
        print(f"\n  {label} @ 0x{rva:08X}  bounds=[0x{start:08X}, 0x{end:08X})  size=0x{end-start:X}")
        calls = resolve_calls(start, end)
        print(f"    direct calls (BL/BLX only, branches excluded): {len(calls)}")
        for site, tgt, kind, raw, ven in calls:
            if kind == 'BLX-reg':
                print(f"      0x{site:08X}  BLX r{tgt}   <-- INDIRECT (vtable) call")
                continue
            nm = method_name(tgt) or '[unnamed]'
            tag = ' [veneer]' if ven else ''
            print(f"      0x{site:08X}  {kind} 0x{tgt:08X}{tag}  {nm}")

        # Locate the indirect call and show the argument setup immediately before it.
        indirect = [(cs, ct) for cs, ct, ck, craw, cv in calls if ck == 'BLX-reg']
        arg_trace = []
        for site, reg in indirect:
            print(f"\n    --- FULL body: argument setup before BLX r{reg} @ 0x{site:08X} ---")
            for a, w in read_words(start, site + 4):
                off = va2off(a)
                if off is None:
                    continue
                desc = decode_insn(a, w)
                print(f"      0x{a:08X}  {desc}")
            arg_trace.append({'site': hex(site), 'reg': reg})

        report[label] = {
            'rva': hex(rva), 'bounds': [hex(start), hex(end)],
            'calls': [
                {'site': hex(cs), 'target': (hex(ct) if ck != 'BLX-reg' else f'r{ct}'),
                 'kind': ck, 'name': (method_name(ct) if ck != 'BLX-reg' else 'INDIRECT'),
                 'veneer': cv}
                for cs, ct, ck, craw, cv in calls
            ],
            'indirect_calls': arg_trace,
        }
    return report


# ---------------------------------------------------------------------------
# Q2 — .cctor seeding of getrandom
# ---------------------------------------------------------------------------

def find_ctor_calls(start, end):
    """Return the ctor call sites inside a .cctor, in address order."""
    out = []
    for site, tgt, kind, raw, ven in resolve_calls(start, end):
        if kind == 'BLX-reg':
            continue
        nm = method_name(tgt) or ''
        if '.ctor' in nm or 'ctor' in nm.lower():
            out.append((site, tgt, nm, ven))
    return out


def q2():
    print("\n" + "=" * 78)
    print("Q2 — how getrandom is seeded (.cctor analysis)")
    print("=" * 78)

    cctors = {
        'DataHub..cctor': 0x18B0B30,
        'GameReference..cctor': 0x1F7F5D8,
    }
    report = {}
    for label, rva in cctors.items():
        bounds = method_bounds(rva)
        if not bounds:
            print(f"  {label}: bounds not found")
            continue
        start, end = bounds
        print(f"\n  {label} @ 0x{rva:08X}  bounds=[0x{start:08X}, 0x{end:08X})  size=0x{end-start:X}")
        calls = resolve_calls(start, end)
        ctors = find_ctor_calls(start, end)
        print(f"    direct calls: {len(calls)}; ctor calls: {len(ctors)}")
        for site, tgt, nm, ven in ctors:
            print(f"      0x{site:08X} -> 0x{tgt:08X}  {nm}{' [veneer]' if ven else ''}")

        # Full listing of the window around each Random ctor, so the seed argument
        # (or its absence) is visible rather than inferred.
        for site, tgt, nm, ven in ctors:
            if 'Random' not in nm:
                continue
            print(f"\n    --- window around Random ctor call @ 0x{site:08X} ---")
            wstart = max(start, site - 0x40)
            for a, w in read_words(wstart, site + 4):
                print(f"      0x{a:08X}  {decode_insn(a, w)}")

        report[label] = {
            'rva': hex(rva), 'bounds': [hex(start), hex(end)],
            'ctor_calls': [{'site': hex(s), 'target': hex(t), 'name': n, 'veneer': v}
                           for s, t, n, v in ctors],
        }
    return report


# ---------------------------------------------------------------------------
# Q3 — UnityEngine reachability inside Sim*.IncrementAge
# ---------------------------------------------------------------------------

def q3():
    print("\n" + "=" * 78)
    print("Q3 — UnityEngine reachability inside Sim*$$IncrementAge")
    print("=" * 78)

    # Every method whose name ends with IncrementAge and whose owner starts with Sim.
    sim_inc = []
    for a, nm in MBA.items():
        if not nm or '$$' not in nm:
            continue
        owner, meth = nm.split('$$', 1)
        if meth == 'IncrementAge' and owner.startswith('Sim'):
            sim_inc.append((a, nm))
    sim_inc.sort()
    print(f"  Sim*$$IncrementAge methods found: {len(sim_inc)}")

    # Methods owned by the classes we expand one hop into.
    EXPAND_OWNERS = ('Sim', 'SocialMediaUtility', 'PersonGenerator', 'DataHub', 'GameReference')

    def expandable(nm):
        if not nm or '$$' not in nm:
            return False
        owner = nm.split('$$', 1)[0]
        return owner.startswith(EXPAND_OWNERS)

    unity_hits = []
    scope_b_methods = set()
    scanned = 0

    for a, nm in sim_inc:
        bounds = method_bounds(a)
        if not bounds:
            continue
        start, end = bounds
        scanned += 1
        # scope A: direct calls in this body
        for site, tgt, kind, raw, ven in resolve_calls(start, end):
            if kind == 'BLX-reg':
                continue
            tn = method_name(tgt) or ''
            if tn.startswith('UnityEngine'):
                unity_hits.append({
                    'scope': 'A-direct', 'from': nm, 'from_rva': hex(a),
                    'site': hex(site), 'to': tn, 'to_rva': hex(tgt),
                })
        # scope B: one hop into expandable callees
        for site, tgt, kind, raw, ven in resolve_calls(start, end):
            if kind == 'BLX-reg':
                continue
            tn = method_name(tgt) or ''
            if not expandable(tn):
                continue
            if tgt in scope_b_methods:
                continue
            scope_b_methods.add(tgt)
            b2 = method_bounds(tgt)
            if not b2:
                continue
            s2, e2 = b2
            for site2, tgt2, kind2, raw2, ven2 in resolve_calls(s2, e2):
                if kind2 == 'BLX-reg':
                    continue
                tn2 = method_name(tgt2) or ''
                if tn2.startswith('UnityEngine'):
                    unity_hits.append({
                        'scope': 'B-one-hop', 'from': tn, 'from_rva': hex(tgt),
                        'site': hex(site2), 'to': tn2, 'to_rva': hex(tgt2),
                        'reached_from': nm,
                    })

    print(f"  bodies scanned: {scanned}; one-hop helper bodies scanned: {len(scope_b_methods)}")
    print(f"  UnityEngine hits: {len(unity_hits)}")
    for h in unity_hits[:60]:
        print(f"    [{h['scope']}] {h['from']} @0x{h['from_rva']} -> {h['to']} @0x{h['to_rva']}"
              + (f"  (via {h['reached_from']})" if h.get('reached_from') else ''))
    return {'sim_increment_age_count': len(sim_inc), 'bodies_scanned': scanned,
            'helper_bodies_scanned': len(scope_b_methods), 'unity_hits': unity_hits}


def main():
    r1 = q1()
    r2 = q2()
    r3 = q3()
    out = {'q1_wrapper_bounds': r1, 'q2_cctor_seeding': r2, 'q3_unityengine_reachability': r3}
    dest = os.path.join(ROOT_DIR, 'out', 'reverse-engineering', 'rng_q123_probe.json')
    os.makedirs(os.path.dirname(dest), exist_ok=True)
    with open(dest, 'w', encoding='utf-8') as fh:
        json.dump(out, fh, indent=2)
    print(f"\n[out] wrote {dest}")


if __name__ == '__main__':
    main()

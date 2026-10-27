# BitLife 3.25.3 — RNG routing & seeding (byte-level ARM evidence)

Source binary: work/native/libil2cpp.so (sha256 b69f574ebda69be3670e50c2c6f3f13600bce1725b30cf51602c369f5c4eac6e, ELF32 ARM)
Metadata pair: work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat (sha256 11f00a16..., v39)
Method names resolved from out/il2cpp/script.json via tools/disasm2.py (capstone ARM).

## 1. Seeding — both .cctor create `new Random()` (parameterless)

### DataHub..cctor @ RVA 0x18B0B30

```
018b0cc4  bl       #0x100f660      ; il2cpp_object_new(System.Random)
018b0cc8  mov      r1, #0          ; MethodInfo slot = 0
018b0ccc  mov      r4, r0          ; r4 = new object
018b0cd0  bl       #0x20b89a4      ; veneer -> System.Random$$.ctor() @ 0x047E0BA4
018b0cec  str      r4, [r1, #0xa74] ; DataHub+0xA74 = getrandom  <-- STORE
```

Veneer decode (0x20B89A4): movw ip,#0x81f0 ; movt ip,#0x272 ; add ip,ip,pc ; bx ip
  -> 0x027281F0 + (0x020B89AC+8) = 0x047E0BA4 = System.Random$$.ctor (parameterless)

Also in DataHub..cctor:
```
018b0d24  bl       #0x20ba1d0      ; veneer -> System.Text.RegularExpressions.Regex$$.ctor
018b0d20  str      r4, [r1, #0xa78] ; DataHub+0xA78 = Regex field
018b0d54  str      r4, [r1, #0xa7c] ; DataHub+0xA7C = another object
018b0da8  bl       #0x1102afc      ; veneer -> Dictionary<object,object>$$Add
```

### GameReference..cctor @ RVA 0x1F7F5D8

```
01f7f68c  bl       #0x100f660      ; il2cpp_object_new(List<object>)
01f7f6a4  bl       #0x20b88f0      ; veneer -> List<object>$$.ctor @ 0x04189548
01f7f6b4-01f7f788: list population via veneer 0x10D85E8 -> List<object>$$AddWithResize
01f7f7a0  strd     r6, r7, [r1, #4] ; GameReference+0x4 = ImpactFilterList, +0x8 = AdditionalStackFrames
01f7f7a8  bl       #0x100f660      ; il2cpp_object_new(System.Random)
01f7f7ac  mov      r1, #0          ; MethodInfo slot = 0
01f7f7b0  mov      r4, r0          ; r4 = new object
01f7f7b4  bl       #0x20b89a4      ; veneer -> System.Random$$.ctor() @ 0x047E0BA4  (SAME veneer)
01f7f7dc  strd     r4, r5, [r0, #0xc] ; GameReference+0xC = getrandom, +0x10 = LETTERS
```

Veneer 0x20B88F0 -> 0x04189548 = System.Collections.Generic.List<object>$$.ctor
Veneer 0x10D85E8 -> 0x04189D54 = System.Collections.Generic.List<object>$$AddWithResize

## 2. System.Random..ctor() (parameterless) @ 0x047E0BA4

```
047e0bf0  bl       #0x47e0c10      ; System.Random$$GenerateSeed
047e0bf4  mov      r1, r0          ; r1 = seed
047e0bf8  mov      r0, r4          ; r0 = this
047e0bfc  pop      {r4, r5, fp, lr}
047e0c00  b        #0x47e0dfc      ; tail-call System.Random$$.ctor(int seed)
```

Standard .NET pattern: `Random() : this(GenerateSeed())`.

## 3. System.Random..ctor(int seed) @ 0x047E0DFC

```
047e0e40  ldr      r0, [pc, #0x210]
047e0e44  mov      r1, #0x38       ; 56 bytes = int[14]
047e0e50  bl       #0x3088798      ; allocate int[14]
047e0e54  str      r0, [sb, #0x10] ; this+0x10 = SeedArray (int[14])
```

Standard .NET Random(int seed): allocates 56-byte int[14] seed array at this+0x10.

## 4. System.Random.GenerateSeed() @ 0x047E0C10

```
047e0cc0  bl       #0x483e0f4      ; veneer -> System.Threading.Monitor$$Enter
047e0cf0  ldr      r0, [r5]        ; r0 = object->klass
047e0cf4  ldrd     r2, r3, [r0, #0xe8] ; vtable entry at klass+0xE8
047e0d00  blx      r2              ; virtual call (time-based seed source)
047e0d28  bl       #0x48416b8      ; veneer -> System.Threading.Monitor$$Exit
```

GenerateSeed is thread-safe (Monitor.Enter/Exit) and calls a virtual method at vtable
offset 0xE8 on a runtime object. This is consistent with a time-based seed
(Environment.TickCount / DateTime.Now), not a fixed seed. Exact source object and
vtable index require Il2CppClass layout resolution; seed VALUE is runtime-dependent
and cannot be recovered statically.

## 5. DataHub.GetRandomNumber(int min, int max) @ 0x15C4E50

```
015c4e50  push     {r4, r5, r6, r7, r8, lr}
015c4e5c  mov      r5, r0          ; r5 = min
015c4e60  mov      r8, r1          ; r8 = max
015c4e9c  ldr      r0, [r7]        ; DataHub Il2CppClass*
015c4ea0  ldr      r1, [r0, #0x74] ; cctor_finished check
015c4eb4  ldr      r0, [r0, #0x5c] ; static_fields
015c4ec8  ldr      r0, [r0, #0xa74] ; r0 = DataHub.getrandom
015c4edc  bl       #0x11009ec      ; veneer -> System.Threading.Monitor$$Enter
015c4efc  ldr      r7, [r0, #0xa74] ; r7 = DataHub.getrandom
015c4f0c  ldr      r0, [r7]        ; r0 = getrandom->klass
015c4f10  ldr      r4, [r0, #0xf0] ; vtable method at klass+0xF0
015c4f14  ldr      r3, [r0, #0xf4] ; MethodInfo
015c4f18  mov      r0, r7          ; this
015c4f1c  mov      r1, r5          ; min
015c4f20  mov      r2, r8          ; max
015c4f24  blx      r4              ; VIRTUAL CALL = Random.Next(min, max)
015c4f48  bl       #0x10d8658      ; veneer -> System.Threading.Monitor$$Exit
015c4f5c  mov      r0, r5          ; return result
015c4f64  pop      {r4, r5, r6, r7, r8, pc}
```

Veneer 0x11009EC -> 0x0483E0F4 = System.Threading.Monitor$$Enter
Veneer 0x10D8658 -> 0x048416B8 = System.Threading.Monitor$$Exit

Routing: DataHub.getrandom (static System.Random @ DataHub+0xA74) -> Next(min, max).
Thread-safe: Monitor.Enter/Exit wraps the draw.

## 6. GameReference.GetRandomNumber(int min, int max) @ 0x1F6E348

```
01f6e348  push     {r4, r5, r6, r7, r8, sl, fp, lr}
01f6e354  mov      r8, r0          ; r8 = min
01f6e358  mov      r4, r1          ; r4 = max
01f6e384  cmp      r4, #1
01f6e38c  movle    r4, #1          ; if (max <= 1) max = 1   <-- CLAMP
01f6e3c8  ldr      r0, [r0, #0xc]  ; r0 = GameReference.getrandom
01f6e3dc  bl       #0x11009ec      ; veneer -> Monitor$$Enter
01f6e3fc  ldr      r7, [r0, #0xc]  ; r7 = GameReference.getrandom
01f6e40c  ldr      r0, [r7]        ; klass
01f6e410  ldrd     sl, fp, [r0, #0xf0] ; vtable method + MethodInfo at klass+0xF0
01f6e414  mov      r0, r7          ; this
01f6e418  mov      r1, r8          ; min
01f6e41c  mov      r2, r4          ; max (clamped)
01f6e420  mov      r3, fp          ; MethodInfo
01f6e424  blx      sl              ; VIRTUAL CALL = Random.Next(min, max)
01f6e448  bl       #0x10d8658      ; veneer -> Monitor$$Exit
01f6e45c  mov      r0, r5          ; return result
01f6e464  pop      {r4, r5, r6, r7, r8, sl, fp, pc}
```

Routing: GameReference.getrandom (static System.Random @ GameReference+0xC) -> Next(min, max).
Pre-clamp: `if (max <= 1) max = 1` before the call.
Thread-safe: Monitor.Enter/Exit wraps the draw.

## 7. Bound semantics

Both wrappers call the SAME virtual method at vtable offset 0xF0 with (this, min, max).
The only System.Random virtual method matching (this, int, int) -> int is
Next(int minValue, int maxValue). .NET semantics:

```
range = (long)max - min
if (range <= int.MaxValue) return (int)(Sample() * range) + min
```

Sample() returns [0,1), so result is in [min, max) — max is EXCLUSIVE.
Each call consumes one InternalSample() draw (via Sample()).

### 6b. Next(int,int) body @ 0x047E11D0 — the exact executed expression

The bound inference above is confirmed by disassembling the method itself
(`tools/disasm2.py 0x047E11D0 0x170`):

```
047e11d8  cmp      r1, r2              ; minValue vs maxValue
047e11dc  bgt      #0x47e128c          ; min > max -> throw
047e11e0  mov      r4, r1              ; r4 = minValue
047e11e8  subs     r6, r2, r4          ; r6:r5 = (long)(maxValue - minValue)
047e11f0  mvn      r1, #0x80000000     ; r1 = 0x7FFFFFFF (MBIG)
047e11f4  subs     r1, r1, r6          ; MBIG - diff
047e11fc  bge      #0x47e1238          ; diff <= MBIG -> small-range path
047e1200  bl       #0x47e1180          ; else GetSampleForLargeRange()
...
047e1238  ldr      r1, [r0]            ; klass -> vtable
047e123c  ldrd     r2, r3, [r1, #0xe0] ; Sample() at vtable+0xE0
047e1244  blx      r2                  ; Sample() -> double in d17
047e1258  bl       #0x3088d20          ; (long)diff -> double in d16
047e1264  vmul.f64 d16, d17, d16       ; d16 = Sample() * (double)diff
047e126c  vcvt.s32.f64 s0, d16         ; (int)d16
047e1280  add      r0, r0, r4          ; += minValue
```

Executed expression:

```
(int)(Sample() * (double)diff) + minValue
```

with `Sample() = InternalSample() * (1.0 / MBIG)` (the virtual method at
vtable+0xE0). Truncation is `vcvt.s32.f64` toward zero on a non-negative product,
which is what makes max EXCLUSIVE.

Both ports (`web/src/rng.ts` and `clone/monorandom.py`) use this exact expression.
The earlier pre-dividing form `Math.floor(sample * (diff / MBIG))` is empirically
interchangeable — 700k random triples across the full int32 range show zero
divergence — but the native form is used so the port sits on what the game executes.
Full audit: `docs/RNG_DIVERGENCE.md`.

`diff > Int32.MaxValue` branches to `GetSampleForLargeRange()` @ 0x047E1180, a
rejection loop returning a `long`. No BitLife call site needs it, so both ports
raise rather than guess.

## 8. Annual path routing — IncrementAgeSimulation

Verified with `tools/callgraph.py` (direct BL/BLX target extraction + script.json name
resolution) against `work/native/libil2cpp.so`.

Method boundaries from `out/il2cpp/method_by_address.json`:
- `Life.IncrementAge`          @ 0x02575DF4 (wrapper)
- `Life.IncrementAgeSimulation` @ 0x02575E18 .. 0x0257B1AC (0x5394 bytes)
- `Life.IncrementAgeUI`         @ 0x0257B1AC .. 0x0257B25C

`Life.IncrementAge` makes only three ordered calls:
```
0x02575DFC  BL Life$$IncrementAgeSimulation
0x02575E04  BL Life$$IncrementAgeUI
0x02575E14  BL Genesis.Controllers.GenesisMemory$$IncrementAge
```

`Life.IncrementAgeSimulation` (1592 direct calls) contains exactly ONE RNG call-site:
```
0x0257AB20  BL 0x01F6E348  GameReference$$GetRandomNumber
```
and exactly ONE UnityEngine call-site:
```
0x0257AD30  BL 0x038EBA00  UnityEngine.Events.UnityEvent<int>$$Invoke
```
`UnityEvent<int>.Invoke` is an event dispatch, NOT `UnityEngine.Random`.

CONCLUSION: The annual simulation path calls `GameReference.GetRandomNumber`
(System.Random via GameReference.getrandom @ +0xC). It does NOT call
`UnityEngine.Random.Range` or any other UnityEngine.Random API directly.
`DataHub.GetRandomNumber` is not called directly from IncrementAgeSimulation;
it is reached from deeper helpers (scenario selection, content rolls) that this
batch did not trace.

Artifacts:
- out/reverse-engineering/callgraph_increment_age_3253.txt
- out/reverse-engineering/callgraph_increment_age_simulation_3253.txt
- out/reverse-engineering/callgraph_increment_age_ui_3253.txt
- tools/callgraph.py

## 9. UnityEngine.Random in the annual path

PROVEN NEGATIVE for the direct annual path. `UnityEngine.Random.Range` exists as a
separate API (method_by_address.json: 0x05047DB8, 0x05047E0C) but `tools/callgraph.py`
found NO call to any UnityEngine.Random method inside `Life.IncrementAge`,
`Life.IncrementAgeSimulation`, or `Life.IncrementAgeUI`. The only UnityEngine call in
the annual simulation is `UnityEvent<int>.Invoke` (event dispatch, not RNG).

The annual RNG is `System.Random`:
- `GameReference.GetRandomNumber` (GameReference.getrandom @ +0xC) is called directly
  from `Life.IncrementAgeSimulation` at 0x0257AB20.
- `DataHub.GetRandomNumber` (DataHub.getrandom @ +0xA74) is not called directly from
  the annual entry points; it is reached from deeper helpers (scenario/content rolls)
  not traced in this batch.

## 9. Ghidra pseudo-C limitation

out/ghidra/rng_3253.c contains Ghidra decompiler output for the same four targets.
The two GetRandomNumber bodies have real boundaries but unresolved FUN_*/DAT_*
references and untyped registers, so the pseudo-C is NOT usable as semantic proof.
The two .cctor targets were single-point stubs in the existing Ghidra project
(auto-analysis never created bodies), so their pseudo-C is meaningless.
The byte-level disassembly above is the authoritative evidence.

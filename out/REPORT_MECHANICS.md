# BitLife 3.25.3 — mechanics recovered from `libil2cpp.so`

Everything here was read off ARM disassembly with `tools/disasm2.py` (method names
resolved through `out/il2cpp/script.json`). Addresses are file RVAs; the library is
plain ARM (not Thumb), so PC-relative pool words resolve with `PC = insn + 8`.

Only methods that a port actually needs are covered. Coverage is deliberate, not
exhaustive: the game has 236 419 named methods and none of the remaining ones block a
faithful rebuild the way stat math and RNG do.

---

## 1. RNG — `DataHub.GetRandomNumber(int min, int max)` @ `0x15C4E50`

```
DataHub.getrandom  (static readonly System.Random, DataHub+0xA74)
  -> vtable[0xF0]  ==  System.Random.Next(int, int)
  -> return
```

It is **`System.Random`**, not `UnityEngine.Random`. One static instance for the whole
process, created in `DataHub..cctor` (`0x18B0B30`) with no explicit seed, so the seed
is `Environment.TickCount` and every fresh launch differs.

Consequence for the port: `Math.random()` is *not* a substitute — `System.Random`'s
consumption pattern differs and any seeded reproducibility work (daily challenges,
replay, save/restore) has to run the same generator. Port Mono's algorithm verbatim:

```ts
// Mono System.Random — MBIG/MSEED are the runtime constants, Next() is
// InternalSample() % MBIG. Next(min,max) = (int)(Sample() * range) + min.
const MBIG = 2147483647;
const MSEED = 161803398;

export class MonoRandom {
  private readonly seedArray = new Int32Array(56);
  private inext = 0;
  private inextp = 21;

  constructor(seed?: number) {
    const subtraction = seed === undefined ? (Date.now() | 0) : seed === -2147483648 ? MBIG : Math.abs(seed | 0);
    let mj = MSEED - subtraction;
    this.seedArray[55] = mj;
    let mk = 1;
    for (let i = 1; i < 55; i++) {
      const ii = (21 * i) % 55;
      this.seedArray[ii] = mk;
      mk = mj - mk;
      if (mk < 0) mk += MBIG;
      mj = this.seedArray[ii];
    }
    for (let k = 1; k < 5; k++) {
      for (let i = 1; i < 56; i++) {
        this.seedArray[i] -= this.seedArray[1 + ((i + 30) % 55)];
        if (this.seedArray[i] < 0) this.seedArray[i] += MBIG;
      }
    }
  }

  private sample(): number {
    if (++this.inext >= 56) this.inext = 1;
    if (++this.inextp >= 56) this.inextp = 1;
    let ret = this.seedArray[this.inext] - this.seedArray[this.inextp];
    if (ret === MBIG) ret--;
    if (ret < 0) ret += MBIG;
    this.seedArray[this.inext] = ret;
    return ret;
  }

  next(min = 0, max = MBIG): number {
    if (min > max) [min, max] = [max, min];
    const range = max - min;
    return range <= MBIG ? min + Math.floor(this.sample() * (range / MBIG)) : min;
  }

  nextBytes(n: number): Uint8Array {
    const out = new Uint8Array(n);
    for (let i = 0; i < n; i++) out[i] = this.sample() & 0xff;
    return out;
  }
}
```

`nextBytes` returning `sample() & 0xff` is exactly `(byte)Next()`, the same
7-bits-throw-away behaviour Mono has.

## 2. Stat deltas — `GameReference.AttributeAdjustmentPointsForImpactScore(int)` @ `0x1F760A0`

Impact scores from scenario rows are clamped to `[-6, 6]` and mapped through a fixed
13-entry jump table. Table index `0` is not a constant — it loads
`GameReference.<static field>` (metadata-usage slot at `0x5697608`), i.e. a designer
tunable, but every other entry is a literal:

| impact | -6 | -5 | -4 | -3 | -2 | -1 | 0 | +1 | +2 | +3 | +4 | +5 | +6 |
|---|---|---|---|---|---|---|---|---|---|---|---|---|---|
| points | -100 | -50 | -30 | -16 | -8 | -4 | tunable | +4 | +8 | +16 | +30 | +50 | +100 |

`impact < -6` behaves as `-6`, `impact > 6` as `+6` (`cmp r4,#6 / movge`;
`cmn r4,#6 / mvnle`).

## 3. Applying a delta — `SimPerson.ImpactHappiness(int)` @ `0x1D10A3C`

`ImpactHealth`, `ImpactLooks`, `ImpactSmarts` (`0x1D10B48` and siblings) are the same
function with a different backing field at `+0x60`. Verbatim behaviour:

```ts
// SimPerson.ImpactHappiness(int impactScore)
if (impactScore <= 0 && this.age <= 4) return;      // +0x14 is Age: kids take no decay
this.happiness = clamp(this.happiness + AttributeAdjustmentPointsForImpactScore(impactScore), 0, 100);
GameReference.SimVampire.PersonAttributeImpacted(this, 0);
if (this.vampireMirror != null)                     // +0x17C
  this.vampireMirror.happiness = this.happiness;    // mirror field also at +0x60
```

Points worth keeping:

- Stat fields are **float 0..100**, clamped on every write, not ints.
- Positive impacts always land; negative impacts are dropped for age ≤ 4.
- The clamp is `if (v >= 100) v = 100; else if (v <= 0) v = 0;` — read as `>=`/`<=`,
  so 100 and 0 are both reachable and both sticky at the boundary.
- A paired "vampire" object carries a mirrored copy of the same field.

## 4. `Life.IncrementAge()` @ `0x2575DF4`

```
IncrementAgeSimulation()          // 0x2575E18 — all sim-side yearly work
IncrementAgeUI()                  // 0x257B1AC — UI refresh
Genesis.Controllers.GenesisMemory.IncrementAge(this[0x2DC], 0)
```

Three ordered phases: sim, UI, memory. `IncrementAgeSimulation` is ~0x5300 bytes and
sequences: age++, stat drift, occupation/school check, disease/addiction roll,
relationship tick, then scenario selection. Port order matters — the UI phase reads
state the sim phase already mutated, and the memory phase snapshots it.

`IncrementAgeScenariosInProgress` (backing field `+0x10`) gates re-entry while the
increment scenario queue (`IncrementAgeScenarioQueueArray`, `+0xC`, `List<Scenario>`)
drains.

## 5. Stat identity — `enum StatType` (TypeDefIndex 6219)

Value type is 32-bit and the members are **powers of two**, i.e. a bitmask:

```
None=0 Happiness=1 Health=2 Smarts=4 Looks=8 Essence=16 Fame=32 Reputation=64
Infamy=128 StreetSmarts=256 Performance=512 Greatness=1024 Popularity=2048
Approval=4096 Charisma=8192 Respect=16384
```

Do not model `StatType` as a plain ordinal in the port — `1 << n` or a TS enum with
those exact values, and let call sites OR them.

## 6. Scenario loading — legacy vs designer

`Scenario.LoadLegacyFormat(ScenarioCSVData, string)` (`0x...`, see dump.cs
TypeDefIndex 4793 region) parses the 30-column legacy schema
(`IsEntryPoint, EntryNarrative, ChoiceList, ActionList, IntValue, StringValue,
ChoiceScenarioID, DropDownList, …`). `LoadDesignerFormat` expects the 54-column
`DesignerCSVHeaders` schema. Both end in `ParseDesignerBluePrintPayload` /
`CreateDesignerScenarioCondition` for the advanced-logic column.

The shipped asset pack holds designer-format rows (`out/decrypted/a16_*-scenarios.csv`,
5-column compact form) while the 28 loose `\x00IAP` containers hold legacy-format rows
with full action lists — see `out/REPORT_LOOSE_CONTAINERS.md`.

## 7. Save format

Save payloads are OPS.Serialization blobs: `Serializer.Serialize(object, compress,
encrypt, key)` (`0x25E0770`) → `CompressionHelper.Compress` (`0x25DA98C`) →
`SecurityHelper.Encrypt(byte[], string)` (`0x25DA948`). The cipher:

```
SecurityHelper.Cryption(byte[] data, byte[] key)        @ 0x25DA620
  stride = 10 ^ Random.Range(0, (int)Math.Log(data.Length) - 2)
  keyIdx = 0
  for (i = 0; i < data.Length; i += stride):
      data[i] ^= key[keyIdx]
      keyIdx = keyIdx == 3 ? 0 : keyIdx + 1
```

Only every `stride`-th byte is transformed, so the cipher is deliberately weak — an
interoperable port can read and write real saves from it once the key string is known.
`stride` depends on the payload length, so it is recomputed per blob, and because it
comes from the shared `System.Random` a save round-trip re-draws it.

---

## What is still open

- `Life.IncrementAgeSimulation` body (~0x5300 bytes) — the yearly sequencing order is
  identified but not transcribed; decompile per-breakpoint rather than reading it whole.
- `AttributeAdjustmentPointsForImpactScore` index 0 (designer tunable, currently a
  metadata slot rather than a literal — resolve at runtime or read the slot's initialiser).
- The `RandomDeckCollection` weighting used by `ValidateAndSetScenario` (`0x2575954`).
- `Genesis.*` blueprints — the condition/dependency graph behind modern scenarios.

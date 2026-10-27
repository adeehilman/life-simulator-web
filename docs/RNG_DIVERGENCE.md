# RNG divergence audit — TS vs .NET `Next(min,max)`

Question: does `web/src/rng.ts` `next(min,max)` match the expression BitLife's
native binary actually executes?

## The native expression (authoritative)

`System.Random$$Next(int,int)` @ `0x047E11D0` in `work/native/libil2cpp.so`
(3.25.3, sha256 `b69f574e…`), disassembled with `tools/disasm2.py`:

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

So the executed expression is:

```
(int)(Sample() * (double)diff) + minValue
```

with `Sample() = InternalSample() * (1.0 / MBIG)`.

Max is **exclusive** (.NET semantics), confirmed by the `vcvt.s32.f64`
truncation toward zero on a non-negative product.

## The three candidate forms

| Form | Expression | Where |
|---|---|---|
| native | `(int)(sample * (1.0/MBIG) * diff) + min` | the binary |
| pre-divide | `Math.floor(sample * (diff / MBIG)) + min` | `web/src/rng.ts` (old) |
| post-divide | `(int)(sample * diff / MBIG) + min` | `clone/monorandom.py` (old) |

The native form multiplies by `1/MBIG` first, then by `diff`. The pre-divide form
folds `diff / MBIG` into one constant first. Those are not the same IEEE-754
expression, so a one-ULP difference could in principle shift a truncation boundary.

## Method

`clone/fixture_check.py` (run: `python clone/fixture_check.py`) draws random
`(sample, diff, min)` triples and compares the forms.

## Result

```
diff in 1..4999, min in -1000..999   : checked=200000  mismatches=0
diff in 1..MBIG, min full int32 range: checked=500000  mismatches=0
```

No divergence observed at any sampled triple. For `diff <= MBIG` the three forms
agree, so the previous TS/Python implementations were already correct.

## Decision

Both implementations were switched to the **native** form anyway
(`sample * (1/MBIG) * diff`, truncated), so the port sits on the exact expression
the game executes rather than on an empirically-equivalent substitute. If a future
fixture ever disagrees, this is the first thing to re-check with the exact
`(sample, diff, min)` triple from the failing case.

## Unimplemented: large ranges

`diff > Int32.MaxValue` takes the `GetSampleForLargeRange()` path @ `0x047E1180`,
which is a rejection loop returning a `long`. No BitLife call site needs it —
`GameReference.GetRandomNumber` clamps `max <= 1 -> 1` and every consumer passes
small ranges — so both ports raise rather than guess.

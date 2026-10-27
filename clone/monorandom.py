"""Mono/.NET `System.Random`, ported from the reference implementation.

Ground truth is the .NET Framework `System.Random` source (mscorlib), which is what
BitLife's IL2CPP build links against. The TypeScript port in `web/src/rng.ts` is the
project's baseline; this module exists so the two can be diffed against each other
and against native fixtures.

Divergences worth knowing about before you trust a comparison:

* .NET computes `Next(min,max)` as `(int)(Sample() * (double)diff / MBIG) + min`.
  `web/src/rng.ts` computes `Math.floor(sample * (range / MBIG))`. Those are NOT
  bit-identical in floating point — the TS form pre-divides, the .NET form divides
  last. `next()` here follows .NET. See `docs/RNG_DIVERGENCE.md`.
* .NET `Next()` (no args) returns `InternalSample()` directly, i.e. 0..MBIG.
* .NET `NextDouble()` returns `Sample() * (1.0 / MBIG)`.
* `NextBytes` writes one `(byte)InternalSample()` per byte.
* `seedArray` is a plain `int[]` in .NET; arithmetic is unchecked, so values stay in
  0..MBIG by construction of the algorithm (the `if (<0) += MBIG` clamps). Python
  ints are unbounded, so no masking is needed and none is applied — that is what
  makes this a faithful port rather than a re-implementation.

Reference: out/REPORT_RNG_3253.md (byte-level native evidence for seeding and
`Next(min,max)` semantics in BitLife 3.25.3).
"""

from __future__ import annotations

MBIG = 2147483647  # Int32.MaxValue
MSEED = 161803398  # the golden-ratio-ish constant .NET uses

INT32_MIN = -2147483648
UINT32_MOD = 4294967296


def _i32(value: int) -> int:
    """Emulate .NET unchecked `int` arithmetic: wrap to signed 32-bit.

    Python ints are unbounded, so without this the constructor diverges from .NET
    for large seeds. `mk = mj - mk` can drop below Int32.MinValue, and a single
    `if (mk < 0) mk += MBIG` clamp is then not enough — .NET's wrap does the work
    instead. Verified against the TypeScript port (which uses Int32Array) and
    against a .NET reference model in clone/debug_divergence.mjs.
    """
    v = value & 0xFFFFFFFF
    return v - UINT32_MOD if v >= 0x80000000 else v


class MonoRandom:
    """A faithful port of .NET Framework `System.Random`."""

    __slots__ = ("seed_array", "inext", "inextp", "draw_count")

    def __init__(self, seed: int | None = None) -> None:
        if seed is None:
            import time

            seed = int(time.time() * 1000) & 0xFFFFFFFF
            # .NET's default ctor uses an environment-derived seed; time-based is
            # the closest portable approximation and is NOT deterministic.
        subtraction = MBIG if seed == -2147483648 else abs(seed)

        self.seed_array = [0] * 56
        self.inext = 0
        self.inextp = 21
        self.draw_count = 0

        mj = _i32(MSEED - subtraction)
        self.seed_array[55] = mj
        mk = 1
        for i in range(1, 55):
            ii = (21 * i) % 55
            self.seed_array[ii] = mk
            mk = _i32(mj - mk)
            if mk < 0:
                mk = _i32(mk + MBIG)
            mj = self.seed_array[ii]
        for _ in range(1, 5):
            for i in range(1, 56):
                self.seed_array[i] = _i32(self.seed_array[i] - self.seed_array[1 + ((i + 30) % 55)])
                if self.seed_array[i] < 0:
                    self.seed_array[i] = _i32(self.seed_array[i] + MBIG)

    # ------------------------------------------------------------------ state

    def snapshot(self) -> dict:
        return {
            "seedArray": list(self.seed_array),
            "inext": self.inext,
            "inextp": self.inextp,
            "drawCount": self.draw_count,
        }

    def restore(self, snap: dict) -> None:
        if len(snap["seedArray"]) != 56:
            raise ValueError("Invalid MonoRandom snapshot length")
        if not (0 <= snap["inext"] < 56) or not (0 <= snap["inextp"] < 56):
            raise ValueError("Invalid MonoRandom snapshot indices")
        self.seed_array = list(snap["seedArray"])
        self.inext = snap["inext"]
        self.inextp = snap["inextp"]
        self.draw_count = snap.get("drawCount", 0)

    # ------------------------------------------------------------------ draws

    def internal_sample(self) -> int:
        """InternalSample(): the raw MBIG-bounded draw. One draw per call."""
        loc_inext = self.inext
        loc_inextp = self.inextp

        loc_inext += 1
        if loc_inext >= 56:
            loc_inext = 1
        loc_inextp += 1
        if loc_inextp >= 56:
            loc_inextp = 1

        ret = _i32(self.seed_array[loc_inext] - self.seed_array[loc_inextp])
        if ret == MBIG:
            ret -= 1
        if ret < 0:
            ret = _i32(ret + MBIG)

        self.seed_array[loc_inext] = ret
        self.inext = loc_inext
        self.inextp = loc_inextp
        self.draw_count += 1
        return ret

    # .NET's public surface, in the order it appears in the reference source.

    def next_double(self) -> float:
        """Random.NextDouble() — [0,1)."""
        return self.internal_sample() * (1.0 / MBIG)

    def next_int(self) -> int:
        """Random.Next() — 0..MBIG inclusive."""
        return self.internal_sample()

    def next(self, min_value: int = 0, max_value: int = MBIG) -> int:
        """Random.Next(min,max) — min inclusive, max EXCLUSIVE.

        Expression taken verbatim from the BitLife 3.25.3 native binary,
        `System.Random$$Next(int,int)` @ `0x047E11D0` (see out/REPORT_RNG_3253.md
        §6b for the disassembly):

            blx r2                  ; Sample()  -> double in d17
            bl  0x3088d20           ; (long)diff -> double in d16
            vmul.f64 d16, d17, d16  ; d16 = Sample() * (double)diff
            vcvt.s32.f64 s0, d16    ; (int)d16
            add r0, r0, r4          ; += minValue

        i.e. `(int)(Sample() * (double)diff) + minValue`, where
        `Sample() = InternalSample() * (1.0 / MBIG)`.

        Empirically this is interchangeable with the pre-dividing form
        `Math.floor(sample * (diff / MBIG))` used by web/src/rng.ts — 500k random
        triples across the full int32 range show zero divergence (see
        docs/RNG_DIVERGENCE.md). The native form is used here anyway so the clone
        sits on the exact expression the game executes.

        Raises when min > max, like .NET does.
        """
        if min_value > max_value:
            raise ValueError("min_value must be <= max_value")
        diff = max_value - min_value
        if diff <= MBIG:
            return int(self.internal_sample() * (1.0 / MBIG) * diff) + min_value
        raise NotImplementedError(
            "Random.Next(min,max) with diff > Int32.MaxValue uses "
            "GetSampleForLargeRange(); no BitLife call site needs it "
            "(out/REPORT_RNG_3253.md §6b)"
        )

    def next_bytes(self, count: int) -> bytes:
        """Random.NextBytes() — one low byte per draw, exactly `(byte)Next()`."""
        return bytes(self.internal_sample() & 0xFF for _ in range(count))

    # ------------------------------------------------- convenience (not .NET)

    def range(self, min_value: int, max_value: int) -> int:
        """`min + Next() % (max-min)`, the shape many BitLife call sites use.

        NOTE: this is NOT .NET `Next(min,max)`. It is the modulo form. BitLife's
        `GameReference.GetRandomNumber` is the exclusive-max `Next(min,max)` form
        (see out/REPORT_RNG_3253.md §6), so prefer `next()` for parity work.
        """
        if max_value <= min_value:
            return min_value
        return min_value + (self.internal_sample() % (max_value - min_value))

    def pick(self, items):
        if not items:
            return None
        return items[self.next(0, len(items))]

    def chance(self, p: float) -> bool:
        return self.next_double() < p

    def __repr__(self) -> str:  # pragma: no cover - debugging aid
        return f"MonoRandom(inext={self.inext}, inextp={self.inextp}, draws={self.draw_count})"

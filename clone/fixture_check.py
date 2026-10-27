"""Regenerate the RNG divergence audit numbers quoted in docs/RNG_DIVERGENCE.md.

Run:  python clone/fixture_check.py
"""

from __future__ import annotations

import random
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from monorandom import MBIG  # noqa: E402


def native(sample: int, diff: int, min_v: int) -> int:
    """System.Random$$Next(int,int) @ 0x047E11D0: (int)(Sample() * (double)diff) + min."""
    return int(sample * (1.0 / MBIG) * diff) + min_v


def pre_divide(sample: int, diff: int, min_v: int) -> int:
    """web/src/rng.ts (old): Math.floor(sample * (range / MBIG)) + min."""
    return min_v + int(sample * (diff / MBIG))


def post_divide(sample: int, diff: int, min_v: int) -> int:
    """clone/monorandom.py (old): (int)(sample * diff / MBIG) + min."""
    return int(sample * diff / MBIG) + min_v


def sweep(seed: int, n: int, diff_hi: int, min_lo: int, min_hi: int) -> tuple[int, int, int, int]:
    rng = random.Random(seed)
    checked = 0
    m_np = m_nd = m_pd = 0
    for _ in range(n):
        s = rng.randrange(0, MBIG + 1)
        diff = rng.randrange(1, diff_hi + 1)
        min_v = rng.randrange(min_lo, min_hi)
        checked += 1
        a, b, c = native(s, diff, min_v), pre_divide(s, diff, min_v), post_divide(s, diff, min_v)
        if a != b:
            m_np += 1
        if a != c:
            m_nd += 1
        if b != c:
            m_pd += 1
    return checked, m_np, m_nd, m_pd


def main() -> int:
    # BitLife-shaped ranges, then the full int32 envelope.
    for label, seed, n, diff_hi, lo, hi in [
        ("diff in 1..4999, min in -1000..999   ", 12345, 200_000, 4999, -1000, 1000),
        ("diff in 1..MBIG, min full int32 range", 4242, 500_000, MBIG, -2147483648, 2147483647),
    ]:
        checked, m_np, m_nd, m_pd = sweep(seed, n, diff_hi, lo, hi)
        print(
            f"{label}: checked={checked}  "
            f"native_vs_pre={m_np}  native_vs_post={m_nd}  pre_vs_post={m_pd}"
        )
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

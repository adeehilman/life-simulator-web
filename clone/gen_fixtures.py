"""Deterministic RNG fixtures for BitLife 3.25.3 parity.

These vectors are the contract between `web/src/rng.ts` (TypeScript) and
`clone/monorandom.py` (Python). Both implementations must produce identical output
for every entry, or parity is broken.

Fixtures are generated, not hand-written: `python clone/gen_fixtures.py` writes
`clone/fixtures/rng_vectors.json`. `clone/test_monorandom.py` asserts against it.

Why fixtures instead of shared test code: the two implementations live in different
languages and different build pipelines (Vitest vs plain Python). A JSON vector file
is the only artifact both can read without a bridge.
"""

from __future__ import annotations

import json
import sys
from pathlib import Path

sys.path.insert(0, str(Path(__file__).resolve().parent))

from monorandom import MBIG, MonoRandom  # noqa: E402

OUT = Path(__file__).resolve().parent / "fixtures" / "rng_vectors.json"

# Seeds chosen to cover: the value the web tests already pin, small values, a large
# value, and the Int32.MinValue edge case .NET special-cases.
SEEDS = [1, 42, 123, 7, 999983, -2147483648, 2147483647, -1]

# Operation shapes BitLife actually uses, mapped to the .NET method each mirrors.
#   next_double  -> Random.NextDouble()
#   next_int     -> Random.Next()
#   next         -> Random.Next(min,max)   [min, max)
#   next_bytes   -> Random.NextBytes(n)
#   range        -> modulo form, NOT .NET Next(); kept because call sites use it
#   chance       -> NextDouble() < p
OPS = [
    {"op": "next_double"},
    {"op": "next_double"},
    {"op": "next_int"},
    {"op": "next", "min": 0, "max": 100},
    {"op": "next", "min": 3, "max": 7},
    {"op": "next", "min": 1, "max": 2},
    {"op": "next", "min": 0, "max": 1},
    {"op": "next", "min": -5, "max": 5},
    {"op": "next_bytes", "count": 8},
    {"op": "range", "min": 0, "max": 10},
    {"op": "chance", "p": 0.5},
    {"op": "pick", "items": ["a", "b", "c", "d"]},
    {"op": "next_double"},
    {"op": "next", "min": 0, "max": 1000000},
]


def apply(rng: MonoRandom, op: dict):
    kind = op["op"]
    if kind == "next_double":
        return rng.next_double()
    if kind == "next_int":
        return rng.next_int()
    if kind == "next":
        return rng.next(op["min"], op["max"])
    if kind == "next_bytes":
        return list(rng.next_bytes(op["count"]))
    if kind == "range":
        return rng.range(op["min"], op["max"])
    if kind == "chance":
        return rng.chance(op["p"])
    if kind == "pick":
        return rng.pick(op["items"])
    raise ValueError(f"unknown op {kind}")


def build() -> dict:
    vectors = []
    for seed in SEEDS:
        rng = MonoRandom(seed)
        results = []
        for op in OPS:
            results.append({"op": op, "value": apply(rng, op)})
        vectors.append(
            {
                "seed": seed,
                "initial": {
                    "inext": 0,
                    "inextp": 21,
                    "seedArray": list(MonoRandom(seed).seed_array),
                },
                "results": results,
                "finalSnapshot": rng.snapshot(),
            }
        )
    return {
        "meta": {
            "generator": "clone/gen_fixtures.py",
            "target": "BitLife 3.25.3 (versionCode 1066, armeabi-v7a)",
            "mbig": MBIG,
            "semantics": {
                "next": "Random.Next(min,max): min inclusive, max EXCLUSIVE",
                "next_double": "Random.NextDouble(): [0,1)",
                "next_int": "Random.Next(): 0..MBIG inclusive",
                "next_bytes": "Random.NextBytes(n): one (byte)InternalSample() per byte",
                "range": "modulo form used by call sites; NOT .NET Next(min,max)",
            },
            "evidence": "out/REPORT_RNG_3253.md",
        },
        "vectors": vectors,
    }


def main() -> int:
    data = build()
    OUT.parent.mkdir(parents=True, exist_ok=True)
    OUT.write_text(json.dumps(data, indent=2) + "\n", encoding="utf-8")
    total = sum(len(v["results"]) for v in data["vectors"])
    print(f"wrote {OUT}  ({len(data['vectors'])} seeds x {len(OPS)} ops = {total} vectors)")
    return 0


if __name__ == "__main__":
    raise SystemExit(main())

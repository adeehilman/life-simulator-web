"""Parity tests for clone/monorandom.py against clone/fixtures/rng_vectors.json.

Run:  python clone/test_monorandom.py
      python -m unittest clone.test_monorandom -v

The fixture is the shared contract with web/src/rng.ts. If a vector fails here, the
Python clone drifted; if the same vector fails in Vitest, the TS port drifted. Either
way parity is broken and must be fixed before any annual-pipeline work is trusted.
"""

from __future__ import annotations

import json
import sys
import unittest
from pathlib import Path

HERE = Path(__file__).resolve().parent
sys.path.insert(0, str(HERE))

from monorandom import MBIG, MonoRandom  # noqa: E402

FIXTURE = HERE / "fixtures" / "rng_vectors.json"


def load_vectors():
    if not FIXTURE.exists():
        raise FileNotFoundError(f"{FIXTURE} missing — run `python clone/gen_fixtures.py` first")
    return json.loads(FIXTURE.read_text(encoding="utf-8"))


class TestAgainstFixture(unittest.TestCase):
    """Every fixture vector must reproduce exactly."""

    @classmethod
    def setUpClass(cls):
        cls.data = load_vectors()

    def test_meta_is_current(self):
        meta = self.data["meta"]
        self.assertEqual(meta["target"], "BitLife 3.25.3 (versionCode 1066, armeabi-v7a)")
        self.assertEqual(meta["mbig"], MBIG)
        self.assertEqual(meta["semantics"]["next"], "Random.Next(min,max): min inclusive, max EXCLUSIVE")

    def test_initial_state_matches_seed(self):
        """seedArray after construction is a pure function of the seed."""
        for v in self.data["vectors"]:
            with self.subTest(seed=v["seed"]):
                rng = MonoRandom(v["seed"])
                self.assertEqual(rng.seed_array, v["initial"]["seedArray"])
                self.assertEqual(rng.inext, v["initial"]["inext"])
                self.assertEqual(rng.inextp, v["initial"]["inextp"])

    def test_vector_results(self):
        for v in self.data["vectors"]:
            with self.subTest(seed=v["seed"]):
                rng = MonoRandom(v["seed"])
                for i, entry in enumerate(v["results"]):
                    op = entry["op"]
                    kind = op["op"]
                    if kind == "next_double":
                        got = rng.next_double()
                    elif kind == "next_int":
                        got = rng.next_int()
                    elif kind == "next":
                        got = rng.next(op["min"], op["max"])
                    elif kind == "next_bytes":
                        got = list(rng.next_bytes(op["count"]))
                    elif kind == "range":
                        got = rng.range(op["min"], op["max"])
                    elif kind == "chance":
                        got = rng.chance(op["p"])
                    elif kind == "pick":
                        got = rng.pick(op["items"])
                    else:
                        self.fail(f"unknown op {kind}")
                    self.assertEqual(
                        got,
                        entry["value"],
                        f"seed={v['seed']} op#{i} {kind} {op} -> got {got!r}, want {entry['value']!r}",
                    )

    def test_final_snapshot(self):
        for v in self.data["vectors"]:
            with self.subTest(seed=v["seed"]):
                rng = MonoRandom(v["seed"])
                for entry in v["results"]:
                    op = entry["op"]
                    kind = op["op"]
                    if kind == "next_double":
                        rng.next_double()
                    elif kind == "next_int":
                        rng.next_int()
                    elif kind == "next":
                        rng.next(op["min"], op["max"])
                    elif kind == "next_bytes":
                        rng.next_bytes(op["count"])
                    elif kind == "range":
                        rng.range(op["min"], op["max"])
                    elif kind == "chance":
                        rng.chance(op["p"])
                    elif kind == "pick":
                        rng.pick(op["items"])
                self.assertEqual(rng.snapshot(), v["finalSnapshot"])


class TestSemantics(unittest.TestCase):
    """The behaviours BitLife's native code depends on."""

    def test_next_max_is_exclusive(self):
        """out/REPORT_RNG_3253.md §6: Random.Next(min,max), max EXCLUSIVE."""
        rng = MonoRandom(123)
        for _ in range(500):
            v = rng.next(3, 7)
            self.assertGreaterEqual(v, 3)
            self.assertLess(v, 7)

    def test_next_single_element_range_returns_min(self):
        rng = MonoRandom(1)
        for _ in range(50):
            self.assertEqual(rng.next(5, 6), 5)

    def test_next_zero_range_returns_min(self):
        rng = MonoRandom(1)
        self.assertEqual(rng.next(9, 9), 9)

    def test_next_rejects_inverted_range(self):
        """.NET throws ArgumentOutOfRangeException; we raise ValueError."""
        rng = MonoRandom(1)
        with self.assertRaises(ValueError):
            rng.next(10, 5)

    def test_next_int_stays_in_mbig_range(self):
        rng = MonoRandom(7)
        for _ in range(500):
            v = rng.next_int()
            self.assertGreaterEqual(v, 0)
            self.assertLessEqual(v, MBIG)

    def test_next_double_is_half_open(self):
        rng = MonoRandom(7)
        for _ in range(500):
            d = rng.next_double()
            self.assertGreaterEqual(d, 0.0)
            self.assertLess(d, 1.0)

    def test_next_bytes_one_draw_per_byte(self):
        """Each byte consumes exactly one InternalSample() — matches .NET."""
        rng = MonoRandom(42)
        before = rng.draw_count
        rng.next_bytes(8)
        self.assertEqual(rng.draw_count - before, 8)

    def test_draw_count_tracks_every_draw(self):
        rng = MonoRandom(1)
        self.assertEqual(rng.draw_count, 0)
        rng.next_double()
        rng.next(0, 10)
        rng.next_int()
        self.assertEqual(rng.draw_count, 3)

    def test_snapshot_restore_roundtrip(self):
        rng = MonoRandom(42)
        rng.next_double()
        snap = rng.snapshot()
        expected = [rng.next_double(), rng.next(0, 100), rng.next_int()]
        rng.restore(snap)
        self.assertEqual([rng.next_double(), rng.next(0, 100), rng.next_int()], expected)

    def test_restore_rejects_bad_snapshot(self):
        rng = MonoRandom(1)
        with self.assertRaises(ValueError):
            rng.restore({"seedArray": [0] * 10, "inext": 0, "inextp": 0})
        with self.assertRaises(ValueError):
            rng.restore({"seedArray": [0] * 56, "inext": 99, "inextp": 0})

    def test_seed_int32_min_is_special_cased(self):
        """.NET maps Int32.MinValue to Int32.MaxValue before abs()."""
        a = MonoRandom(-2147483648)
        b = MonoRandom(2147483647)
        self.assertEqual(a.seed_array, b.seed_array)

    def test_seed_is_abs_of_input(self):
        self.assertEqual(MonoRandom(-42).seed_array, MonoRandom(42).seed_array)

    def test_two_instances_same_seed_are_identical(self):
        """Determinism: same seed, same sequence, always."""
        a, b = MonoRandom(2024), MonoRandom(2024)
        for _ in range(200):
            self.assertEqual(a.next_double(), b.next_double())

    def test_range_is_modulo_not_net_next(self):
        """range() is the call-site modulo form; document that it differs from next()."""
        rng = MonoRandom(1)
        v = rng.range(0, 10)
        self.assertGreaterEqual(v, 0)
        self.assertLess(v, 10)

    def test_range_degenerate_returns_min(self):
        rng = MonoRandom(1)
        self.assertEqual(rng.range(4, 4), 4)
        self.assertEqual(rng.range(4, 2), 4)

    def test_pick_empty_returns_none(self):
        self.assertIsNone(MonoRandom(1).pick([]))

    def test_pick_uses_exclusive_max(self):
        """pick() must use next(0, len) so the last index is reachable."""
        rng = MonoRandom(1)
        seen = set()
        for _ in range(200):
            seen.add(rng.pick(["a", "b", "c", "d"]))
        self.assertEqual(seen, {"a", "b", "c", "d"})


class TestDistribution(unittest.TestCase):
    """Coarse sanity: the generator is uniform, not stuck."""

    def test_uniformity_over_many_draws(self):
        rng = MonoRandom(31337)
        buckets = [0] * 10
        n = 20000
        for _ in range(n):
            buckets[rng.next(0, 10)] += 1
        expected = n / 10
        for b in buckets:
            self.assertAlmostEqual(b, expected, delta=expected * 0.15)

    def test_long_stream_has_no_short_cycle(self):
        """56-entry state; a broken port would repeat far sooner than 10k draws."""
        rng = MonoRandom(5)
        seen = set()
        for _ in range(10000):
            seen.add(rng.next_double())
        self.assertGreater(len(seen), 9900)


if __name__ == "__main__":
    unittest.main(verbosity=2)

import { describe, expect, it } from 'vitest';
import { readFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { MonoRandom } from './rng';

/**
 * Cross-language parity: the Python clone in clone/monorandom.py generated
 * clone/fixtures/rng_vectors.json. If the TypeScript port disagrees with any vector
 * here, the two implementations have drifted and parity is broken.
 *
 * Regenerate with: python clone/gen_fixtures.py
 *
 * The fixture is read with fs rather than imported so it can live outside `src/`
 * (tsconfig `include` is ["src"]) and stay a single source of truth shared by both
 * languages without being pulled into the app bundle.
 */

type Op =
  | { op: 'next_double' }
  | { op: 'next_int' }
  | { op: 'next'; min: number; max: number }
  | { op: 'next_bytes'; count: number }
  | { op: 'range'; min: number; max: number }
  | { op: 'chance'; p: number }
  | { op: 'pick'; items: string[] };

type Fixture = {
  meta: { target: string; mbig: number };
  vectors: Array<{
    seed: number;
    initial: { inext: number; inextp: number; seedArray: number[] };
    results: Array<{ op: Op; value: unknown }>;
    finalSnapshot: { seedArray: number[]; inext: number; inextp: number; drawCount: number };
  }>;
};

const fixture: Fixture = JSON.parse(
  readFileSync(fileURLToPath(new URL('../../clone/fixtures/rng_vectors.json', import.meta.url)), 'utf8'),
);

function apply(rng: MonoRandom, op: Op): unknown {
  switch (op.op) {
    case 'next_double':
      return rng.nextDouble();
    case 'next_int':
      return rng.nextInt();
    case 'next':
      return rng.next(op.min, op.max);
    case 'next_bytes':
      return Array.from(rng.nextBytes(op.count));
    case 'range':
      return rng.range(op.min, op.max);
    case 'chance':
      return rng.chance(op.p);
    case 'pick':
      return rng.pick(op.items);
  }
}

describe('cross-language RNG parity (TypeScript vs Python clone)', () => {
  it('fixture targets BitLife 3.25.3', () => {
    expect(fixture.meta.target).toBe('BitLife 3.25.3 (versionCode 1066, armeabi-v7a)');
  });

  it('covers every fixture seed', () => {
    expect(fixture.vectors.length).toBeGreaterThanOrEqual(8);
  });

  for (const v of fixture.vectors) {
    describe(`seed ${v.seed}`, () => {
      it('constructs the same seedArray as the Python clone', () => {
        const rng = new MonoRandom(v.seed);
        const snap = rng.snapshot();
        expect(snap.seedArray).toEqual(v.initial.seedArray);
        expect(snap.inext).toBe(v.initial.inext);
        expect(snap.inextp).toBe(v.initial.inextp);
      });

      it('reproduces every fixture draw', () => {
        const rng = new MonoRandom(v.seed);
        for (const [i, entry] of v.results.entries()) {
          const got = apply(rng, entry.op);
          expect(
            got,
            `seed=${v.seed} op#${i} ${entry.op.op} -> got ${JSON.stringify(got)}, want ${JSON.stringify(entry.value)}`,
          ).toEqual(entry.value);
        }
      });

      it('ends at the same generator position as the Python clone', () => {
        const rng = new MonoRandom(v.seed);
        for (const entry of v.results) apply(rng, entry.op);
        expect(rng.snapshot()).toEqual(v.finalSnapshot);
      });
    });
  }
});

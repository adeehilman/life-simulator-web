// Life state and the yearly tick.
//
// Mirrors `Life` (dump.cs TypeDefIndex 1534): the age counter, the stat bag, memory,
// and a death roll. IncrementAge is the three-phase sequence the binary runs —
// simulation, UI, memory — see out/REPORT_MECHANICS.md § 4.

import { DISPLAY_STATS, StatType, clampStat, emptyStats, impactStat, type StatBag } from '../stats';
import type { MonoRandom, MonoRandomSnapshot } from '../rng';
import { generateName, type PersonName } from './names';

export type Gender = 'male' | 'female';

export interface LifeLogEntry {
  age: number;
  text: string;
}

export interface Life {
  seed: number;
  name: PersonName;
  gender: Gender;
  country: string;
  city: string;
  age: number;
  alive: boolean;
  causeOfDeath: string | null;
  stats: StatBag;
  money: number;
  log: LifeLogEntry[];
  /** Stats snapshot from last birthday, so the HUD can show movement. */
  previous: StatBag;
  /** Guards re-entry while the increment scenario queue drains. */
  incrementing: boolean;
  /** Domain-specific scenario state retained until a typed subsystem owns it. */
  domainState?: Record<string, number>;
  /** Ordered follow-up scenario IDs awaiting resolution. */
  scenarioQueue?: string[];
  /** Exact Mono/System.Random position at the last persisted state. */
  rngState?: MonoRandomSnapshot;
}

const START_AGE = 0;
const START_MONEY = 0;
/** Rough per-year drift the sim applies before scenarios run. */
const DRIFT: ReadonlyArray<[StatType, number]> = [
  [StatType.Health, 0.4],
  [StatType.Happiness, -0.3],
  [StatType.Smarts, 0.2],
];

/** Baseline mortality by age, before the health contribution. */
function deathChance(age: number, health: number): number {
  if (age < 40) return 0.0006 * Math.max(1, age / 8);
  const base = Math.min(0.55, (age - 40) ** 1.9 / 4200);
  return base * (1.6 - health / 100);
}

export function createLife(rng: MonoRandom, country: string, city: string): Life {
  const gender: Gender = rng.chance(0.5) ? 'male' : 'female';
  const stats = emptyStats(0);
  // Babies are not blank slates in the game: the birth roll seeds the four visible
  // stats inside a narrow band, then health starts high and decays.
  for (const stat of DISPLAY_STATS) {
    stats[stat] = rng.next(30, 71);
  }
  stats[StatType.Health] = rng.next(70, 101);
  for (const stat of [
    StatType.Essence,
    StatType.Charisma,
    StatType.StreetSmarts,
    StatType.Respect,
  ]) {
    stats[stat] = rng.next(10, 41);
  }
  const life: Life = {
    seed: rng.nextInt(),
    name: generateName(rng, gender),
    gender,
    country,
    city,
    age: START_AGE,
    alive: true,
    causeOfDeath: null,
    stats,
    money: START_MONEY,
    log: [],
    previous: { ...stats },
    incrementing: false,
    domainState: {},
    scenarioQueue: [],
    rngState: rng.snapshot(),
  };
  life.log.push({ age: 0, text: `Born ${gender === 'male' ? 'a boy' : 'a girl'} in ${city}, ${country}.` });
  return life;
}

export interface YearResult {
  aged: boolean;
  died: boolean;
  cause: string | null;
  rngDraws: number;
}

export interface AnnualPipelineHooks {
  onSimulation?: (life: Life, result: YearResult) => void;
  onUi?: (life: Life, result: YearResult) => void;
  onMemory?: (life: Life, result: YearResult) => void;
}

/** Recovered order: simulation, UI refresh, then Genesis memory snapshot. */
export function runAnnualPipeline(
  life: Life,
  rng: MonoRandom,
  hooks: AnnualPipelineHooks = {},
): YearResult {
  const result = incrementAgeSimulation(life, rng);
  hooks.onSimulation?.(life, result);
  hooks.onUi?.(life, result);
  hooks.onMemory?.(life, result);
  return result;
}

/** Phase 1 — the sim side of a birthday. Caller runs UI + memory afterwards. */
export function incrementAgeSimulation(life: Life, rng: MonoRandom): YearResult {
  const beforeDraws = rng.snapshot().drawCount;
  if (!life.alive) return { aged: false, died: false, cause: life.causeOfDeath, rngDraws: 0 };
  life.incrementing = true;
  life.previous = { ...life.stats };
  life.age += 1;

  for (const [stat, amount] of DRIFT) {
    const before = life.stats[stat];
    // drift is fractional; the game keeps the stat float, so carry it directly
    life.stats[stat] = clampStat(before + amount);
  }
  // health erodes faster the older the sim gets
  if (life.age > 35) {
    impactStat(life.stats, StatType.Health, -Math.floor((life.age - 35) / 8) - 1, life.age);
  }
  // very young sims regain health instead of losing it
  if (life.age <= 12) life.stats[StatType.Health] = clampStat(life.stats[StatType.Health] + 1);

  const roll = rng.nextDouble();
  if (roll < deathChance(life.age, life.stats[StatType.Health])) {
    life.alive = false;
    life.causeOfDeath = pickCauseOfDeath(life, rng);
    life.incrementing = false;
    life.rngState = rng.snapshot();
    return { aged: true, died: true, cause: life.causeOfDeath, rngDraws: rng.snapshot().drawCount - beforeDraws };
  }

  life.incrementing = false;
  life.rngState = rng.snapshot();
  return { aged: true, died: false, cause: null, rngDraws: rng.snapshot().drawCount - beforeDraws };
}

const CAUSES = [
  'old age',
  'a heart attack',
  'a stroke',
  'cancer',
  'pneumonia',
  'a car accident',
  'a fall',
] as const;

function pickCauseOfDeath(life: Life, rng: MonoRandom): string {
  if (life.age >= 80) return 'old age';
  if (life.stats[StatType.Health] <= 10) return rng.pick(['illness', 'organ failure', 'a heart attack'])!;
  return rng.pick(CAUSES)!;
}

export function logEvent(life: Life, text: string): void {
  life.log.push({ age: life.age, text });
}

/** Human-readable "Age 0 — born" style entries are assembled in the UI. */
export function isChild(life: Life): boolean {
  return life.age <= 4;
}

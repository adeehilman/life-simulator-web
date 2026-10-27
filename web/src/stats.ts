// Stat system — mirrors the game's own arithmetic.
//
// StatType is a bitmask in the binary (TypeDefIndex 6219, powers of two), so keep the
// exact values and let call sites OR them.
//
// Impact scores clamp to [-6, 6] and map through GameReference's fixed table
// (out/REPORT_MECHANICS.md § 2). Positive deltas always land; negative ones are
// dropped while the sim is 4 or younger (SimPerson.ImpactHappiness guard).

export enum StatType {
  None = 0,
  Happiness = 1,
  Health = 2,
  Smarts = 4,
  Looks = 8,
  Essence = 16,
  Fame = 32,
  Reputation = 64,
  Infamy = 128,
  StreetSmarts = 256,
  Performance = 512,
  Greatness = 1024,
  Popularity = 2048,
  Approval = 4096,
  Charisma = 8192,
  Respect = 16384,
}

/** Table index 0 is a designer tunable in the binary; 0 keeps the sim stable. */
const IMPACT_POINTS: Readonly<Record<number, number>> = {
  [-6]: -100,
  [-5]: -50,
  [-4]: -30,
  [-3]: -16,
  [-2]: -8,
  [-1]: -4,
  1: 4,
  2: 8,
  3: 16,
  4: 30,
  5: 50,
  6: 100,
};

export const MAX_STAT = 100;
/** Nothing is a pain-penalty before school age. */
export const DECAY_FREE_AGE = 4;

/** GameReference.AttributeAdjustmentPointsForImpactScore, including the clamp. */
export function pointsForImpact(impact: number): number {
  const clamped = Math.max(-6, Math.min(6, impact | 0));
  return IMPACT_POINTS[clamped] ?? 0;
}

export const STAT_NAMES: Readonly<Record<StatType, string>> = {
  [StatType.None]: 'None',
  [StatType.Happiness]: 'Happiness',
  [StatType.Health]: 'Health',
  [StatType.Smarts]: 'Smarts',
  [StatType.Looks]: 'Looks',
  [StatType.Essence]: 'Essence',
  [StatType.Fame]: 'Fame',
  [StatType.Reputation]: 'Reputation',
  [StatType.Infamy]: 'Infamy',
  [StatType.StreetSmarts]: 'Street Smarts',
  [StatType.Performance]: 'Performance',
  [StatType.Greatness]: 'Greatness',
  [StatType.Popularity]: 'Popularity',
  [StatType.Approval]: 'Approval',
  [StatType.Charisma]: 'Charisma',
  [StatType.Respect]: 'Respect',
};

/** Stats the HUD shows on the main screen, in the game's own order. */
export const DISPLAY_STATS: readonly StatType[] = [
  StatType.Happiness,
  StatType.Health,
  StatType.Smarts,
  StatType.Looks,
];

export type StatBag = Record<StatType, number>;

export function emptyStats(value = 50): StatBag {
  const bag = {} as StatBag;
  for (const key of Object.values(StatType)) {
    if (typeof key === 'number') bag[key] = value;
  }
  bag[StatType.None] = 0;
  return bag;
}

/** Clamp is `>= 100` / `<= 0`, so both ends are reachable and sticky. */
export function clampStat(value: number): number {
  if (value >= MAX_STAT) return MAX_STAT;
  if (value <= 0) return 0;
  return value;
}

export interface ImpactResult {
  applied: boolean;
  before: number;
  after: number;
  delta: number;
}

/**
 * SimPerson.ImpactX for any stat.
 *
 * `age` gates negative impacts; every write is clamped to 0..100.
 */
export function impactStat(
  stats: StatBag,
  stat: StatType,
  impactScore: number,
  age: number,
): ImpactResult {
  const before = stats[stat] ?? 0;
  if (impactScore <= 0 && age <= DECAY_FREE_AGE) {
    return { applied: false, before, after: before, delta: 0 };
  }
  const after = clampStat(before + pointsForImpact(impactScore));
  stats[stat] = after;
  return { applied: true, before, after, delta: after - before };
}

/** Sum of the four displayed stats — the game's rough "how is this life going". */
export function wellbeing(stats: StatBag): number {
  let total = 0;
  for (const stat of DISPLAY_STATS) total += stats[stat] ?? 0;
  return total / DISPLAY_STATS.length;
}

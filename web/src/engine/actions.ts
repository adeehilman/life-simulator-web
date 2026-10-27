import { DISPLAY_STATS, impactStat, StatType, type StatBag } from '../stats';
import type { Life } from './life';
import type { Choice } from './scenario';
import { DOMAIN_DEFINITIONS, normalizeDomainName } from './domain-registry';

const EFFECT_STATS: Readonly<Record<string, StatType>> = {
  happiness: StatType.Happiness,
  health: StatType.Health,
  smarts: StatType.Smarts,
  intelligence: StatType.Smarts,
  looks: StatType.Looks,
  appearance: StatType.Looks,
  essence: StatType.Essence,
  fame: StatType.Fame,
  reputation: StatType.Reputation,
  infamy: StatType.Infamy,
  'street smarts': StatType.StreetSmarts,
  streetsmarts: StatType.StreetSmarts,
  performance: StatType.Performance,
  greatness: StatType.Greatness,
  popularity: StatType.Popularity,
  approval: StatType.Approval,
  charisma: StatType.Charisma,
  respect: StatType.Respect,
};

function statForName(name: string): StatType | undefined {
  return EFFECT_STATS[name.replace(/_/g, ' ').trim().toLowerCase()];
}

export interface EffectResult {
  applied: Record<string, number>;
  unsupported: Record<string, number>;
}

function finishEffectResult(
  applied: Record<string, number>,
  unsupported: Record<string, number>,
): EffectResult {
  return { applied, unsupported };
}

/** Apply authored scenario impacts and report domains without a state target. */
export function applyChoiceEffects(
  life: Pick<Life, 'age' | 'stats' | 'domainState'>,
  choice: Pick<Choice, 'impact' | 'effects'>,
): EffectResult {
  const applied: Record<string, number> = {};
  const unsupported: Record<string, number> = {};
  const entries = Object.entries(choice.effects);

  if (entries.length > 0) {
    for (const [name, impact] of entries) {
      const stat = statForName(name);
      if (stat === undefined) {
        const domain = normalizeDomainName(name);
        if (life.domainState && DOMAIN_DEFINITIONS[domain]) {
          life.domainState[domain] = (life.domainState[domain] ?? 0) + impact;
        } else {
          unsupported[name] = impact;
        }
        continue;
      }
      const result = impactStat(life.stats as StatBag, stat, impact, life.age);
      applied[name] = result.delta;
    }
    return finishEffectResult(applied, unsupported);
  }

  // Legacy two-choice rows sometimes expose only one generic impact score.
  // Preserve the old visible-stat behavior only for that format; designer rows
  // with named impacts take the exact path above.
  if (choice.impact !== 0) {
    for (const stat of DISPLAY_STATS) {
      const result = impactStat(life.stats as StatBag, stat, choice.impact, life.age);
      applied[StatType[stat].toLowerCase()] = result.delta;
    }
  }
  return finishEffectResult(applied, unsupported);
}

// Scenario selection and resolution.
//
// The shipped scenario tables are designer sheets: a `Scenario` column (body text with
// placeholders), an optional `Condition` gate, a `CTA` prompt, and `Yes Choice` /
// `No Choice` labels. Casino and a few others use a wider shape with per-choice
// narrative and impact columns; both are handled here.
//
// Selection mirrors `DataHub.ValidateAndSetScenario` in spirit: filter by condition,
// then draw weighted by how well the row's numeric gates match the current sim.

import { get, getNumber, type CsvTable } from '../csv';
import { StatType } from '../stats';
import { DESIGNER_HEADERS, LEGACY_HEADERS } from './scenario-schema';
import { conditionAccepts, resolveLine } from '../data/text';
import { table, tablesMatching } from '../data/loader';
import type { MonoRandom } from '../rng';
import type { Life } from './life';

export interface Choice {
  text: string;
  /** Impact score in the game's own -6..6 scale, when authored. */
  impact: number;
  /** Named stat impacts from designer rows, kept in authored units. */
  effects: Record<string, number>;
  /** Raw APK designer payload, retained until its interpreter is recovered. */
  impactsPayload?: string;
  advancedLogic?: string;
  /** Scenario/blueprint route selected by this choice. */
  routeTo?: string;
  log: string;
}

export interface Scenario {
  id: string;
  title: string;
  body: string;
  cta: string;
  choices: Choice[];
  currencyCost?: number;
  isAgeUpScenario?: boolean;
  blueprintPayload?: string;
}

const STAT_EFFECTS: Readonly<Record<string, string>> = {
  happiness: 'Happiness',
  health: 'Health',
  smarts: 'Smarts',
  intelligence: 'Intelligence',
  looks: 'Looks',
  appearance: 'Appearance',
  essence: 'Essence',
  fame: 'Fame',
  reputation: 'Reputation',
  infamy: 'Infamy',
  streetSmarts: 'Street Smarts',
  performance: 'Performance',
  greatness: 'Greatness',
  popularity: 'Popularity',
  approval: 'Approval',
  charisma: 'Charisma',
  respect: 'Respect',
};

function firstValue(csv: CsvTable, row: string[], names: readonly string[]): string {
  for (const name of names) {
    const value = get(csv, row, name);
    if (value) return value;
  }
  return '';
}

function choiceText(csv: CsvTable, row: string[], index: number): string {
  const oneBased = index + 1;
  const legacy = index === 0 ? ['Yes Choice', 'Choice'] : index === 1 ? ['No Choice'] : [];
  return firstValue(csv, row, [
    `Choice ${oneBased}`,
    `Choice ${oneBased} Text`,
    `Choice${oneBased}`,
    `Choice${oneBased}_Text`,
    `Choice${oneBased} Text`,
    DESIGNER_HEADERS[(oneBased - 1) * 8 + 16] ?? '',
    ...legacy,
  ]);
}

function choiceRoute(csv: CsvTable, row: string[], index: number): string {
  const oneBased = index + 1;
  return firstValue(csv, row, [
    `Route To ${oneBased}`,
    `RouteTo ${oneBased}`,
    `Choice ${oneBased} Route To`,
    `Choice${oneBased} RouteTo`,
    `Choice${oneBased}_RouteTo`,
    `Choice${oneBased} Route To`,
    DESIGNER_HEADERS[(oneBased - 1) * 8 + 18] ?? '',
    LEGACY_HEADERS[oneBased + 5] ?? '',
  ]);
}

function choicePayload(csv: CsvTable, row: string[], index: number, suffix: string): string {
  const oneBased = index + 1;
  return firstValue(csv, row, [
    `Choice ${oneBased} ${suffix}`,
    `Choice${oneBased} ${suffix}`,
    `Choice${oneBased}_${suffix.replace(/\s+/g, '')}`,
  ]);
}

function booleanValue(value: string): boolean | undefined {
  if (!value) return undefined;
  return /^(true|yes|x|1)$/i.test(value) ? true : false;
} 

function numericOrUndefined(value: string): number | undefined {
  if (!value.trim()) return undefined;
  const parsed = Number(value);
  return Number.isFinite(parsed) ? parsed : undefined;
}

function parseImpactsPayload(payload: string): Record<string, number> {
  const effects: Record<string, number> = {};
  for (const token of payload.split(/[;,|]/)) {
    const match = token.trim().match(/^([A-Za-z][A-Za-z _-]*)\s*=\s*(-?\d+(?:\.\d+)?)$/);
    if (!match) continue;
    const value = Number(match[2]);
    if (Number.isFinite(value)) effects[match[1].trim().toLowerCase().replace(/\s+/g, '_')] = value;
  }
  return effects;
}

function choiceEffects(csv: CsvTable, row: string[], index: number): Record<string, number> {
  const oneBased = index + 1;
  const effects: Record<string, number> = {};
  const payload = choicePayload(csv, row, index, 'Impacts');
  Object.assign(effects, parseImpactsPayload(payload));
  const suffix = new RegExp(String.raw`\sImpact\s${oneBased}$`, 'i');
  for (const header of csv.header) {
    if (!suffix.test(header)) continue;
    const value = getNumber(csv, row, header, Number.NaN);
    if (!Number.isFinite(value)) continue;
    const key = header.replace(suffix, '').trim().toLowerCase().replace(/\s+/g, '_');
    effects[key] = value;
  }
  // Some common stat columns are named without the exact suffix convention.
  for (const [key, label] of Object.entries(STAT_EFFECTS)) {
    const value = getNumber(csv, row, `${label} Impact ${oneBased}`, Number.NaN);
    if (Number.isFinite(value)) effects[key] = value;
  }
  return effects;
}

/** Compile one legacy or designer row without inventing missing choices/effects. */
export function compileScenarioRow(csv: CsvTable, row: string[], rowIndex: number): Scenario | null {
  const body = firstValue(csv, row, ['Body', 'Scenario']);
  if (!body) return null;
  const choices: Choice[] = [];
  for (let index = 0; index < 4; index++) {
    const text = choiceText(csv, row, index);
    if (!text) continue;
    const oneBased = index + 1;
    const narrative = firstValue(csv, row, [
      `Narrative ${oneBased}`,
      `Log Version ${oneBased}`,
      `Choice ${oneBased} Log Entry Line 1`,
      `Choice ${oneBased} Log Entry Line 2`,
    ]);
    const genericImpact = getNumber(csv, row, `Impact ${oneBased}`, 0);
    const effects = choiceEffects(csv, row, index);
    choices.push({
      text,
      impact: genericImpact,
      effects,
      impactsPayload: choicePayload(csv, row, index, 'Impacts') || undefined,
      advancedLogic: choicePayload(csv, row, index, 'Advanced Logic') || undefined,
      routeTo: choiceRoute(csv, row, index) || undefined,
      log: narrative || text,
    });
  }
  if (choices.length === 0) return null;
  const currencyCost = numericOrUndefined(firstValue(csv, row, [
    'Choice Currency Cost',
    'Currency Cost',
  ]));
  const isAgeUpScenario = booleanValue(firstValue(csv, row, [
    'Is Age Up Scenario',
    'IsAgeUpScenario',
  ]));
  const blueprintPayload = firstValue(csv, row, [
    'Blueprint Payload For Route',
    'BlueprintPayloadForRoute',
  ]);
  return {
    id: firstValue(csv, row, ['Scenario ID', 'ScenarioID', 'Index']) || `${rowIndex}`,
    title: firstValue(csv, row, ['Title', 'Exterior Title']),
    body,
    cta: firstValue(csv, row, ['CTA']) || 'What will you do?',
    choices,
    ...(currencyCost === undefined ? {} : { currencyCost }),
    ...(isAgeUpScenario === undefined ? {} : { isAgeUpScenario }),
    ...(blueprintPayload ? { blueprintPayload } : {}),
  };
}

const SCENARIO_TABLE = /(?:-scenarios?|dumb-scenarios?)/i;

let tableCache: string[] | null = null;

async function scenarioTables(): Promise<string[]> {
  if (!tableCache) {
    const all = await tablesMatching(SCENARIO_TABLE);
    // Include legacy Scenario rows and modern designer rows (`Body` + `Choice 1`).
    const usable: string[] = [];
    for (const name of all) {
      const csv = await table(name);
      const headers = csv.header.map((header) => header.toLowerCase());
      if (
        headers.includes('scenario') ||
        (headers.includes('body') && headers.some((header) => /^choice 1$/.test(header)))
      ) {
        usable.push(name);
      }
    }
    tableCache = usable;
  }
  return tableCache;
}

function contextOf(life: Life): string {
  return [
    life.country,
    life.city,
    life.gender,
    life.age < 13 ? 'child' : life.age < 20 ? 'teen' : life.age < 65 ? 'adult' : 'senior',
  ]
    .join(' ')
    .toLowerCase();
}

const LOGIC_STAT_NAMES: Readonly<Record<string, StatType>> = {
  happiness: StatType.Happiness,
  health: StatType.Health,
  smarts: StatType.Smarts,
  intelligence: StatType.Smarts,
  looks: StatType.Looks,
  appearance: StatType.Looks,
  fame: StatType.Fame,
  reputation: StatType.Reputation,
  infamy: StatType.Infamy,
  streetsmarts: StatType.StreetSmarts,
  'street smarts': StatType.StreetSmarts,
  respect: StatType.Respect,
};

function logicValue(name: string, life: Life): number | string | undefined {
  const key = name.trim().toLowerCase();
  const stat = LOGIC_STAT_NAMES[key];
  if (stat !== undefined) return life.stats[stat] ?? 0;
  if (key === 'age') return life.age;
  if (key === 'money') return life.money;
  if (key === 'gender') return life.gender;
  if (key === 'country') return life.country;
  if (key === 'city') return life.city;
  if (key === 'alive') return life.alive ? 'true' : 'false';
  return undefined;
}

function stripOuterParentheses(value: string): string {
  let text = value.trim();
  while (text.startsWith('(') && text.endsWith(')')) {
    let depth = 0;
    let closesAt = -1;
    let quoted = false;
    for (let i = 0; i < text.length; i++) {
      const char = text[i];
      if (char === '"' || char === "'") quoted = !quoted;
      if (quoted) continue;
      if (char === '(') depth++;
      if (char === ')') {
        depth--;
        if (depth === 0) { closesAt = i; break; }
      }
    }
    if (closesAt !== text.length - 1) break;
    text = text.slice(1, -1).trim();
  }
  return text;
}

function splitTopLevel(value: string, separator: string): string[] {
  const parts: string[] = [];
  let start = 0;
  let depth = 0;
  let quoted = false;
  for (let i = 0; i <= value.length - separator.length; i++) {
    const char = value[i];
    if (char === '"' || char === "'") quoted = !quoted;
    if (!quoted && (char === '(' || char === '[')) depth++;
    if (!quoted && (char === ')' || char === ']')) depth--;
    if (!quoted && depth === 0 && value.slice(i, i + separator.length) === separator) {
      parts.push(value.slice(start, i).trim());
      start = i + separator.length;
      i += separator.length - 1;
    }
  }
  parts.push(value.slice(start).trim());
  return parts.filter(Boolean);
}

function parseLogicLiteral(value: string): number | string {
  const text = value.trim().replace(/^['"]|['"]$/g, '');
  const number = Number(text);
  return Number.isFinite(number) && text !== '' ? number : text;
}

function evaluateLogicAtom(atom: string, life: Life): boolean {
  const match = atom.trim().match(/^([A-Za-z][A-Za-z _-]*?)\s*(contains|in|>=|<=|==|=|>|<|!=)\s*(.+)$/i);
  if (!match) return false;
  const actual = logicValue(match[1], life);
  if (actual === undefined) return false;
  const operator = match[2].toLowerCase();
  const rhs = match[3].trim();
  if (operator === 'contains') {
    return typeof actual === 'string' && actual.toLowerCase().includes(String(parseLogicLiteral(rhs)).toLowerCase());
  }
  if (operator === 'in') {
    const values = rhs.startsWith('[') && rhs.endsWith(']')
      ? splitTopLevel(rhs.slice(1, -1), ',').map(parseLogicLiteral)
      : [parseLogicLiteral(rhs)];
    return values.some((value) => typeof actual === 'number' && typeof value === 'number' ? actual === value : String(actual).toLowerCase() === String(value).toLowerCase());
  }
  const expected = parseLogicLiteral(rhs);
  if (typeof actual === 'number' && typeof expected === 'number') {
    switch (operator) {
      case '>=': return actual >= expected;
      case '<=': return actual <= expected;
      case '>': return actual > expected;
      case '<': return actual < expected;
      case '=':
      case '==': return actual === expected;
      case '!=': return actual !== expected;
    }
  }
  const left = String(actual).toLowerCase();
  const right = String(expected).toLowerCase();
  return operator === '=' || operator === '==' ? left === right : operator === '!=' ? left !== right : false;
}

function evaluateLogicExpression(expression: string, life: Life): boolean {
  const text = stripOuterParentheses(expression);
  if (!text) return false;
  if (text.startsWith('!')) return !evaluateLogicExpression(text.slice(1), life);
  const orParts = splitTopLevel(text, '||');
  if (orParts.length > 1) return orParts.some((part) => evaluateLogicExpression(part, life));
  const andParts = splitTopLevel(text, '&&');
  if (andParts.length > 1) return andParts.every((part) => evaluateLogicExpression(part, life));
  return evaluateLogicAtom(text, life);
}

export function evaluateAdvancedLogic(expression: string, life: Life): boolean {
  return evaluateLogicExpression(expression, life);
}

export function choiceIsAvailable(
  choice: Pick<Choice, 'advancedLogic'>,
  life: Life,
): boolean {
  const expression = choice.advancedLogic?.trim();
  return !expression || evaluateAdvancedLogic(expression, life);
}

export function followChoiceRoute(
  scenario: Scenario,
  queue: ReadonlyMap<string, Scenario>,
  choiceIndex = 0,
): Scenario | null {
  const route = scenario.choices[choiceIndex]?.routeTo?.trim();
  return route ? queue.get(route) ?? null : null;
}

export function enqueueRoute(queue: string[], route: string | undefined): void {
  const normalized = route?.trim();
  if (normalized) queue.push(normalized);
}

export function consumeRoute(queue: string[]): string | null {
  return queue.shift() ?? null;
}

export async function compileQueuedScenario(routeId: string, csv: CsvTable): Promise<Scenario | null> {
  const rowIndex = csv.rows.findIndex((row) =>
    firstValue(csv, row, ['Scenario ID', 'ScenarioID', 'Index']) === routeId,
  );
  if (rowIndex < 0) return null;
  return compileScenarioRow(csv, csv.rows[rowIndex], rowIndex);
}

export function scenarioRowAccepts(
  csv: CsvTable,
  row: string[],
  life: Pick<Life, 'age' | 'gender' | 'country' | 'city' | 'stats'>,
): boolean {
  const condition = get(csv, row, 'Condition');
  if (!conditionAccepts(condition, contextOf(life as Life))) return false;

  const minAge = getNumber(csv, row, 'Hero Min Age', getNumber(csv, row, 'Min Age', 0));
  const maxAge = getNumber(csv, row, 'Hero Max Age', getNumber(csv, row, 'Max Age', 200));
  if (life.age < minAge || life.age > maxAge) return false;

  const gender = get(csv, row, 'Hero Gender').toLowerCase();
  if (gender && gender !== 'both' && gender !== life.gender) return false;

  const country = get(csv, row, 'Country').trim().toLowerCase();
  if (country && country !== 'both' && !country.split(/[,/|]/).map((v) => v.trim()).includes(life.country.toLowerCase())) {
    return false;
  }

  const statGates: ReadonlyArray<[string, number]> = [
    ['Happiness', life.stats[1] ?? 0],
    ['Health', life.stats[2] ?? 0],
    ['Smarts', life.stats[4] ?? 0],
    ['Looks', life.stats[8] ?? 0],
    ['Fame', life.stats[32] ?? 0],
    ['Reputation', life.stats[64] ?? 0],
    ['Infamy', life.stats[128] ?? 0],
    ['Respect', life.stats[16384] ?? 0],
  ];
  for (const [name, value] of statGates) {
    const min = getNumber(csv, row, `Min ${name}`, Number.NEGATIVE_INFINITY);
    const max = getNumber(csv, row, `Max ${name}`, Number.POSITIVE_INFINITY);
    if (value < min || value > max) return false;
  }

  const minAttitude = getNumber(csv, row, 'Min Attitude', -100);
  const maxAttitude = getNumber(csv, row, 'Max Attitude', 100);
  if (minAttitude > -100 || maxAttitude < 100) {
    // Per-person relationship state is not in the current Life shell yet.
    const attitude = 0;
    if (attitude < minAttitude || attitude > maxAttitude) return false;
  }
  return true;
}

export function weightedPick<T>(items: readonly T[], weights: readonly number[], rng: MonoRandom): T | undefined {
  const total = weights.reduce((sum, weight) => sum + Math.max(0, weight), 0);
  if (items.length === 0 || total <= 0) return rng.pick(items);
  let roll = rng.nextDouble() * total;
  for (let i = 0; i < items.length; i++) {
    roll -= Math.max(0, weights[i] ?? 0);
    if (roll < 0) return items[i];
  }
  return items[items.length - 1];
}

function rowWeight(csv: CsvTable, row: string[]): number {
  return Math.max(0, getNumber(csv, row, 'Commonness Score', 1));
}

async function resolveScenario(compiled: Scenario, name: string, rowIndex: number, life: Life, rng: MonoRandom): Promise<Scenario> {
  const body = await resolveLine(compiled.body, life.gender, life.country, rng);
  const choices: Choice[] = [];
  for (const choice of compiled.choices) {
    const resolved = await resolveLine(choice.text, life.gender, life.country, rng);
    const resolvedLog = await resolveLine(choice.log, life.gender, life.country, rng);
    choices.push({ ...choice, text: resolved.text, log: resolvedLog.text });
  }
  return {
    ...compiled,
    id: `${name}#${rowIndex}`,
    body: body.text,
    choices,
  };
}

export async function rollQueuedScenario(life: Life, rng: MonoRandom, routeId: string): Promise<Scenario | null> {
  const tables = await scenarioTables();
  for (const name of tables) {
    const csv = await table(name);
    const rowIndex = csv.rows.findIndex((row) => firstValue(csv, row, ['Scenario ID', 'ScenarioID', 'Index']) === routeId);
    if (rowIndex < 0 || !scenarioRowAccepts(csv, csv.rows[rowIndex], life)) continue;
    const compiled = await compileQueuedScenario(routeId, csv);
    if (!compiled) continue;
    return resolveScenario(compiled, name, rowIndex, life, rng);
  }
  return null;
}

export async function rollScenario(life: Life, rng: MonoRandom): Promise<Scenario | null> {
  const tables = await scenarioTables();
  if (tables.length === 0) return null;

  for (let attempt = 0; attempt < 24; attempt++) {
    const name = rng.pick(tables);
    if (!name) continue;
    const csv = await table(name);
    const candidates = csv.rows.filter((row) => scenarioRowAccepts(csv, row, life));
    if (candidates.length === 0) continue;
    const row = weightedPick(candidates, candidates.map((candidate) => rowWeight(csv, candidate)), rng);
    if (!row) continue;

    const compiled = compileScenarioRow(csv, row, csv.rows.indexOf(row));
    if (!compiled) continue;

    const body = await resolveLine(compiled.body, life.gender, life.country, rng);
    const choices: Choice[] = [];
    for (const choice of compiled.choices) {
      const resolved = await resolveLine(choice.text, life.gender, life.country, rng);
      const resolvedLog = await resolveLine(choice.log, life.gender, life.country, rng);
      choices.push({ ...choice, text: resolved.text, log: resolvedLog.text });
    }

    return {
      ...compiled,
      id: `${name}#${csv.rows.indexOf(row)}`,
      body: body.text,
      choices,
    };
  }
  return null;
}

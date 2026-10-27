// Placeholder substitution.
//
// Scenario text carries `<singular>`, `<plural>`, `<insult>`, `<10/15/20/25>` etc. The
// noun placeholders resolve against a themed data table (a16_alcohol, a16_insults,
// a16_animals …); numeric placeholders pick one alternative and fill in a log copy.

import { table, tableIndex } from '../data/loader';
import { get, getList } from '../csv';
import type { MonoRandom } from '../rng';

export interface ResolvedLine {
  text: string;
  log: string;
  /** Table rows that were substituted in, keyed by placeholder — the renderer
   *  can pull their emoji/colour from here. */
  noun: Record<string, Record<string, string>>;
}

const NOUN_TABLES = /^a16_(alcohol|insult|animal|food|drug|pastime|college|career)/i;
const OPTION_GROUP = /<([^<>]*\/[^<>]*)>/g;

function splitOptions(token: string): string[] {
  return token.split('/');
}

let nounTableCache: string[] | null = null;

async function nounTables(): Promise<string[]> {
  if (!nounTableCache) {
    const index = await tableIndex();
    nounTableCache = Object.keys(index).filter((name) => NOUN_TABLES.test(name));
  }
  return nounTableCache;
}

/** Pick a row that satisfies the row's `Gender`/`Country` columns where present. */
function pickNounRow(
  rows: string[][],
  header: string[],
  gender: 'male' | 'female',
  country: string,
  rng: MonoRandom,
): string[] | null {
  const usable = rows.filter((row) => {
    const genderCol = header.findIndex((h) => h.toLowerCase() === 'gender');
    if (genderCol !== -1) {
      const value = (row[genderCol] ?? '').toLowerCase();
      if (value && value !== 'both' && value !== gender) return false;
    }
    const countryCol = header.findIndex((h) => h.toLowerCase() === 'country');
    if (countryCol !== -1) {
      const countries = getList({ header, rows: [] }, row, header[countryCol]);
      if (countries.length && !countries.includes(country)) return false;
    }
    return true;
  });
  return rng.pick(usable) ?? null;
}

export async function resolveLine(
  raw: string,
  gender: 'male' | 'female',
  country: string,
  rng: MonoRandom,
): Promise<ResolvedLine> {
  const noun: Record<string, Record<string, string>> = {};
  const tables = await nounTables();

  // <singular> / <plural> / <insult> …
  const nounPattern = /<([a-z]+)>/g;
  const replaced = await Promise.all(
    raw.split(nounPattern).map(async (chunk, position) => {
      if (position % 2 === 0) return chunk;
      const key = chunk.toLowerCase();
      for (const name of tables) {
        const csv = await table(name);
        const col = csv.header.find((h) => h.toLowerCase() === key);
        if (!col) continue;
        const row = pickNounRow(csv.rows, csv.header, gender, country, rng);
        if (!row) continue;
        noun[key] = Object.fromEntries(
          csv.header.map((h, i) => [h.toLowerCase(), row[i] ?? '']),
        );
        return get(csv, row, col);
      }
      return chunk;
    }),
  );

  let text = replaced.join('');

  // <10/15/20/25> — fill every occurrence of the same token with one choice.
  const log = text;
  text = text.replace(OPTION_GROUP, (_whole, options: string) => {
    const picked = rng.pick(splitOptions(options)) ?? options;
    return picked;
  });

  return { text, log, noun };
}

/** Does this row's condition column accept the current state? */
export function conditionAccepts(condition: string, haystack: string): boolean {
  const trimmed = condition.trim();
  if (!trimmed || trimmed.toLowerCase() === 'any') return true;
  return trimmed
    .toLowerCase()
    .split(/[,/|]/)
    .map((part) => part.trim())
    .filter(Boolean)
    .some((part) => haystack.includes(part));
}

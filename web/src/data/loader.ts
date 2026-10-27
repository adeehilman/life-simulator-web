// Lazy, cached access to the decrypted CSV corpus.
//
// Every table is a `-enc` TextAsset from the asset pack decrypted by
// tools/decrypt_all.py to public/data/<name>.csv. `_index.json` maps each table name
// to its header so tables can be selected without downloading them.

import { decodeCsvBytes, parseCsv, type CsvTable } from '../csv';

const BASE = `${import.meta.env.BASE_URL}data/`;

type TableMeta = { columns: string[]; encoding?: string; family?: string; rows?: number; validUtf8?: boolean };

let indexPromise: Promise<Record<string, string[]>> | null = null;
let typedIndexPromise: Promise<Record<string, TableMeta>> | null = null;
const cache = new Map<string, Promise<CsvTable>>();

function typedTableIndex(): Promise<Record<string, TableMeta>> {
  typedIndexPromise ??= fetch(`${BASE}_typed-index.json`)
    .then((res) => {
      if (!res.ok) throw new Error(`typed table index: ${res.status}`);
      return res.json() as Promise<{ tables: Record<string, TableMeta> }>;
    })
    .then((payload) => payload.tables);
  return typedIndexPromise;
}

export function tableIndex(): Promise<Record<string, string[]>> {
  indexPromise ??= fetch(`${BASE}_index.json`).then((res) => {
    if (!res.ok) throw new Error(`table index: ${res.status}`);
    return res.json() as Promise<Record<string, string[]>>;
  });
  return indexPromise;
}

export function table(name: string): Promise<CsvTable> {
  let pending = cache.get(name);
  if (!pending) {
    pending = Promise.all([
      fetch(`${BASE}${name}.csv`).then((res) => {
        if (!res.ok) throw new Error(`${name}: ${res.status}`);
        return res.arrayBuffer();
      }),
      typedTableIndex().catch(() => ({} as Record<string, TableMeta>)),
    ]).then(([bytes, typed]) => parseCsv(decodeCsvBytes(new Uint8Array(bytes), typed[name]?.encoding)));
    cache.set(name, pending);
  }
  return pending;
}

/** Names of tables whose header contains every one of `columns`. */
export async function tablesWith(columns: readonly string[]): Promise<string[]> {
  const index = await tableIndex();
  const wanted = columns.map((c) => c.toLowerCase());
  return Object.keys(index).filter((name) => {
    const header = index[name].map((h) => h.toLowerCase());
    return wanted.every((col) => header.includes(col));
  });
}

export async function tablesMatching(pattern: RegExp): Promise<string[]> {
  const index = await tableIndex();
  return Object.keys(index).filter((name) => pattern.test(name));
}

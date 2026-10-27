// CSV splitter matching the game's own parser.
//
// DataHub.CSVParser is `,(?=(?:[^"]*"[^"]*")*(?![^"]*"))` — split on commas that are
// not inside a quoted field. Rows are CRLF-delimited. Fields keep their surrounding
// quotes until `unquote` runs, so a caller can tell a literal empty field from `""`.

const SEPARATOR = /,(?=(?:[^"]*"[^"]*")*(?![^"]*"))/;

export function splitRow(line: string): string[] {
  return line.split(SEPARATOR);
}

export function unquote(field: string): string {
  const trimmed = field.trim();
  if (trimmed.length >= 2 && trimmed.startsWith('"') && trimmed.endsWith('"')) {
    return trimmed.slice(1, -1).replace(/""/g, '"');
  }
  return trimmed;
}

export interface CsvTable {
  header: string[];
  rows: string[][];
}

/** Decode extracted CSV bytes without corrupting the cp1252 tables in the APK. */
export function decodeCsvBytes(bytes: Uint8Array, encoding: string = 'utf-8'): string {
  const label = encoding === 'cp1252' || encoding === 'windows-1252' ? 'windows-1252' : encoding;
  return new TextDecoder(label).decode(bytes);
}

export function parseCsv(text: string): CsvTable {
  const records: string[][] = [];
  let record: string[] = [];
  let field = '';
  let quoted = false;

  const pushField = () => {
    record.push(unquote(field));
    field = '';
  };
  const pushRecord = () => {
    // Match the game's parser: ignore a completely empty trailing record.
    if (record.length > 1 || record[0] !== '') records.push(record);
    record = [];
  };

  for (let i = 0; i < text.length; i++) {
    const char = text[i];
    if (quoted) {
      if (char === '"') {
        if (text[i + 1] === '"') {
          field += '"';
          i++;
        } else {
          quoted = false;
        }
      } else {
        field += char;
      }
      continue;
    }
    if (char === '"' && field.length === 0) {
      quoted = true;
    } else if (char === ',') {
      pushField();
    } else if (char === '\n') {
      if (field.endsWith('\r')) field = field.slice(0, -1);
      pushField();
      pushRecord();
    } else {
      field += char;
    }
  }
  if (field.length > 0 || record.length > 0) {
    pushField();
    pushRecord();
  }

  if (records.length === 0) return { header: [], rows: [] };
  return { header: records[0], rows: records.slice(1) };
}

/** Case-insensitive column lookup — the designer sheets are not consistent about case. */
export function columnIndex(header: readonly string[], name: string): number {
  const target = name.toLowerCase();
  return header.findIndex((h) => h.toLowerCase() === target);
}

export function get(table: CsvTable, row: readonly string[], name: string): string {
  const at = columnIndex(table.header, name);
  return at === -1 ? '' : (row[at] ?? '');
}

/** Numeric read with the game's own "bad value means default" convention. */
export function getNumber(
  table: CsvTable,
  row: readonly string[],
  name: string,
  fallback = 0,
): number {
  const raw = get(table, row, name).trim();
  if (!raw) return fallback;
  const value = Number(raw);
  return Number.isFinite(value) ? value : fallback;
}

/** `mx, ca, us` and quoted variants collapse to a lowercase set. */
export function getList(table: CsvTable, row: readonly string[], name: string): string[] {
  return get(table, row, name)
    .split(',')
    .map((part) => part.trim().toLowerCase())
    .filter(Boolean);
}

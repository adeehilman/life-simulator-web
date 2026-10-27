import { mkdirSync, readFileSync, readdirSync, statSync, writeFileSync } from 'node:fs';
import { fileURLToPath } from 'node:url';
import { join, relative } from 'node:path';

const root = fileURLToPath(new URL('..', import.meta.url));
const manifestPath = join(root, 'out', 'datapack', 'manifest.json');
const dataDir = join(root, 'web', 'public', 'data');
const outputPath = join(root, 'out', 'web_coverage.json');

function walk(dir) {
  if (!statSafe(dir)?.isDirectory()) return [];
  return readdirSync(dir, { withFileTypes: true }).flatMap((entry) => {
    const path = join(dir, entry.name);
    return entry.isDirectory() ? walk(path) : [path];
  });
}

function statSafe(path) {
  try { return statSync(path); } catch { return null; }
}

const manifest = JSON.parse(readFileSync(manifestPath, 'utf8'));
const dataFiles = walk(dataDir);
const csvFiles = dataFiles.filter((path) => path.endsWith('.csv'));
const indexFiles = dataFiles.filter((path) => path.endsWith('_index.json'));
const byType = {};
for (const item of manifest) byType[item.type] = (byType[item.type] ?? 0) + 1;

const report = {
  generatedAt: new Date().toISOString(),
  target: 'BitLife 3.25.3 / com.candywriter.bitlife',
  manifestObjects: manifest.length,
  manifestByType: byType,
  webDataFiles: dataFiles.length,
  webCsvFiles: csvFiles.length,
  webIndexFiles: indexFiles.length,
  webDataMiB: dataFiles.reduce((sum, path) => sum + statSync(path).size, 0) / 1024 / 1024,
  notes: [
    'This report verifies copied data files, not semantic support by the runtime engine.',
    'Asset and audio parity require separate mapping and playback reports.',
  ],
  sampleFiles: dataFiles.slice(0, 20).map((path) => relative(root, path)),
};

mkdirSync(join(root, 'out'), { recursive: true });
writeFileSync(outputPath, `${JSON.stringify(report, null, 2)}\n`);
console.log(JSON.stringify(report, null, 2));
console.log(`Wrote ${outputPath}`);

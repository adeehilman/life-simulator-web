# BitLife APK → PWA Web Port — MASTER TODO

Created: 2026-10-26
Supersedes: `PORT_TODO.md` (kept as history)

## Ringkasan permintaan (dari LO)

Port BitLife 3.25.3 (`com.candywriter.bitlife`) ke versi web/PWA yang benar-benar bisa dimainkan, dengan:

1. **Konten sama persis** dengan versi APK sekarang — seluruh scenario, teks, tabel data, dan aset UI dari APK target.
2. **Reverse engineering menyeluruh** — mekanik internal, urutan eksekusi, formula, dan struktur data dibaca dari binary, bukan ditebak.
3. **RNG berbasis stat perlu persis** — generator acak dan urutan pemanggilannya harus mengikuti perilaku APK.
4. **Asset UI perlu sama** — sprite, ikon, font, warna, dan elemen visual memakai aset hasil ekstraksi.
5. **Tata letak/layout perlu sama** — struktur layar, navigasi, dan tata letak mengikuti pola APK.
6. **Musik perlu sama** — musik dan SFX dari APK dipakai dengan trigger yang setara.
7. **Web-native diperbolehkan** untuk teknologi internal Unity, storage, rendering, dan packaging (React/Vite/PWA/IndexedDB menggantikan Unity internals).
8. **Hasil akhir harus buildable dan playable**, bukan sekadar rencana.

## Definisi selesai

Port dianggap selesai hanya jika semua ini benar:

- [ ] PWA build bersih dari repo ini dan berjalan offline setelah load pertama.
- [ ] Life baru bisa dibuat, di-age, disimpan, dan dimuat kembali.
- [ ] Pipeline tahunan mengikuti urutan yang direcover dari binary.
- [ ] RNG memakai Mono `System.Random` (sudah diport) dengan urutan konsumsi yang sesuai.
- [ ] Scenario dimuat dari 965 CSV hasil decrypt, bukan hardcode.
- [ ] Domain inti jalan: stats, health/death, family, relationships, education, careers, money, crime, activities, assets.
- [ ] UI memakai aset ekstraksi dan tata letak setara APK.
- [ ] Musik/SFX ter-decode dan terpasang dengan trigger yang setara.
- [ ] Ada test regresi yang membandingkan hasil web vs bukti APK/static/runtime.
- [ ] Gap yang tersisa terdokumentasi dengan jelas, bukan diklaim selesai.

## Legenda status

- `[x]` selesai dan terverifikasi
- `[~]` sebagian/kerangka ada
- `[ ]` belum
- `[!]` terblokir atau butuh bukti baru

---

## Phase 0 — Baseline & evidence ledger

- [x] Catat versi target, package name, path APK/split/asset pack/metadata/native lib.
- [x] Build bersih PWA: `cd web && npm install && npm run build` (terverifikasi 2026-10-26, exit 0).
- [x] Data CSV tersedia di `web/public/data` (966 file termasuk `_index.json`).
- [x] Font tersedia di `web/public/fonts` (4 file).
- [x] Buat evidence ledger machine-readable: `out/EVIDENCE_LEDGER.json`.
- [~] Tetapkan core test corpus + expected result tetap (`web/src/core.test.ts`); APK runtime fixtures belum ada.
- [x] Dokumentasikan reproduce verify command: `cd web && npm run verify`.

## Phase 1 — Konten & data completeness

- [x] Dump IL2CPP metadata v39.
- [x] Decrypt 965 CSV `*-enc`.
- [x] Build manifest objek Unity (37.478 objek).
- [~] Ekstraksi aset (texture/sprite/font/audio/raw MonoBehaviour).
- [~] Rekonsiliasi objek manifest: `out/asset_index.json` + `web/public/assets/_index.json`; 28,303 manifest entries have consumable extracted files.
- [ ] Perbaiki 17 audio gagal (FMOD/Vorbis/ADPCM).
- [ ] Perbaiki 3 font/texture dependency failures.
- [!] 29 loose `\x00IAP` containers — resolve atau dokumentasikan di luar scope.
- [x] Validasi/copy seluruh 965 CSV ke `web/public/data`.
- [x] Generate typed table index: `out/data_index.json` + `web/public/data/_typed-index.json` (63,110 rows; 221 scenario-like tables).
- [x] CSV values copied byte-for-byte; parser preserves quoting/multiline fields (test-verified).
- [~] Copy browser-consumable sprites/textures/fonts to `web/public/assets` (16,347 files).
- [~] Copy 418 successfully decoded WAV files to `web/public/audio`; 17 FMOD/Vorbis/ADPCM failures remain and trigger mapping is not done.

## Phase 2 — IL2CPP model & mechanics recovery

- [x] Schema TS/JSON dari dump.cs (Life, Scenario, SimPerson, SimDeath, StatType).
- [x] Analisis IncrementAge ×3 + UpdateStatesForAge.
- [x] Identifikasi StatType bitmask.
- [x] Recovery mapping impact `[-6..6] → poin stat`.
- [x] Recovery Mono `System.Random` untuk `DataHub.GetRandomNumber`.
- [~] Decompile stat getter + scenario/deck/RNG wrapper; 20 target addresses exported to `out/ghidra/decompiled_20methods.c`.
- [~] Resolve `FUN_*` via `script.json`: ledger covers 147 references; 2 resolve directly, 145 need runtime/metadata-usage analysis.
- [~] Static evidence: `ValidateAndSetScenario` uses tier/deck queue structures; uniform random row selection is not parity-correct.
- [~] Mechanics batch report: `out/REPORT_MECHANICS_20METHODS.md`; six additional targets were decompiled, but unresolved boundaries/types prevent new exact TS rules.
- [ ] Recovery tabel inisialisasi stat by age/gender/country/trait.
- [ ] Recovery fungsi mutasi stat untuk semua `StatType`.
- [ ] Recovery clamp, decay, disease, injury, addiction, death rules.
- [ ] Recovery urutan pemanggilan tahunan, gating flag, scenario queue, snapshot timing.
- [ ] Recovery `ValidateAndSetScenario` + `RandomDeckCollection` weighting.
- [ ] Recovery condition evaluation + designer/Genesis blueprint execution.
- [ ] Recovery semua tipe effect/action scenario dan field targetnya.
- [ ] Recovery save serialization/compression/encryption jika kompatibilitas save APK diperlukan.
- [ ] Tambahkan catatan interpretasi di setiap method decompile; pseudo-C saja tidak diterima.

## Phase 3 — Runtime data layer

- [~] Lazy CSV loader + header index.
- [x] Generic CSV parser; quoted comma/escape/multiline tested.
- [~] Typed table index: `out/data_index.json` + `_typed-index.json`.
- [~] Typed domain loaders started in `web/src/data/domains.ts`: careers, countries, diseases, relationship scenarios; remaining domains and exact schemas pending.
- [~] Resolver placeholder/localization/substitusi dasar.
- [~] Scenario compiler: 2–4 choice rows, raw designer metadata preservation, conservative logic gates, age/gender/country/stat gates, Commonness weighting, and persisted route queue; 221 scenario-like tables indexed, full blueprint/condition/action semantics belum lengkap.
- [~] Effect coverage audit: 102 authored impact domains found in decrypted CSV corpus (`out/scenario_effect_coverage.json`). Generic `domainState` now retains unsupported authored numeric effects and survives save/load; typed semantics per domain remain pending.
- [~] Known advanced-logic comparisons (`stat`, `age`, `money`, `gender`, `country`, `alive`, `&&`, `||`) evaluate conservatively; unknown tokens reject. Full APK Genesis logic belum.
- [ ] Dukung legacy + designer scenario format secara penuh.
- [~] Preserve non-UTF8 content: typed loader now decodes cp1252 tables from `_typed-index.json`; 54 such files documented.
- [ ] Cache/index tanpa mengubah urutan baris atau semantik random selection.
- [ ] Diagnostik malformed row + coverage report.

## Phase 4 — Simulation engine

- [~] Kerangka create life, age counter, 4 stat terlihat, log, death shell.
- [~] Kerangka yearly tick.
- [ ] Life creation + birth circumstance resolution persis.
- [ ] Stat/RNG stream + urutan pemanggilan persis.
- [ ] Annual simulation pipeline persis.
- [ ] Scenario selection, weighting, eligibility, cooldown, queue, chain.
- [ ] Choice action interpreter dengan semua effect numerik/string/state.
- [ ] Health, disease, injury, addiction, treatment, death.
- [ ] Family, children, sibling, spouse, ex-partner, relationship attitude.
- [ ] Education, graduation, application, school event.
- [ ] Careers, promotion, performance, firing, retirement, workplace event.
- [ ] Money, income, expense, tax, loan, asset, inheritance, bankruptcy.
- [ ] Crime, arrest, court, prison, escape.
- [ ] Activities, hobby, travel, fame, social media, pet, vehicle, property.
- [ ] Special domain dari data target (actor, athlete, astronaut, casino, business, zoo, vampire, seasonal).
- [ ] Death/obituary + post-life state.

## Phase 5 — UI, layout, asset, audio

- [x] Shell React/Vite/PWA ada di `web/`; build produksi terverifikasi.
- [~] Dashboard life + scenario card dasar ada; masih prototype.
- [ ] Inventarisasi + pemetaan sprite/texture ke komponen UI semantik.
- [ ] Rekonstruksi inventaris screen + navigasi dari bukti Unity UI/prefab/MonoBehaviour.
- [ ] Rekonstruksi layout mobile portrait: spacing, warna, tipografi, ikon, kartu, menu, modal.
- [ ] Tambah layout desktop responsif tanpa mengubah semantik gameplay.
- [ ] Integrasikan font ekstraksi + verifikasi fallback.
- [~] 418 WAV berhasil diekstrak, disalin ke `web/public/audio`, diberi URL/playback helper dan explicit `age-up` event registry (`web/src/audio.ts`); 17 clip dan APK trigger mapping masih pending.
- [ ] Map musik/SFX ke trigger screen/event/transisi.
- [ ] Recreate animasi/feedback dengan CSS/Web Animations/Canvas.
- [ ] Aksesibilitas + kontrol keyboard/touch tanpa mengubah alur target.

## Phase 6 — Persistence, PWA, packaging

- [~] IndexedDB autosave/load dengan envelope berversi sudah ada.
- [~] JSON export/import + migration v1→v2 + save slots API sudah ada; `domainState` dan `scenarioQueue` persist; UI slot management dan corruption recovery belum.
- [~] Konfigurasi PWA manifest/service worker ada.
- [ ] Verifikasi offline boot + offline play penuh setelah load pertama.
- [ ] Cache versioning aset/data terikat ke build APK target.
- [ ] Hapus dependency Unity/mobile backend/analytics yang tidak perlu.
- [ ] Build produksi reproducible + artifact deployment.

## Phase 7 — Validasi & parity

- [~] Unit test: RNG, stat mapping, clamp, condition, substitution, CSV parsing, scenario compiler/effects, weighted gates, save migration, audio URL (16 tests).
- [ ] Golden fixture untuk baris scenario + choice effect representatif.
- [ ] Fixture regresi tahun-demi-tahun untuk seed life diketahui.
- [ ] Cross-check decompile statis vs observasi runtime.
- [ ] Perbandingan visual setiap screen vs screenshot APK.
- [ ] Verifikasi trigger + playback audio.
- [ ] QA mobile browser: Chrome Android, Firefox Android, Safari iOS.
- [ ] QA desktop + responsive layout.
- [ ] Audit performa/bundle size untuk korpus konten penuh.
- [ ] Laporan coverage akhir: tabel, aset, sistem, screen, sound, gap tersisa.

---

## Progress log

### 2026-10-26
- Master TODO dibuat dari permintaan LO.
- Baseline PWA terverifikasi: `npm run build` exit 0, precache 979 entri, `dist/` terbentuk.
- Data CSV (966 file) + font (4 file) sudah ada di `web/public`.
- Engine kerangka ada: `web/src/engine/{life,scenario,names}.ts`, `web/src/{rng,stats}.ts`, `web/src/data/loader.ts`.
- `MonoRandom` sudah memport Mono `System.Random` sesuai `out/REPORT_MECHANICS.md § 1`.
- `StatType` bitmask + `pointsForImpact` sudah sesuai `§ 2`/`§ 3`.
- CSV parser diperbaiki agar mendukung quoted commas, escaped quotes, dan multiline quoted fields; diverifikasi oleh test.
- IndexedDB autosave/load sudah ditambahkan di `web/src/persistence.ts` dan dipasang ke `App.tsx` (best-effort di private mode).
- Vitest ditambahkan; 26 core tests lulus (`npm test`), termasuk CSV cp1252, scenario compiler/effects, designer metadata/logic gates, weighted eligibility, unsupported/domain-state diagnostics, route queue, save migration, annual pipeline ordering, dan audio event registry.
- Coverage report ditambahkan di `tools/coverage_report.mjs`; hasil `out/web_coverage.json` mengonfirmasi 37.478 manifest objects, 965 CSV + index di web.
- Production build tetap lulus: `npm run build`; setelah asset/audio copy precache terverifikasi pada 4.236 entries (~157 MiB) dan pada clean build asset penuh dapat mencapai ~17.747 entries (~677 MiB), tergantung proses parallel build yang aktif.
- Scenario compiler diperluas: legacy/designer row dengan 2–4 choice, `Body`/`Scenario`, `Route To`, named `* Impact N`, dan domain effects dipertahankan.
- Choice runtime sekarang menerapkan hanya stat/effect yang authored; tidak lagi mengubah semua visible stat secara membabi buta.
- Ghidra menambah 6 target scenario/deck (14 total), lalu 6 target mechanics tambahan (20 total), output terbaru `out/ghidra/decompiled_20methods.c`; `out/REPORT_MECHANICS_20METHODS.md` mencatat batas interpretasi dan 147 FUN references.
- Typed data index dibuat: 965 CSV, 63.110 rows, 221 scenario-like tables; 54 file memakai cp1252/invalid UTF-8 dan perlu loader encoding yang tepat.
- Asset semantic index + copy dibuat: `out/asset_index.json`, `web/public/assets/_index.json`, 16.347 sprite/texture/font files di web.
- Evidence ledger dibuat: `out/EVIDENCE_LEDGER.json`.
- Verify terakhir: 16 tests lulus dan production build exit 0; PWA precache menjadi 17.747 entries (~677 MiB) setelah asset/audio copy.
- Typed domain loaders dimulai (`web/src/data/domains.ts`) untuk careers, countries, diseases, relationships.
- Scenario engine sekarang punya exported eligibility (age/gender/country/stat) + Commonness weighted selection; detail deck/tier APK masih belum dipindahkan penuh.
- Audio helper ditambahkan (`web/src/audio.ts`) untuk preload/play 418 WAV valid; trigger mapping dan 17 failed clips masih pending.
- Verify terakhir setelah domain/route/audio plumbing: 26 tests lulus, `npm run verify` exit 0, precache 17.747 entries (~677 MiB).
- Belum ada: typed domain runtime lengkap, blueprint/condition/action semantics lengkap, complete parity mechanics, full runtime fixtures, visual/runtime validation.

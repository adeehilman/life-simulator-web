# BitLife 3.25.3 Web Port — Plan menuju 100%

Target: PWA web yang mempertahankan konten, state transition, scenario behavior, RNG consumption, UI observable behavior, layout, audio event behavior, persistence, dan output yang dapat dibandingkan dengan APK BitLife 3.25.3.

Tanggal dibuat: 2026-10-27
Status dokumen: aktif
Sumber kebenaran progress: file ini + `PORT_MASTER_TODO.md` + `out/EVIDENCE_LEDGER.json`.

## Definisi 100%

Port hanya boleh dinyatakan 100% jika semua gate berikut memiliki bukti:

1. Semua konten dan tabel APK terinventarisasi, tersalin, atau memiliki keputusan scope berbukti.
2. Semua state yang memengaruhi output gameplay memiliki model web dan reducer/action handler.
3. Semua scenario legacy/designer/Genesis dapat diparse, dievaluasi, dieksekusi, diroute, dan di-queue.
4. Annual pipeline, RNG stream, stat mutation, death, dan domain systems menghasilkan fixture yang sama dengan APK untuk corpus uji.
5. Semua screen utama, navigation, layout portrait/desktop, asset, font, animation, dan modal flow dibandingkan dengan APK.
6. Semua audio yang diperlukan tersedia dalam format browser dan trigger/loop/volume mapping diuji.
7. Save slots, export/import, migration, corruption recovery, offline boot/play, dan cache versioning teruji.
8. Regression suite APK-vs-web lulus tanpa gap tidak terdokumentasi.
9. Tidak ada item `[ ]`, `[!]`, atau `[~]` yang menyangkut target parity; item out-of-scope harus punya bukti.

## Aturan eksekusi

- Setiap fase harus menghasilkan artifact, test, atau evidence.
- Test ditulis sebelum implementasi baru dan harus terlihat gagal sebelum dibuat green.
- Pseudo-C, build success, dan asset copy tidak dihitung sebagai semantic parity tanpa fixture.
- Domain yang belum dapat dipetakan tidak boleh diam-diam dianggap generic.
- Jika APK runtime tidak tersedia untuk fixture, status tetap `blocked`/`static-only`, bukan selesai.
- Setiap perubahan wajib menjalankan focused test lalu `npm run verify`.
- Progress dicatat di bagian log dan ledger machine-readable.

## Fase eksekusi

### Phase 0 — Baseline dan audit otomatis

Status: `[~]`

- [x] Tetapkan target APK, version, package, input/output paths.
- [x] PWA build/test baseline.
- [x] Evidence ledger.
- [x] Buat parity status generator `tools/parity_report.py` yang menghitung CSV, manifest assets, audio, effect domains, dan unresolved FUN refs.
- [x] Lock source hashes untuk dump, metadata, data index, asset index, decompile output, ledger, dan effect coverage.
- [x] Tambahkan `npm run parity-report`.

Gate: report reproducible dan dapat mendeteksi regression count — generator run berhasil, full verify sedang berjalan.

### Phase 1 — Corpus dan asset completeness

Status: `[~]`

- [x] Il2CppDumper metadata v39.
- [x] 965 CSV decrypt/copy.
- [x] Typed data index dan encoding inventory.
- [x] Asset manifest 37,478 serialized objects.
- [x] 16,347 sprite/texture/font files copied.
- [ ] Decode 17 AudioClip failures.
- [ ] Resolve 3 font/texture dependency failures.
- [ ] Analyze 29 `\x00IAP` containers; prove scope or decode.
- [ ] Reconcile every manifest object to extracted/categorized/unsupported result.

Gate: zero unexplained extraction failures, atau setiap failure punya bukti out-of-scope.

### Phase 2 — Native mechanics recovery

Status: `[~]`

- [x] Life schema, StatType, impact table, MonoRandom static recovery.
- [x] 20 Ghidra targets and interpretation report.
- [ ] Correct function boundaries/prototypes for annual pipeline and stat mutation.
- [ ] Resolve relevant `FUN_*` and `DAT_*` references.
- [ ] Recover stat initialization by age/gender/country/trait.
- [ ] Recover all stat mutation, clamp, decay, disease, injury, addiction, death rules.
- [~] Web Mono RNG now supports exact snapshot/restore, draw-count tracing, and persistence in `Life.rngState`; deterministic seed-1 compatibility and annual draw-count tests pass. APK seed/internal memory capture remains blocked by WSA SELinux/Frida attach denial.
- [~] Recover exact APK RNG call order and seed source; Frida 17.24.3 root setup and attach are now verified on PID 26952, but WSA ARM64-on-x86_64 runtime did not map `libil2cpp.so`, so no RVA hook/event capture is available yet.
- [ ] Add native/static fixture for each recovered rule.

Gate: every translated rule has source address + interpretation + test fixture.

### Phase 3 — Genesis scenario runtime

Status: `[~]`

- [~] Legacy/designer compiler, raw metadata preservation, simple logic evaluator.
- [~] Generic domain state and persisted route queue.
- [~] Generated registry for all 102 authored impact domains (`web/src/engine/domain-registry.ts`) with corpus counts/categories; typed reducers and semantics remain pending.
- [ ] Parse all 54 designer headers exactly.
- [ ] Parse legacy 32 headers exactly.
- [ ] Decode blueprint payload structure.
- [x] Implement Genesis condition AST/operators, grouping, negation, typed values for the recovered native operator surface; native filter execution is also covered.
- [~] Implement Genesis action/effect interpreter: typed state actions now cover vars, entities, transient objects, collections, slots, feature containers, and transactional rollback; prison/combat/dating/paywall/currency/UI blueprint reducers remain explicit unsupported diagnostics.
- [~] Implement route chains, entry points, follow-up, failure/success branches, age-up scenarios, costs; base route queue exists, but full blueprint route semantics and APK fixture remain open.
- [x] Preserve unsupported blueprint actions as diagnostics instead of silently treating them as applied.
- [~] Native Genesis schema inventory recovered from `dump.cs`: `BluePrintType` 31 values, `GENESIS_FILTER` 30 filters, `MATH_OPERATOR` 6 operators, and entity/property/collection/slot model.
- [ ] Preserve row order and APK random consumption.
- [ ] Build scenario golden fixtures from real corpus.

Gate: every scenario action type is executed or explicitly proven metadata-only.

### Phase 4 — Domain state and annual simulation

Status: `[~]`

- [~] Core Life/stats/money/log/death shell.
- [~] Generic domainState fallback.
- [~] Generated registry for all 102 authored impact domains (`web/src/engine/domain-registry.ts`) with corpus counts/categories; typed reducers and semantics remain pending.
- [ ] Convert each of the 102 impact domains into typed state/reducer or prove transient-only.
- [ ] Health/disease/injury/treatment/addiction/death.
- [ ] Family/children/siblings/parents/spouse/ex/relationship attitude.
- [ ] Education/school/college/graduation.
- [ ] Career/job/performance/promotion/firing/retirement.
- [ ] Finance/income/expense/tax/loan/asset/inheritance/bankruptcy.
- [ ] Crime/arrest/court/prison/escape.
- [ ] Property/vehicle/pet/activity/travel/fame/social media.
- [ ] Special systems: actor, athlete, astronaut, casino, business, zoo, vampire, seasonal, etc.
- [ ] Exact annual stage ordering and gate flags.
- [ ] Year-by-year fixtures and deterministic state diff.

Gate: no authored domain effect silently disappears; annual fixtures match APK oracle.

### Phase 5 — UI, layout, navigation, assets

Status: `[~]`

- [~] React/Vite/PWA shell and prototype dashboard.
- [ ] Extract screen/prefab/navigation evidence from Unity objects and MonoBehaviours.
- [ ] Map every semantic asset to screen/component.
- [ ] Rebuild portrait dashboard, stats, cards, buttons, menus, modal, lists, forms, obituary.
- [ ] Rebuild navigation and back/close/confirm behavior.
- [ ] Integrate extracted fonts and verify text metrics.
- [ ] Rebuild responsive desktop layout.
- [ ] Rebuild visible animation/feedback.
- [ ] Screenshot diff fixtures for representative screens.

Gate: screen inventory complete and visual diff thresholds pass.

### Phase 6 — Audio

Status: `[~]`

- [~] 418 WAV copied; explicit web event registry and age-up event plumbing.
- [ ] Decode remaining 17 clips or prove unused/unneeded.
- [ ] Identify Unity AudioSource/AudioClip references and event names.
- [ ] Map music/SFX to screens, age, choice, popup, death, achievement, transition.
- [ ] Recreate loop, one-shot, volume, priority, ducking, and transition behavior.
- [ ] Audio event regression fixtures.

Gate: every required clip has verified trigger and browser playback fixture.

### Phase 7 — Persistence and packaging

Status: `[~]`

- [~] IndexedDB autosave, slots API, export/import, v1→v2 migration.
- [~] domainState/scenarioQueue persistence.
- [ ] Corruption detection/recovery and invalid-save quarantine.
- [ ] Verify all slots, deletion, rename, import/export.
- [ ] Offline boot/play smoke test from production service worker.
- [ ] Cache versioning tied to corpus/build hash.
- [ ] Reproducible production artifact and deployment instructions.

Gate: reload/offline/corrupt/import scenarios pass.

### Phase 8 — APK-vs-web regression and completion audit

Status: `[ ]`

- [~] Establish read-only APK oracle capture method via `tools/oracle_capture.py`; ADB `127.0.0.1:58526` works, but connected package is version 3.26.0 while target is 3.25.3.
- [~] Capture baseline screens/activity/package/logcat: `out/oracle/bitlife-3.26.0-baseline/capture.json` contains 3 frames.
- [~] Capture controlled gameplay sequence with OCR: Age 0 → Age 1 `Physical Development` → `Crawl across the floor` → Age 2 `Vaccination`; fixture `out/oracle/bitlife-3.26.0-baseline/fixture_sequence.json`. This is 3.26.0 evidence only; RNG/internal IDs still unavailable.
- [~] Magisk root read-only audit completed; `ATH_DATA` classified as auth/session JSON and raw token discarded; no plaintext gameplay save found in selected private files. Redacted report: `out/oracle/private-3.26.0/private_audit_redacted.json`.
- [~] Normalize visible oracle scenario against target corpus: `Physical Development` matches `a16_dumb-scenarios-universal.csv` row 117; `Vaccination` is currently a candidate version/content delta. Report: `out/oracle/bitlife-3.26.0-baseline/scenario_matches.json`.
- [ ] Normalize APK/web state for diff without hiding meaningful fields.
- [ ] Run fixture suite across all domains and scenario classes.
- [ ] Run mobile browser QA: Chrome Android, Firefox Android, Safari iOS.
- [ ] Run desktop/responsive QA.
- [ ] Run performance/storage/offline audit.
- [ ] Generate final coverage report.
- [ ] Remove every unexplained TODO marker.
- [ ] Set `PORT_100_PLAN.md` status to `[x] 100% COMPLETE` only after all gates pass.

Gate: final report contains zero unexplained parity gaps.

## Current verified baseline

- 30 Vitest tests pass.
- `npm run verify` passes.
- Read-only ADB oracle is connected at `127.0.0.1:58526`; installed package is 3.26.0.
- Controlled OCR fixture sequence captured for dashboard, Age Up, scenario choice, and follow-up scenario.
- Production PWA precaches 17,747 entries (~677 MiB).
- 965 CSV tables copied; 63,110 indexed rows; 221 scenario-like tables.
- 16,347 sprite/texture/font files copied.
- 418 WAV files copied; 17 AudioClip failures remain.
- 20 Ghidra target addresses exported; 145 of 147 FUN references unresolved in the current 14-method resolution set.
- Full Genesis interpreter, typed domain reducers, exact APK deck semantics, UI parity, full audio mapping, and APK regression fixtures are not complete.

## Progress log

### 2026-10-27

- Created this phased 100% plan.
- Existing verified baseline copied from `PORT_MASTER_TODO.md` and `out/EVIDENCE_LEDGER.json`.
- Phase 0: parity status generator and source hash lock completed; artifact `out/port_parity_report.json`.
- Phase 3: exact header schema generated from `dump.cs` (`scenario-schema.ts`); compiler alias coverage uses APK enum names.
- Phase 4: generated `web/src/engine/domain-registry.ts` from the real 102-domain corpus with authored column/file counts and conservative categories.
- Integrated registry lookup into `applyChoiceEffects`; known registry domains can persist in `domainState`, while unknown names remain diagnostics.
- Verification after this batch: 30 tests pass, `npm run verify` exit 0, production PWA build succeeds, precache 17,747 entries (~677 MiB).
- RNG/annual slice: added exact `MonoRandom` snapshot/restore, persisted `Life.rngState`, draw counter, and `YearResult.rngDraws`; focused and full verification pass.
- Genesis slice: added `web/src/engine/genesis.ts` with native Genesis filter operators and transactional state interpreter for variables, entities, transient objects, collections, slots, and feature containers; unsupported BlueprintTypes remain diagnostics. Focused suite: 33 tests pass.
- Scenario logic slice: advanced-logic evaluator now handles nested grouping, negation, numeric/string typed literals, `contains`, and `in` lists; full verification pending after this log entry.
- Dynamic APK RNG attach attempted with matching Frida 17.24.3 x86_64 server; WSA/SELinux returned `PermissionDeniedError`, so APK seed/internal memory remains unverified.
- Added `tools/oracle_capture.py`; ADB connection works and produced 3 read-only frames under `out/oracle/bitlife-3.26.0-baseline/`.
- Connected APK is version 3.26.0 (versionCode 1069), not target 3.25.3; its frames are baseline-only and cannot close target regression gates.
- Magisk root was granted; read-only private audit confirms `ATH_DATA` is auth/session JSON, not gameplay save. Raw auth value was discarded; report is redacted at `out/oracle/private-3.26.0/private_audit_redacted.json`.
- `Physical Development` visibly matches target 3.25.3 corpus row 117; `Vaccination` remains a candidate 3.26.0-vs-3.25.3 delta.
- Remaining blockers unchanged: 17 AudioClip failures, 3 font/texture failures, 29 IAP containers, 145 unresolved FUN references, full Genesis semantics, typed reducers, target-version APK fixtures, UI/audio parity.

## Completion notification rule

The agent must explicitly report completion only when this file contains:

```text
Status: [x] 100% COMPLETE
Final verification: PASS
Unexplained parity gaps: 0
```

Until then, progress updates must state the remaining gaps plainly.

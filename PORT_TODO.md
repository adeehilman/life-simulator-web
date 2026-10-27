# BitLife APK → PWA Port — Master TODO

Updated: 2026-10-26

## User goal

Port the target BitLife APK into a playable PWA web version with:

- the same extracted scenario/content corpus as the target APK;
- stat-dependent RNG and gameplay behavior reproduced as precisely as possible;
- equivalent UI assets, screen structure, layout, typography, audio/music, and interaction flow;
- web-native replacements allowed for Unity internals, storage, rendering, networking, and packaging;
- no claim of completion until the PWA is built, tested, and the major systems are exercised end to end.

Target baseline: BitLife 3.25.3 / `com.candywriter.bitlife` from the supplied APK/XAPK.

## Completion definition

The port is complete only when all of these are true:

1. The PWA builds from a clean checkout and runs offline after first load.
2. A new life can be created and saved/loaded.
3. Age progression follows the recovered yearly pipeline and uses the recovered RNG stream/call order where required.
4. Scenario tables, conditions, choices, effects, chains, substitutions, and follow-ups are loaded from the extracted corpus rather than hardcoded approximations.
5. Core domains work: stats, health/death, family, relationships, education, careers, money, crime, activities, assets, and special systems represented by the APK data.
6. UI screens have been mapped to the extracted assets and reproduce the target layout/interaction model at mobile and desktop breakpoints.
7. Music and sound assets are decoded, mapped, and played through web audio with equivalent trigger points.
8. Regression fixtures compare representative web outcomes against observed APK/static/runtime evidence.
9. Known unsupported items are either fixed or explicitly proven irrelevant to the target scope.

## Status legend

- `[x]` verified complete
- `[~]` implemented/partially verified
- `[ ]` not complete
- `[!]` blocked or needs new evidence

---

## Phase 0 — Baseline and evidence ledger

- [x] Record APK/XAPK, extracted paths, ABI split, asset pack, metadata, and native library.
- [x] Record the target version and package name.
- [x] Keep `CONTEXT.md`, `INVENTORY.md`, and this file synchronized.
- [ ] Create a machine-readable evidence ledger mapping every implementation rule to its source (CSV, dump.cs, Ghidra, runtime trace, or visual reference).
- [x] Define a repeatable clean-build command for the complete PWA: `cd web && npm install && npm run build`.
- [ ] Define a fixed test corpus and expected results.

## Phase 1 — Content and data completeness

- [x] Dump IL2CPP metadata with v39 support.
- [x] Decrypt the base64 `*-enc` TextAssets (965 CSV outputs).
- [x] Build the serialized Unity object manifest.
- [~] Export textures, sprites, fonts, audio, and raw serialized objects.
- [ ] Reconcile every manifest object against a successful web-consumable output.
- [ ] Fix the 17 audio extraction failures (FMOD/Vorbis/ADPCM).
- [ ] Fix the 3 font/texture dependency failures.
- [!] Resolve the 29 loose `\x00IAP` containers, or document with evidence that they are outside the target gameplay/content scope.
- [ ] Validate that every scenario/data table needed by a referenced class is present in `web/public/data`.
- [ ] Generate typed data indexes for all table families, not only filename/header indexes.
- [ ] Preserve exact CSV values, empty fields, quoting, multiline values, numeric precision, and row order.

## Phase 2 — IL2CPP model and mechanics recovery

- [x] Generate TypeScript/JSON model output from `dump.cs` (`Life`, `Scenario`, `SimPerson`, `SimDeath`, `StatType`, etc.).
- [x] Analyze `Life.IncrementAge`, `IncrementAgeSimulation`, `IncrementAgeUI`, and `Sim.UpdateStatesForAge`.
- [x] Identify `StatType` bitmask values.
- [x] Recover the scenario impact mapping `[-6..6] → stat points` where evidenced.
- [x] Recover the Mono/System.Random implementation used by `DataHub.GetRandomNumber` where evidenced.
- [~] Decompile key stat getters and RNG wrappers.
- [ ] Resolve all `FUN_*` calls used by the yearly pipeline to dump.cs/script.json names.
- [ ] Recover exact stat initialization tables by age, gender, country, and relevant traits.
- [ ] Recover exact stat mutation functions for Happiness, Health, Smarts, Looks, Fame, Reputation, Infamy, and other `StatType` members.
- [ ] Recover exact clamp, decay, disease, injury, addiction, and death rules.
- [ ] Recover exact yearly call order, gating flags, scenario queue behavior, and snapshot timing.
- [ ] Recover `ValidateAndSetScenario` and `RandomDeckCollection` weighting.
- [ ] Recover condition evaluation and designer/Genesis blueprint execution.
- [ ] Recover all scenario effect/action types and their target fields.
- [ ] Recover save serialization/compression/encryption only if APK save compatibility is required.
- [ ] Add interpretation notes beside every decompiled method; pseudo-C alone is not accepted as implementation evidence.

## Phase 3 — Runtime data layer

- [~] Lazy CSV loader and header index.
- [~] Generic CSV parser.
- [ ] Typed loaders for country/city, names, careers, education, health, crime, relationships, property, vehicles, pets, finance, activities, and special systems.
- [ ] Exact placeholder/localization/substitution resolver.
- [ ] Scenario compiler: CSV/blueprint rows → normalized conditions, choices, actions, and chains.
- [ ] Support legacy and designer scenario formats where needed.
- [ ] Cache/index tables without changing row order or random-selection semantics.
- [ ] Add malformed-row diagnostics and coverage report.

## Phase 4 — Simulation engine

- [~] Life creation shell, age counter, four visible stats, log, and death shell.
- [~] Basic yearly tick shell.
- [ ] Exact life creation and birth-circumstance resolution.
- [ ] Exact stat/RNG stream and call ordering.
- [ ] Exact annual simulation pipeline.
- [ ] Scenario selection, weighting, eligibility, cooldowns, queues, and chains.
- [ ] Choice action interpreter with all numeric/string/state effects.
- [ ] Health, diseases, injuries, addictions, treatments, and death.
- [ ] Family, children, siblings, spouse, ex-partners, and relationship attitudes.
- [ ] Education, graduation, applications, and school events.
- [ ] Careers, promotions, performance, firing, retirement, and workplace events.
- [ ] Money, income, expenses, taxes, loans, assets, inheritance, and bankruptcy.
- [ ] Crime, arrest, court, prison, escape, and related events.
- [ ] Activities, hobbies, travel, fame, social media, pets, vehicles, property, and other data-backed systems.
- [ ] Special feature domains found in the target data (for example actor, athlete, astronaut, casino, business, zoo, vampire, and seasonal systems).
- [ ] Death/obituary and post-life state.

## Phase 5 — UI, layout, assets, and audio

- [x] React/Vite/PWA shell exists in `web/`; production build verified with `npm run build`.
- [~] Basic life dashboard and scenario card exist; this remains a prototype, not full parity.
- [ ] Inventory and map extracted sprites/textures to semantic UI components.
- [ ] Reconstruct screen inventory and navigation from Unity UI/prefab/MonoBehaviour evidence.
- [ ] Reconstruct mobile portrait layout, spacing, colors, typography, icons, cards, menus, and modal behavior.
- [ ] Add responsive desktop layout without changing gameplay semantics.
- [ ] Integrate extracted fonts and verify fallback behavior.
- [ ] Convert/fix all supported music and sound clips to browser-supported formats.
- [ ] Map music/SFX to screen, event, and transition triggers.
- [ ] Recreate animations and feedback with CSS/Web Animations/Canvas where needed.
- [ ] Add accessibility and keyboard/touch controls without changing target flow.

## Phase 6 — Persistence, PWA, and packaging

- [ ] Replace prototype persistence with versioned IndexedDB save storage.
- [ ] Add save slots, autosave, export/import, migration, and corruption recovery.
- [~] PWA manifest/service-worker configuration exists.
- [ ] Verify offline boot and complete offline play after first load.
- [ ] Add asset/data cache versioning tied to the target APK build.
- [ ] Remove unnecessary Unity/mobile backend/analytics dependencies from the port.
- [ ] Produce a reproducible production build and deployment artifact.

## Phase 7 — Validation and parity

- [ ] Unit tests for RNG, stat mapping, clamps, conditions, substitutions, and CSV parsing.
- [ ] Golden fixtures for representative scenario rows and choice effects.
- [ ] Year-by-year regression fixtures for known life seeds.
- [ ] Cross-check static decompilation against runtime observations where possible.
- [ ] Visual comparison of each reconstructed screen against APK screenshots.
- [ ] Audio trigger and playback verification.
- [ ] Mobile browser QA: Chrome Android, Firefox Android, Safari iOS where available.
- [ ] Desktop QA and responsive layout checks.
- [ ] Performance/bundle-size audit for the full content corpus.
- [ ] Final coverage report: tables, assets, systems, screens, sounds, and unresolved gaps.

## Current verified starting point

- `out/il2cpp/dump.cs`: IL2CPP metadata dump.
- `out/decrypted/`: 965 decrypted CSV files.
- `out/datapack/`: extracted serialized-object outputs.
- `out/schema/types.ts` and `out/schema/types.json`: generated model schema.
- `out/ghidra/decompiled_8methods.c`: eight decompiled target methods.
- `out/REPORT_MECHANICS.md`: recovered mechanics notes, including Mono/System.Random and stat impact mapping.
- `web/`: existing React/Vite PWA prototype with data loader, RNG, stat shell, scenario shell, and basic life UI.

## Honest current state

The extraction foundation is strong, but the complete port is not finished. The current web app is a vertical-slice prototype, not a content-complete BitLife replacement. The largest remaining work is exact scenario/action interpretation, full simulation-domain implementation, UI/layout mapping, audio integration, and parity testing.

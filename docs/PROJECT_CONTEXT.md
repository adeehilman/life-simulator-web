# Life Simulator Web — Project Context

## Target and version policy

The semantic parity target is BitLife 3.25.3 (`com.candywriter.bitlife`). BitLife 3.26.0 is used only as a development/UI/runtime oracle until target-version fixtures are available. Every oracle artifact must retain its installed version label.

## Reproducible commands

```bash
cd web
npm install
npm run verify
```

The current web verification includes Vitest and a production Vite/PWA build.

## Current verified implementation

- 965 decrypted CSV tables are available in `web/public/data`.
- Data indexes describe approximately 63,110 rows and 221 scenario-like tables.
- The web port contains a Mono/System.Random-compatible generator with deterministic tests.
- RNG snapshots include the seed array, indices, and draw count; `Life.rngState` is persisted and restored.
- The annual web pipeline exposes and tests `simulation -> UI -> memory` hook ordering and reports consumed RNG draws.
- Scenario compilation preserves raw impacts, advanced logic, route metadata, cost, age-up flags, and blueprint payloads.
- Advanced logic supports grouping, negation, typed numeric/string values, comparisons, `contains`, and `in`.
- `web/src/engine/genesis.ts` implements typed Genesis filters and transactional state actions for variables, entities, transient objects, collections, slots, and feature containers. Unsupported blueprint types are diagnostics, not silent success.
- IndexedDB persistence, JSON import/export, migration, domain state, route queue, and RNG state are implemented as web-side behavior.
- Static IL2CPP artifacts and Ghidra reports are retained in the tracked evidence subset.

## Runtime instrumentation evidence

The Frida client and server are both version 17.24.3. The server was verified as UID 0 and Frida attached to the BitLife 3.26.0 process without mutating APK or save state.

The installed APK is ARM64 (`arm64-v8a`) running under WSA x86_64 translation. Its native split contains `libil2cpp.so` and `libunity.so`, but those modules were not mapped in the attached process during the probe window. The current blocker is native module loading in WSA, not Frida authentication. See:

- `out/oracle/frida-3.26.0/setup_evidence.json`
- `out/oracle/frida-3.26.0/probe_events.json`
- `out/oracle/frida-3.26.0/module_watch.json`

No native RVA hook was installed and no gameplay/RNG/save memory was changed.

## Security boundary

Do not commit APKs, credentials, authentication/session payloads, JWTs, refresh tokens, private PlayerPrefs, virtual environments, dependency caches, or generated build output. The private audit was deliberately retained only as redacted metadata.

## Completion rule

Do not mark the project 100% complete until all parity gates have evidence. The required final marker is:

```text
Status: [x] 100% COMPLETE
Final verification: PASS
Unexplained parity gaps: 0
```

Until then, report static, web-side, oracle, and target-version evidence separately.

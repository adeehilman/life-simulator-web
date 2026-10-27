# BitLife 3.25.3 — RNG call-site map (who draws, and from where)

Source: `work/native/libil2cpp.so` (sha256 `b69f574e…`, ELF32 ARM) + `out/il2cpp/script.json`
+ `out/il2cpp/method_by_address.json`.
Tools: `tools/find_callers.py` (whole-binary BL/BLX scan), `tools/callgraph.py`
(direct-call extraction with veneer resolution).

## 1. Direct callers of `DataHub.GetRandomNumber` @ `0x15C4E50`

**7 call sites, all inside `DataHub` itself** — it is a narrow internal content helper,
not the general-purpose roll:

| Caller | Call site |
|---|---|
| `DataHub.GetRandomBlackMarketMuseumName` | `0x016CBF1C` |
| `DataHub.CreateZooHabitatName` | `0x0173E15C` |
| `DataHub.GetRandomColorForCarType` | `0x017770DC` |
| `DataHub.GetRandomModelDiseaseType` | `0x0178631C` |
| `DataHub.GetRandomOrganicDiseaseForAgeAndGenderAndCareer` | `0x01786ADC` |
| `DataHub.GetRandomPositiveBuskScenario` | `0x017EB55C` |
| `DataHub.GetRandomCoworkerReactionToBossSocializeForGender` | `0x017FD91C` |

Artifact: `out/reverse-engineering/callers_getrandomnumber_3253.txt`

## 2. Direct callers of `GameReference.GetRandomNumber` @ `0x1F6E348`

**522 distinct methods, 620 call sites.** This is the workhorse RNG of the game.
Categories:

- **Scenario classes** (the majority): `Scenario*$$RefreshScenario`,
  `Scenario*$$ChoiceSelectedAtIndex`, `Scenario*$$ScenarioIsEligibleForRandomPush`, …
- **Annual `Sim*.IncrementAge`**:
  - `SimHero$$IncrementAge` — **5 sites** (`0x01A8BD54`, `0x01A8DDD4`, `0x01A8F4D4`,
    `0x01A91394`, `0x01A93854`)
  - `SimMuseum$$IncrementAge`, `SimSpyAgency$$IncrementAge` (2), `SimProbe$$IncrementAge` (2),
    `SimSpecialJobAstronaut$$IncrementAge`, `SimProduct$$IncrementAge`,
    `SimDealerCartel$$IncrementAge`, `SimSpecialJobMusician$$IncrementAge`,
    `SimSpecialJobPolitician$$IncrementAge`, `SimSibling$$IncrementAge`,
    `SimSoundCloudTrack$$IncrementAge`, `SocialMediaUtility$$IncrementAgeAddFollowers`
- **Push-scenario selection**: `DumbScenarioInterface$$GetARandomPushDumbScenario` — 2 sites
- **Genesis**: `Game.Genesis.BluePrints.BluePrintRandom$$ConditionSelected`,
  `Genesis.Controllers.GenesisMemory$$ProcessInject`
- **Person generation**: ~35 `PersonGenerator$$Generate*` methods
- **Other**: `ObituaryGenerator$$GenerateObituary` (4), `SimCult$$GetAnnualFollowers` (2),
  `SimCrypto$$SetupCryptoLifecycle` (3), `SimPlace$$RefreshMurderShortlistAndForce` (3), …

## 3. `Life.ValidateAndSetScenario` @ `0x02575954`..`0x02575DF4`

Boundary proven from `method_by_address.json` (next method `Life.IncrementAge` @ `0x02575DF4`),
size `0x4A0`, **80 direct calls, ZERO direct RNG calls.**

Named/veneer-resolved targets:

| Target | Address | Note |
|---|---|---|
| `System.Type$$GetMethod` | `0x047EC1B0` | reflection |
| `System.Reflection.MethodBase$$Invoke` | `0x046E983C` | reflection dispatch |
| `Dictionary<object,object>$$.ctor` / `Add` / `ContainsKey` | `0x03C76848` / `0x03C7764C` / `0x03C77898` | deck/tier registry |
| `Life$$YearsSinceScenario` | `0x0256FF74` | cooldown gate |
| `System.String$$Concat` | `0x04652728` | |
| `UnityEngine.Debug$$LogError` | `0x05013EE0` | error path |
| `DiagnosticsEmail$$SendEmail` | `0x019C0548` | |
| `Tracking.CrashReport$$FirebaseTracking` | `0x025367E0` | |

**Key finding:** `ValidateAndSetScenario` dispatches scenario logic through
**reflection** (`Type.GetMethod` → `MethodBase.Invoke`). The RNG draws therefore happen
inside reflectively-invoked methods and are **not statically traceable** from this entry
point. A port must reproduce the invoked methods' behaviour, not just the call graph.

Artifact: `out/reverse-engineering/callgraph_validate_and_set_scenario_3253.txt`

## 4. Consequence for per-year RNG draw mapping

- The **direct** annual draw is `GameReference.GetRandomNumber` from
  `Life.IncrementAgeSimulation` @ `0x0257AB20` (see `out/REPORT_RNG_3253.md` §8).
- Additional draws occur inside the `Sim*.IncrementAge` helpers that
  `IncrementAgeSimulation` calls, and inside reflectively-invoked scenario methods.
- `DataHub.GetRandomNumber` is **not** on the annual path directly; it serves
  content-name/disease/colour selection helpers.
- Exact per-year draw count therefore remains **not proven** — it needs either a
  runtime fixture (ARM64) or full transcription of the reflectively-invoked scenario
  methods. This is consistent with the standing "Tier-2 static only" limitation.

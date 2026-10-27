# Scenario engine recovery — BitLife 3.25.3

Source: `out/ghidra/decompiled_14methods.c`, `out/il2cpp/dump.cs`,
`out/il2cpp/script.json`, and the 965 decrypted CSV tables.

## Verified structure

- `Life.ValidateAndSetScenario` @ `0x2575954` is the annual scenario gate/queue path.
- `RandomDeckCollection.ValidateAndSetScenario` @ `0x1A6B61C` handles deck/tier selection and queue advancement.
- `Scenario.LoadDesignerFormat` @ `0x1D8BA6C` parses the modern designer format.
- `Scenario.CreateDesignerScenarioCondition` @ `0x1D98320` exists as a separate condition-construction stage.
- `Scenario.ParseDesignerBluePrintPayload` @ `0x1D97C08` parses blueprint payload data.
- `Scenario.LoadLegacyFormat` @ `0x1D909DC` handles legacy row loading.

## Important consequences for the port

1. Scenario selection is not a uniform random choice from all CSV rows. The APK uses
   tier/deck structures, eligibility gates, and queue state. The current web engine
   now applies age/gender/country/stat gates and `Commonness Score` weighting, but
   it is not yet a complete deck/queue implementation.
2. The modern designer schema has 54 enumerated columns. Relevant groups include:
   `ScenarioID`, `Style`, `Filter`, `HeroAge`, `Title`, `Body`, `RewardsGranted`,
   `Dropdowns`, `TableRows`, `Sliders`, `BarGraphs`, four choice text/style/route/
   impact/log/advanced-logic groups, blueprint payload, currency cost, age-up flag,
   focus tag, and draw filter.
3. A choice can have a route target and multiple domain-specific impact columns.
   The web compiler retains every authored `* Impact N` value, including domains
   that do not yet have a state handler (for example Flight, Karma, Job, Fitness,
   Technical, and Relationship).
4. The legacy and designer parsers must not be collapsed into one two-choice format.
   The web compiler supports the common 2–4-choice surface but does not yet execute
   all action lists, advanced logic, blueprint payloads, or route chains.
5. Ghidra's direct `FUN_*` name resolution is incomplete: 147 unique references were
   extracted from the 14-method output; only 2 match a `ScriptMethod` address directly.
   Many remaining calls are generic runtime helpers, vtable calls, metadata-usage
   wrappers, or addresses requiring IL2CPP registration resolution.

## Implemented web subset

- `web/src/engine/scenario.ts`
  - legacy `Scenario`/`Yes Choice`/`No Choice` rows;
  - designer `Body`/`Choice 1..4` rows;
  - route fields;
  - named `* Impact N` fields;
  - age, gender, country, and visible-stat gates;
  - `Commonness Score` weighted row selection;
  - placeholder resolution through the existing text loader.
- `web/src/engine/actions.ts`
  - applies authored stat impacts only to named stats;
  - preserves a legacy generic-impact fallback;
  - leaves unsupported domain effects recorded rather than silently applying them.

## Remaining exactness work

- Recover the deck/tier class list and its reset/consumption semantics.
- Implement `ScenarioCondition` and `AdvancedLogic` operators from blueprint payloads.
- Implement all `ScenarioAction`/choice effect target types.
- Implement route chains and follow-up queues.
- Resolve relationship/person focus state and all special-domain state models.
- Collect APK runtime fixtures to compare row eligibility, deck choice, and RNG call order.

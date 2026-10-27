# Mechanics recovery — 20-target Ghidra batch

Source: `out/ghidra/decompiled_20methods.c`, `out/il2cpp/dump.cs`, and `out/il2cpp/script.json`.

## Batch result

- Ghidra headless completed with exit code 0.
- Output: `out/ghidra/decompiled_20methods.c`.
- Size: 12,576 lines / 478,962 bytes.
- The original 14 targets are present.
- Six additional addresses were requested:
  - `0x1064660` — runtime/thunk helper reached from the decompiler, not a `Life` method in `dump.cs`.
  - `0x1F760A0` — `GameReference.AttributeAdjustmentPointsForImpactScore` in `dump.cs`.
  - `0x1D10B48` — `SimPerson.ImpactHappiness` in `dump.cs`.
  - `0x1D10C44` — `SimPerson.ImpactHealth` in `dump.cs`.
  - `0x15C11E4` — `DataHub.GetRandomNumber` in `dump.cs`.
  - `0x1F6E4B0` — `GameReference.GetRandomNumber` in `dump.cs`.

## What is safe to use

- The address/signature pairs above were rechecked against `dump.cs` before the run.
- The output is useful as a call-site and native-control-flow artifact.
- `Life.IncrementAge` still shows the three-phase calls already recorded: simulation, UI, then Genesis memory.
- `DataHub.GetRandomNumber` output visibly contains control flow and Unity/game data paths, but its register types and helper calls are not recovered sufficiently to replace the existing static RNG evidence.

## What is not safe to claim from this batch

- `0x1064660` is not evidence that the helper itself is the annual simulation body. It is the generic `thunk_FUN_01064660` target used by Ghidra in several places.
- The decompiler output for `GameReference.AttributeAdjustmentPointsForImpactScore` at this forced boundary is not a clean switch/table function; it contains unresolved object/runtime operations. Do not use it to alter the existing impact table without a better function boundary or runtime fixture.
- `SimPerson.ImpactHappiness` decompiled to an extremely small compare/return fragment with unresolved parameter typing. That is insufficient to prove the complete stat mutation rule.
- `SimPerson.ImpactHealth` contains thresholds and field writes, but `DAT_*` values, object fields, and helper semantics are unresolved. It is not yet a complete TypeScript specification.
- `GameReference.GetRandomNumber` is a Unity/runtime wrapper with unresolved vector/random types; it must not replace the verified `DataHub` RNG model.

## Next exact recovery step

1. Resolve the actual function boundaries in Ghidra rather than forcing a containing function at every RVA.
2. Decompile the IL2CPP method bodies with correct prototypes/structures from `il2cpp.h` and `dump.cs`.
3. Follow each unresolved `FUN_*`/`DAT_*` reference to its `ScriptMethod`, metadata usage, field offset, or literal-pool source.
4. Add a fixture before changing the web engine.

Until those steps are done, the web implementation remains limited to the rules in `out/REPORT_MECHANICS.md`; this batch increases evidence coverage but does not justify new parity claims.

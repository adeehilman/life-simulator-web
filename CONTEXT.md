# BitLife RE — Session Context (updated 2026-10-25)

Goal: port BitLife 3.25.3 (com.candywriter.bitlife) to web/PWA, rebuild as close to identical as possible.

## State summary

- **Il2CppDumper**: built from PR #903 branch (metadata v35-39 support) in `Il2CppDumper/` (branch `pr903`).
  Build: `dotnet build Il2CppDumper/Il2CppDumper.csproj -c Release -f net8.0`
  Run (from output dir): `dotnet <dll> work/native/libil2cpp.so work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat . < /dev/null`
  Outputs in `out/il2cpp/`: dump.cs (39MB), DummyDll/, script.json, il2cpp.h, stringliteral.json.
- **CIPHER SOLVED** — scenario CSV containers are base64 TextAssets named `*-enc` inside
  `work/abi/UnityDataAssetPack.apk` → `assets/bin/Data/datapack.unity3d` (37,478 objects).
  - `DecryptString = XORCipherString(b64decode(s), ObfuscateString(DefaultCipherKey()))`
  - `DefaultCipherKey() = "com.wtfapps.apollo16"`
  - ObfuscateString: lowercase letters through fixed 26-entry substitution table
    (a→z b→m c→y d→l e→x f→k g→w h→j i→v j→i k→u l→h m→t n→g o→s p→f q→r r→e s→q t→d u→p v→c w→o x→b y→n z→a)
  - XOR is offset 0: `plain[i] ^ key[i % len(key)]`
  - Effective key: `yst.odkzffq.zfshhs16`
  - Tool: `tools/decrypt_all.py` → outputs to `out/decrypted/` (965 CSVs decrypted, 12MB)
  - `a16_countries-enc` failed b64: it's an embedded .NET DLL, not encrypted CSV. Skip it.
  - Notebook: `tools/disasm2.py` — ARM disassembler with method-name resolution via script.json
  - Lesson: for PC-relative literal pool words with high byte 0xFF, interpret SIGNED

## Key paths

| Item | Path |
|---|---|
| XAPK | `dl/bitlife.xapk` |
| Base APK extracted | `work/apk/` |
| ABI split | `work/abi/config.armeabi_v7a.apk` |
| Asset pack | `work/abi/UnityDataAssetPack.apk` |
| libil2cpp.so | `work/native/libil2cpp.so` (ARM, not Thumb) |
| Global metadata | `work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat` (v39) |
| Il2CppDumper output | `out/il2cpp/` |
| Decrypted CSVs | `out/decrypted/` (965 files) |
| Old outputs | `out/strings.txt`, `out/scenarios/`, `out/assets/` (279 PNG), `out/audio/` (418 WAV), `out/fonts/` |
| Skills used | `unity-il2cpp-re` (load with skill_view for RE procedures) |

## Key dump.cs discoveries

- `EncryptionManager` (TypeDefIndex 53): XOR obfuscation cipher, all methods
- `DataHub` (1022): central data loader, hundreds of `_xxxSet` fields
- `Life` (1534): 318 fields — core per-life state model
- `StatType` (6219): Happiness/Health/Smarts/Looks/Essence/Fame/Reputation/Infamy/StreetSmarts/Performance/Greatness/Popularity/Approval/Charisma/Respect
- `ScenarioCSVHeaders` (5589), `DesignerCSVHeaders` (5555): CSV schemas
- `CSVDocument`/`CSVLine`/`CSVHeader` in `Genesis.CSV` namespace

## Remaining TODO (priority order)

1. ~~Il2CppDumper with v39 metadata~~ ✅
2. ~~Decrypt scenario CSV containers~~ ✅
3. ~~28 loose `\x00IAP` containers in `work/apk/assets/`~~ ⏸ DEFERRED — NOT same cipher.
   Magic `\x00IAP\x02\x00\x00\x00` = Unity IAP proprietary container (not base64 TextAsset,
   not UnityFS/UnityWeb/UnityRaw bundle). XOR w/ apollo16 key yields no structure.
   29 files (~187KB each, some 284-401KB), distinct headers = independent products/locales.
   Not needed for web port core; hardcode product catalog later if desired.
4. ~~Full asset dump~~ ✅ `tools/dump_datapack.py` → `out/datapack/` + `manifest.json`.
   37,478 objects catalogued; ~28K files extracted (8,155/8,158 tex PNG,
   sprites via own texture rects). Only failures:
   - 3 Font Texture (path_id 3063/4758/6364) — UnityPy dep-resolution bug
     w/ empty StreamData path; fonts exist as TTF in out/datapack/fonts/, skip.
   - 17 AudioClip FmodError:FORMAT (racing music/SFX) — Vorbis/ADPCM not
     decoded by this UnityPy build; can re-extract via FMOD or ffmpeg later.
5. ~~Data model → TypeScript/JSON schema~~ ✅ `tools/dump_schema.py` →
   `out/schema/types.json` + `types.ts`. Parses dump.cs top-level blocks:
   Life (318 fields), Scenario, StatType (bitflag enum: Happiness=1,
   Smarts=4, Looks=8...), SimHero, SimWorld, SimPerson (incl Att_* attribute
   set used in stat formulas), SimDeath. TS maps C# types: List<>→[], 
   Dictionary→{[k]:v}, backing-fields `<X>k__BackingField`→X.
6. Game mechanics: decompile key methods (IncrementAge, stat formulas, RNG) via Ghidra + script.json, or Frida runtime
   - IN PROGRESS. Ghidra 12.2 headless installed (JDK 25 needed; JDK21 insufficient).
     Env: JAVA_HOME=C:\Users\Ade\jdk25\jdk-25.0.4.1+1, GHIDRA dir C:\Users\Ade\ghidra_extract\
     Project C:\Users\Ade\ghidra_proj (BitLife:/libil2cpp.so, analyzed ~67min, 2.9GB).
     Script tools/ghidrawrite/DecompileKeyMethods.java — force-create fn at RVA
     (remove overlapping FUN_ first), disassemble, AddressSet body,
     SourceType.USER_DEFINED; run via run_headless2.cmd with -noanalysis.
   - Output: out/ghidra/Life_IncrementAge.c (4984 lines C pseudo-code).
     out/ghidra/decompiled_4methods.c — 4 methods, 5043 lines:
     Life.IncrementAge / IncrementAgeSimulation / IncrementAgeUI /
     Sim.UpdateStatesForAge.
     out/ghidra/decompiled_6methods.c — + UnityEngine.Random.Range(float/int):
       RangeFloat = thin vtable delegate; RangeInt calls native FUN_050473f8 +
       telemetry. RNG itself is Unity builtin (not custom) → web port can use
       any seeded PRNG; exact sequence not needed for identical-feel rebuild.
     out/ghidra/decompiled_8methods.c — + ZooAnimal.GetHappiness(zoo) 0x1BDB3CC,
       SimPerson.GetSmarts 0x1BDB8E8: stat getters read from LOOKUP TABLES
       (DAT_... + index*4, branch on *(r5+0x1c) = gender), not arithmetic.
       → web port: replicate tables from CSV/dump, not formulas.
     RVAs so far: Life.IncrementAge 0x2575DF4 / Sim 0x2575E18 / UI 0x257B1AC /
     UpdateStatesForAge 0x1D18318 / Random.Range float 0x5047DB8 int 0x5047E0C /
     GetHappiness(zoo) 0x1BDB3CC / GetSmarts 0x1BDB8E8.
   - Pitfall: dump.cs RVAs = ELF virtual addresses in Ghidra directly
     (MIN=00010000); getFunctionContaining returns wrong giant FUN_ unless
     function re-created explicitly.
- Web/PWA build
- Master port checklist: `PORT_TODO.md` (created 2026-10-26; tracks exact-content, mechanics/RNG, UI/layout, music, persistence, and parity validation)
- PWA baseline: `web/` builds successfully with `cd web && npm install && npm run build`; output is `web/dist/` with 965 CSV tables precached.

## Environment notes

- Python for scripts: `C:/Program Files/FlyEnv-Data/app/python-3.14.6/python.exe` (has UnityPy, capstone)
- `python` (hermes venv) has no pip; use the FlyEnv one
- Windows MSYS bash; use POSIX syntax; native Windows paths for native tools

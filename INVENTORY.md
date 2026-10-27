# BitLife RE — Inventaris Bahan (updated 2026-10-26)

Semua aset & data yang berhasil diekstrak dari BitLife 3.25.3
(com.candywriter.bitlife), siap untuk port web/PWA.

## Ringkasan status

| TODO | Status |
|---|---|
| 1. Il2CppDumper v39 metadata | ✅ |
| 2. Decrypt scenario CSV | ✅ |
| 3. Loose `\x00IAP` containers | ⏸ DEFERRED (bukan cipher sama) |
| 4. Full asset dump datapack | ✅ |
| 5. Data model → TS/JSON schema | ✅ |
| 6. Game mechanics via Ghidra | 🔶 BERJALAN (8 method terdecompile) |
| 7. Web/PWA build | ⬜ BELUM |

---

## Inventaris file

### A. Kode & metadata IL2CPP — `out/il2cpp/`
- **dump.cs** — 39 MB, ~1,137,000 baris: seluruh definisi class/struct/enum/method + RVA.
- **script.json** — method-name ↔ address mapping (untuk disasm / resolusi nama).
- DummyDll/, il2cpp.h, stringliteral.json.

### B. Data game terdecrypt — `out/decrypted/` (965 CSV)
- Semua scenario/data CSV dari datapack.unity3d, didecrypt dengan cipher XOR
  (`DefaultCipherKey = "com.wtfapps.apollo16"`, obfuscate table a↔z dst.).
- Contoh: a16_birth-circumstances.csv, a16_zoo-fundraiser.csv, dst.
- Pengecualian: `a16_countries-enc` = DLL .NET embedded (skip).
- Cipher tool: `tools/decrypt_all.py`.

### C. Aset grafis & audio — `out/datapack/` (36,490 file)
Dari datapack.unity3d via UnityPy (`tools/dump_datapack.py`):
- **textures/** — PNG sprite/texture (~8 ribu)
- **sprites/** — PNG per-sprite
- **audio/** — WAV (~418 clip; sebagian gagal FmodError:FORMAT = Vorbis/ADPCM)
- **fonts/** — TTF font
- **text/** — TextAsset non-terenkripsi
- **meshes/, materials/, shaders/, animations/, scripts/(raw MonoBehaviour)**
- manifest.json di root folder mencatat semua objek + path_id.

Bonus lama:
- `out/assets/` (697 file), `out/scenarios/` (91), `out/fonts/` (4),
  `out/scenario_catalog.json` (~105 KB katalog scenario).

### D. Schema data model → TypeScript — `out/schema/`
Dihasilkan oleh `tools/dump_schema.py` dari dump.cs:
- **types.ts** — interface TS lengkap: Life (318 fields), Scenario,
  StatType enum bitflag (Happiness=1..Respect=16384), SimPerson (+ Att_* attrs),
  SimWorld, SimDeath.
  501+ baris TypeScript.
- **types.json** — versi raw JSON dari schema yang sama.

### E. Decompiled game mechanics via Ghidra — `out/ghidra/*.c`
Ghidra headless + script Java (`tools/ghidrawrite/decompile_key_methods.java`)
decompile method kunci ke pseudo-C:
1. **Life_IncrementAge.c** (@0x2575DF4) + decompiled_4methods.c —
   orkestrasi penuaan tahunan.
2. **decompiled_6methods.c** (+ Random.Range float/int @0x5047DB8/@0x5047E0C).
3. **decompiled_8methods.c** (+ ZooAnimal.GetHappiness @0x1BDB3CC,
   SimPerson.GetSmarts @0x1BDB8E8). Total ~5270 baris pseudo-C.

Insight inti:
1. Stat getter = lookup table (`GetSmarts`: array DAT... + idx*4,
   branch gender @ r5+0x1c) → replikasi tabel bukan formula.
2. UpdateStatesForAge = rata-rata akumulasi stat per tahun (`fVar1/fVar4`).
3. RNG = Unity builtin → seeded PRNG apa pun cukup utk port.

### F. String & naratif terpisah topik — `out/strings_by_topic/*`
careers / choices / crime / health / money / narrative /
relationships / ui (.txt).

---

## Alat-alat kunci

| Tool | Fungsi |
|---|---|
| tools/disasm2.py | ARM disassembler + resolusi nama via script.json |
| tools/dump_datapack.py | Ekstraksi penuh datapack.unity3d → out/datapack |
| tools/dump_schema.py | dump.cs → types.ts/types.json |
| tools/dump_schema.py argumen tambahan utk tipe lain    |

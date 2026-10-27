# STATUS REPORT — Audit Reverse Engineering BitLife 3.25.3

Audit ini dikoreksi pada 2026-10-27. Target aktif adalah BitLife 3.25.3/versionCode 1066; artifact 3.26.0 hanya referensi delta.

Audit status didasarkan pada file dan output yang ada di workspace. Pasangan native/metadata target 3.25.3 konsisten: `work/native/libil2cpp.so` identik dengan member `lib/armeabi-v7a/libil2cpp.so` pada `work/abi/config.armeabi_v7a.apk`; ELF32 ARM adalah arsitektur yang benar untuk split target ini.

## 1. Ringkasan

Tahap A — Pemetaan: sekitar 75%; binary, metadata, dump.cs, script.json, dan address map tersedia.
Tahap B — Penelusuran: sekitar 45%; output pseudocode dan laporan statis tersedia, tetapi boundary/prototype dan 145/147 referensi FUN belum terselesaikan.
Tahap C — Clone: sekitar 5%; belum ada folder `clone/`, implementasi Python, atau test clone.
Kondisi saat ini: bukti statis cukup untuk kandidat RNG dan urutan tiga fase annual, tetapi belum cukup untuk exact annual transition atau clone Python tervalidasi.

## 2. Sudah selesai (terbukti)

| Item | Tahap | Bukti (path file / RVA / output) |
|---|---|---|
| Binary native 3.25.3 tersedia dan tervalidasi | A | `work/native/libil2cpp.so`, 93,898,144 bytes; SHA-256 `b69f574e...`; identik dengan member `work/abi/config.armeabi_v7a.apk:lib/armeabi-v7a/libil2cpp.so`; ELF32 ARM (`EI_CLASS=1`, `e_machine=0x28`) benar untuk target. |
| APK dan hasil ekstraksi tersedia | A | `BitLife.apk`, 141,217,414 bytes; direktori `work/apk/` dan `work/abi/` tersedia. |
| Global metadata tersedia | A | `work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat`, 19,174,212 bytes. `CONTEXT.md:33` menyebut metadata v39. |
| Il2CppDumper dump tersedia | A | `out/il2cpp/dump.cs`, 39,417,073 bytes; `out/il2cpp/DummyDll/` tersedia. |
| Script method map tersedia | A | `out/il2cpp/script.json`, 104,976,229 bytes; `out/il2cpp/method_by_address.json`, 19,702,909 bytes. |
| Schema Life tersedia | A | `out/schema/types.ts`, `out/schema/types.json`; `out/EVIDENCE_LEDGER.json` mencatat 318 parsed fields. |
| Kandidat RNG DataHub terpetakan | A/B | `DataHub$$GetRandomNumber` pada `0x015c4e50` di `out/il2cpp/method_by_address.json`; signature ada di `out/il2cpp/script.json`; interpretasi juga ada di `out/REPORT_MECHANICS.md`. |
| Kandidat stat impact terpetakan | A/B | `GameReference$$AttributeAdjustmentPointsForImpactScore` pada `0x01f760a0` di `out/il2cpp/method_by_address.json`; signature/RVA juga ada di `out/il2cpp/dump.cs`. |
| Kandidat annual entry points terpetakan | A/B | `Life$$ValidateAndSetScenario` `0x02575954`, `Life$$IncrementAge` `0x02575df4`, `Life$$IncrementAgeSimulation` `0x02575e18`, `Life$$IncrementAgeUI` `0x0257b1ac` di `out/il2cpp/method_by_address.json`. |
| Pseudocode annual tersedia | B | `out/ghidra/decompiled_14methods.c` dan `out/ghidra/decompiled_20methods.c`; laporan menyebut output Ghidra 20-target tersedia. |
| Urutan tiga fase annual teridentifikasi | B | `out/REPORT_MECHANICS.md:123-138` dan `out/EVIDENCE_LEDGER.json` item `age.pipeline`: simulation → UI → Genesis memory snapshot. Ini hanya membuktikan urutan tingkat tinggi, bukan seluruh logic annual. |
| Model RNG Mono tersedia di web | B/C preparatory | `web/src/rng.ts`, `web/src/core.test.ts`; test snapshot/restore dan known seed-1 sequence ada. Ini adalah implementasi TypeScript, bukan clone Python atau bukti seed APK. |
| RNG native candidate teridentifikasi | B | `out/il2cpp/dump.cs` menunjukkan `DataHub.getrandom` dan `GameReference.getrandom` sebagai static `System.Random`; routing dan seeding sudah dipulihkan di `out/REPORT_RNG_3253.md`. |
| RNG routing & seeding (BARU) | B | `out/REPORT_RNG_3253.md`: kedua `.cctor` membuat `new Random()` parameterless (veneer `0x20B89A4` → `System.Random..ctor` `0x047E0BA4` → `GenerateSeed` `0x047E0C10` → `Random(int)` `0x047E0DFC`); `GetRandomNumber` memanggil `Random.Next(min,max)` (max eksklusif) di bawah `Monitor.Enter/Exit`; `GameReference` clamp `max<=1 → 1`. |
| Annual RNG routing (BARU) | B | `tools/callgraph.py` + `out/reverse-engineering/callgraph_increment_age_simulation_3253.txt`: `Life.IncrementAgeSimulation` (`0x02575E18`..`0x0257B1AC`) memanggil `GameReference.GetRandomNumber` di `0x0257AB20`; TIDAK ada panggilan `UnityEngine.Random` di jalur annual. |
| Unity Random teridentifikasi sebagai API terpisah | B | `out/il2cpp/method_by_address.json` memuat `UnityEngine.Random$$Range` pada `0x05047db8`, `0x05047e0c`, `RandomRangeInt`, dan `get_value`. Ini tidak membuktikan bahwa annual DataHub RNG memakai Unity Random. |
| Test web tersedia | C preparatory | `web/src/core.test.ts`; mencakup MonoRandom, annual pipeline web, persistence, Genesis, scenario, dan domain registry. Tidak ada test di `clone/`. |
| Script Python analisis tersedia | A/B | `tools/` berisi script antara lain `decrypt_all.py`, `dump_schema.py`, `disasm2.py`, `parity_report.py`, `brute_prng_seed.py`, `test_prng_seed.py`, dan `tools/ghidra/decompile_key_methods.py`. |
| Evidence ledger tersedia | Audit | `out/EVIDENCE_LEDGER.json`, 188 baris; berisi status `static-verified`, `partially-verified`, `blocked`, dan known gaps. |
| Frida blocker terdokumentasi | B | `out/oracle/frida-3.26.0/setup_evidence.json` mencatat ARM64 APK pada WSA x86_64/Houdini, `libil2cpp.so` tidak mapped, dan tidak ada RVA hook. Ini mendukung keputusan memakai jalur statis. |

## 3. Sebagian / belum terverifikasi

| Item | Apa yang sudah ada | Apa yang kurang |
|---|---|---|
| Decode metadata melalui REA | `global-metadata.dat` ada; output dump dan model ada; `CONTEXT.md` menyebut v39 | Tidak ada laporan REA khusus yang mengikat hasil decode ke setiap kandidat RNG/annual. Status decode per struktur tidak dapat dibuktikan lebih jauh dari artifact yang tersedia. |
| Pemetaan kandidat → RVA → binary | `dump.cs`, `script.json`, `method_by_address.json`, dan `libil2cpp.so` ada; beberapa pasangan RVA/name terdokumentasi | Belum ada tabel audit lengkap kandidat RNG/annual dengan validasi boundary terhadap binary untuk seluruh kandidat. |
| Boundary/prototype annual | `out/ghidra/decompiled_14methods.c`, `decompiled_20methods.c`, dan `REPORT_MECHANICS_20METHODS.md` tersedia | Laporan sendiri menyatakan boundary/prototype belum bersih dan type/helper belum terselesaikan. `Life.IncrementAgeSimulation` belum ditranskripsi menjadi urutan exact. |
| RNG `DataHub.GetRandomNumber` | RVA `0x15C4E50`, static `System.Random`, dan model Mono terdokumentasi | Seed aktual APK, call order, jumlah draw per annual, dan hubungan setiap draw dengan event belum terbukti dari runtime atau fixture target. |
| Seed source | `REPORT_MECHANICS.md` menyebut `DataHub..cctor` `0x18B0B30` tanpa explicit seed dan `Environment.TickCount` | Tidak ada fixture/output runtime yang mengonfirmasi seed aktual atau initial internal state. Status harus tetap belum terverifikasi untuk APK. |
| Exact annual transition | Tiga fase tingkat tinggi dan beberapa candidate method tersedia | Stage order lengkap, gate flags, stat mutation, disease/injury/addiction/death, relationship, scenario selection, dan year-by-year state diff belum lengkap. |
| Stat mutation | Laporan menguraikan kandidat impact table `-6..6`, clamp, dan age guard; RVA `0x1D10A3C`/`0x1D10B48` disebut di report | `REPORT_MECHANICS_20METHODS.md` menyatakan decompile forced boundary dan unresolved fields/helpers belum cukup membuktikan spesifikasi lengkap. Beberapa `ImpactHappiness` overload juga ada, sehingga owner class harus divalidasi sebelum dipakai. |
| Ghidra project | Script Ghidra dan output C ada di `tools/ghidra/`, `tools/ghidrawrite/`, `out/ghidra/` | Tidak ada file project Ghidra (`*.gpr`, `*.rep`, `*.gzf`, `*.gdt`, `*.i64`, `*.idb`) di workspace saat audit. `CONTEXT.md` menyebut project eksternal, tetapi file project itu tidak ada di root ini dan tidak diverifikasi. |
| FUN/DAT resolution | `out/ghidra/fun_resolution_14methods.json` ada | Hanya 2 resolved dari 147 dan 145 unresolved; laporan tidak mendukung klaim bahwa annual body atau semua dependency telah recovered. |
| RNG hypothesis script | `tools/test_prng_seed.py` mengimplementasikan generator Mono dan pencarian seed kandidat | Tidak ada output run/result match yang tersimpan; script bukan clone Python final dan bergantung pada `tools/crib_drag.py`. |
| Python reconstruction | Ada script Python analisis di `tools/` | Tidak ada `clone/`, package Python clone, model annual final, atau test Python clone. |
| Web annual pipeline | `web/src/engine/life.ts` dan `web/src/core.test.ts` menguji simulation → UI → memory serta draw count | Ini hanya behavior web yang dirancang/diuji; belum dibuktikan sama dengan annual pipeline APK. |
| Version alignment | Target aktif BitLife 3.25.3/versionCode 1066; native/metadata pair konsisten. `input/3.26.0/` dan `out/3.26.0/` terpisah sebagai reference-only | Fixture oracle 3.25.3 baru masih perlu dicatat; artifact 3.26.0 tidak boleh dipakai sebagai target evidence. |
| Output `out/` | Seluruh folder `out/` ada dan diinventarisasi: 38,940 file, sekitar 1,069,335,820 bytes; file teks/JSON dapat dipindai | Banyak output adalah generated/extraction artifacts; keberadaan file tidak sama dengan validasi isi atau semantic parity. |
| Catatan khusus | `out/REPORT_MECHANICS.md`, `REPORT_MECHANICS_20METHODS.md`, ledger, dan `CONTEXT.md` ada | Folder `notes/` tidak ada. Informasi yang disebut akan berada di `notes/` tidak dapat diaudit. |

## 4. Belum dikerjakan

1. Membuat folder `clone/` dan baseline Python yang terpisah dari implementasi TypeScript.
2. Menentukan dan memvalidasi owner class untuk setiap kandidat `GetRandomNumber`, `System.Random`, `UnityEngine.Random`, `IncrementAge`, dan stat mutation.
3. Memperbaiki function boundary dan prototype Ghidra untuk `Life.IncrementAgeSimulation` serta helper annual yang relevan.
4. Menyelesaikan referensi `FUN_*`/`DAT_*` yang diperlukan untuk RNG dan annual; saat ini ledger mencatat 145 unresolved dari 147 pada set 14-method.
5. Menyusun tabel call graph annual berbasis alamat dan pseudocode yang telah divalidasi, bukan hanya urutan tiga fase tingkat tinggi.
6. Membuktikan seed source dan internal state APK secara statis atau melalui fixture yang kompatibel; bukti runtime WSA saat ini tidak tersedia.
7. Merekonstruksi exact annual transition ke Python, termasuk RNG consumption, gate flags, stat mutation, disease/injury/addiction/death, relationship, dan scenario selection.
8. Menulis test Python untuk setiap rule yang sudah memiliki alamat + interpretasi + expected output.
9. Membuat fixture deterministic dari binary/metadata yang menghubungkan input annual, state sebelum, draw sequence, dan state sesudah.
10. Membandingkan hasil clone Python dengan fixture APK target dan memisahkan delta 3.26.0 dari target 3.25.3.

## 5. Blocker & risiko

- **Tidak ada proyek Ghidra di workspace:** hanya output C dan script yang tersedia; salin/export project atau sediakan path yang dapat diaudit agar status analisis project dapat diverifikasi.
- **145/147 FUN unresolved:** helper dan field semantics belum cukup untuk menyatakan pseudocode sebagai exact; prioritaskan hanya dependency yang dilalui RNG/annual.
- **Function boundary/prototype belum bersih:** forced decompile dapat menggabungkan fungsi atau salah tipe; validasi boundary dari `dump.cs`, symbol map, dan disassembly sebelum cloning.
- **WSA ARM64-on-x86_64:** evidence menunjukkan `libil2cpp.so` dan `libunity.so` tidak mapped; jangan memakai hasil Frida sebagai bukti call order atau seed.
- **Pemisahan versi:** target aktif adalah 3.25.3/versionCode 1066 dengan pasangan native/metadata konsisten; `input/3.26.0/`, `out/3.26.0/`, dan oracle 3.26.0 adalah reference-only untuk delta, bukan target parity.
- **Folder `clone/` dan `notes/` tidak ada:** target deliverable Python dan catatan terstruktur belum tersedia; buat hanya setelah audit ini, pada instruksi berikutnya.
- **Generated output sangat besar:** `out/` sekitar 1.07 GB dan berisi banyak artifact hasil ekstraksi; keberadaan artifact bukan jaminan setiap klaim di dalamnya tervalidasi.
- **Tidak ada output test Python seed:** `tools/test_prng_seed.py` hanya membuktikan adanya hipotesis/alat, bukan adanya seed match.
- **Runtime fixture target tidak ada:** tanpa fixture state-before/state-after dan draw trace, exact annual clone tidak dapat divalidasi.

## 6. Temuan kunci sejauh ini

| Area | Class/method | RVA / bukti | Kesimpulan yang boleh diambil |
|---|---|---|---|
| RNG utama yang terdokumentasi | `DataHub.GetRandomNumber(int min, int max)` | `0x015C4E50`; `out/REPORT_MECHANICS.md:13-27`; `out/il2cpp/script.json` | Sumber yang dilaporkan adalah satu static Mono `System.Random`, bukan `UnityEngine.Random`. Ini static-verified, bukan runtime-seed-verified. |
| RNG runtime implementation | `System.Random.Sample`, `InternalSample`, `Next`, `NextDouble` | `out/il2cpp/method_by_address.json` sekitar entry `0x047e1060`–`0x047e1438` | Method implementation metadata tersedia; exact APK state/call sequence belum ditemukan. |
| Static initializer yang dilaporkan | `DataHub..cctor` | `0x018B0B30` di `out/REPORT_MECHANICS.md` | Report menyatakan no explicit seed/`Environment.TickCount`; initializer body belum dibuktikan di fixture runtime. |
| RNG API lain | `UnityEngine.Random.Range`, `RandomRangeInt`, `get_value` | `0x05047DB8`, `0x05047E0C`, dan entries terkait di `out/il2cpp/method_by_address.json` | Unity RNG memang ada sebagai API terpisah. Tidak boleh disamakan dengan `DataHub.GetRandomNumber` tanpa call-site proof. |
| Annual entry | `Life.IncrementAge()` | `0x02575DF4` | Method dan pseudocode tersedia; exact full transition belum recovered. |
| Annual simulation | `Life.IncrementAgeSimulation()` | `0x02575E18` | Candidate body tersedia di decompile; report menyatakan sequencing detail belum ditranskripsi/validated. |
| Annual UI | `Life.IncrementAgeUI()` | `0x0257B1AC` | Phase-level call tersedia; internal UI semantics bukan annual state proof. |
| Scenario selection | `Life.ValidateAndSetScenario()` | `0x02575954` | Report/ledger menyatakan tier/deck/queue structures teridentifikasi; weighting dan exact deck semantics masih open. |
| Stat impact mapping | `GameReference.AttributeAdjustmentPointsForImpactScore(int)` | `0x01F760A0` | Report menyatakan clamp `-6..6` dan table `-100,-50,-30,-16,-8,-4,[tunable],4,8,16,30,50,100`; index 0 masih tunable/unresolved. |
| Stat mutation candidate | `SimPerson.ImpactHappiness(int)` | `0x01D10A3C`; sibling `ImpactHealth` `0x01D10B48` menurut `REPORT_MECHANICS.md` | Candidate clamp/age behavior terdokumentasi, tetapi `REPORT_MECHANICS_20METHODS.md` menyatakan forced-boundary output belum cukup untuk complete TypeScript specification. |
| Native annual phase order | `Life.IncrementAge` → simulation/UI/Genesis memory | `out/REPORT_MECHANICS.md:123-138`, `out/ghidra/decompiled_14methods.c` | Hanya urutan tingkat tinggi yang terbukti: simulation → UI → memory snapshot. |

## 7. Langkah berikutnya yang disarankan

1. `out/il2cpp/dump.cs`, `out/il2cpp/script.json`, `out/il2cpp/method_by_address.json`, `out/ghidra/decompiled_14methods.c`: buat tabel kandidat-to-address untuk `DataHub.GetRandomNumber`, `System.Random`, `IncrementAge*`, dan helper yang langsung dipanggil; hasil yang diharapkan adalah daftar boundary/prototype tervalidasi tanpa menambah klaim baru.
2. `out/ghidra/decompiled_20methods.c`, `out/ghidra/fun_resolution_14methods.json`, `out/REPORT_MECHANICS_20METHODS.md`: resolve hanya dependency annual/RNG yang relevan dan tandai setiap `FUN_*`/`DAT_*` yang masih unknown; hasil yang diharapkan adalah call graph annual parsial dengan coverage dan unknowns eksplisit.
3. `clone/` dan test Python baru: setelah rule statis memiliki address + interpretasi, implementasikan MonoRandom dan satu annual slice kecil dengan fixture lokal; hasil yang diharapkan adalah test Python pertama yang membuktikan rule tertentu tanpa mengklaim exact APK annual parity.

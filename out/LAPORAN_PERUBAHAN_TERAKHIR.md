# Laporan — Lacak Perubahan Terakhir di Kode

**Proyek:** reverse-engineer-bitlife (port BitLife 3.25.3 → web/PWA)
**Tanggal lacak:** 2026-10-25
**Metode:** urutan mtime file + isi script; bukan git repo tunggal (root bukan git, dua subdir `Il2CppDumper/` & `bitlife-edit/` adalah repo terpisah).

---

## Ringkasan eksekutif

Kerjaan terakhir **bukan** di area RE binary lagi — fase decrypt selesai dan kerjaan aktif sudah pindah ke **membangun mesin game web**. Rangkaian perubahan paling baru (16:00→16:34) membangun fondasi PWA yang jalan: port RNG Mono, stat engine, siklus umur, pemilih skenario dari CSV asli, dan scaffold Vite+React+TS+PWA.

---

## Kronologi perubahan (terbaru → terlama)

| Waktu | Area | Apa yang berubah |
|---|---|---|
| **16:34** | `web/src/App.tsx`, `main.tsx` | UI React lengkap: boot → setup (negara/kota) → playing → dead. HUD stat + delta, log hidup, obituari |
| **16:32–16:31** | `web/src/engine/{scenario,names,life}.ts` | Mesin permainan TS |
| **16:30–16:29** | `web/src/data/{text,loader}.ts`, `csv.ts`, `rng.ts`, `index.html`, `package.json` | Loader CSV lazy+cache + index JSON; parser CSV replika game; port MonoRandom; scaffold Vite |
| **16:28** | `web/public/data/*.csv` (965 file) + dicopy dari corpus decrypt |
| **16:27–16:26** | `out/REPORT_MECHANICS.md`, `out/REPORT_LOOSE_CONTAINERS.md` + model gen dipakai (`web/src/model/*.ts`) |
| **~16:17–15:58** | `tools/gen_model.py`, lalu serangkaian percobaan dekripsi "loose container": find_bl → twotime/twotime2 → beam.py / beam2.py / beam8.py (+ model2-4.pkl), akhirnya decrypt_loose.py |

Catatan waktu diratakan karena semua file dalam satu sesi kerja kontinu ~1 jam.

---

## Detail per area

### 1. Web/PWA — fondasi game (`web/`) — PALING BARU
Scaffold Vite+React+TS+PWA (`vite-plugin-pwa`, registerSW). Sudah ada:
- **`src/rng.ts`** — port verbatim Mono `System.Random`. Kunci penting dari RE (§1 REPORT_MECHANICS): game pakai satu static System.Random via DataHub.GetRandomNumber @0x15C4E50; Math.random() tidak setara.
- **`src/stats.ts`** — StatType bitmask eksak (powers of two), tabel impact -6..6→poin persis binary (§2), clamp ≥100/≤0 sticky (§3), guard umur ≤4 untuk dampak negatif.
- **`src/csv.ts`** — splitter regex replika DataHub.CSVParser.
- **`src/data/{loader,text}.ts`**, engine life/scenario/names — siklus umur 3 fase (§4 IncrementAge), pemilih skenario berbobot kondisi.
- Model TS digenerate otomatis dari dump.cs oleh gen_model.py ke folder ini.

### 2. Report mekanik (`out/*.md`)
Dua laporan teknis ditulis dekat dengan fase ini:
- **REPORT_MECHANICS.md**: RNG System.Random @0x15C4E50; tabel impact @0x1F760A0; SimPerson ImpactHappiness @0x1D10A3C; IncrementAge @0x2575DF4 (sim→UI→memory); StatType bitmask; save cipher SecurityHelper.Cryption @0x25DA620.
- Istilah "open": tubuh IncrementAgeSimulation (~0x5300B), tunable impact index 0, RandomDeckCollection weighting.

### 3. Loose container crack (`tools/*`)
Rantai percobaan paling intens di sesi ini:
```
find_bl.py (cari magic) 
→ twotime/twotime2.py + model{2..4}.pkl (statistik two-time pad)
→ beam.py / beam2.py / beam8.py (beam search decode)
→ decrypt_loose.py <-- final
```
Hasil akhir tercatat di REPORT_LOOSE_CONTAINERS.md:
- Format container \x00IAP verified pada semua 28 file.
- Header row semua grup ter-dekripsi pasti.
- Body hanya pulih statistik sebagai two-time pad (~68% keystream cocok antar anggota grup). Cukup buat dibaca/dikutip, belum buat feed parser.
- Arah solusi berikutnya disarankan Frida hook pada SecurityHelper.Decrypt saat boot.

### 4. Asset dump penuh (`tools/dump_datapack.py`)
Dump seluruh objek datapack.unity3d ke out/datapack/: manifest.json (~37k objek), PNG sprite/texture, WAV audio, font TTF/Mesh OBJ/MonoBehaviour raw bin per tipe bucket.

---

## Status terhadap CONTEXT.md TODO

| TODO CONTEXT.md (#prioritas lama) | Status sekarang |
|---|---|
| Il2CppDumper v39 metadata ✅✅(lama) | Selesai jalur build pr903 |
| Decrypt scenario CSV ✅✅(lama) | Selesai via XOR key b64 TextAsset -enc |
| ~~Decrypt loose \x00IAP~~ (#3 lama) | Header solved total; body hanya partial statistik (**belum tuntas**) |
| Full asset dump (#4 lama) ⏳**(MAJU)** kini jalan via dump_datapack.py → out/datapack/manifest.json + sprites/textures dsb |
| Data model TS (#5 lama) ⏳**(MAJU)** kini jalan via gen_model.py → web/src/model/, enums/index/gameplay namespaces saja |

> Prioritas nomor pada baris CONTEXT didasarkan urutan teks asli ("Remaining TODO"), bukan angka eksplisit di file itu sendiri kecuali #1/#2 diberi strikethrough ✅.

---

## Di mana perubahan terakhir *benar-benar* berada

Puncak aktivitas = direktori tersembunyi bernama `.git/index`
— bukan itu maksudnya.** Jawaban singkat:**

Perubahan kode terbaru = folder **`web/src/**`. File termuda seluruh repo = 
```
Il2CppDumper/.git/index        18:03   <- cuma artefak git checkout PR #903
bitlife-edit/.git/index        18:03   <- artefak git clone support
CONTEXT.md                     15:03
```
File kode termuda yang bermakna = 
```
web/src/main.tsx                16:34   <- entry PWA registerSW
web/src/App.tsx                 16:34   <- UI React penuh
web/src/model/<153 .ts>          ~16    <- hasil gen_model dari dump.cs
```

Intinya dua hal paralel digarap paling baru:
1. **(Selesai/menuju selesai)** Port mesin permainan ke TS di web/: RNG Mono verbatim + stat engine eksak + loader CSV asli + UI playable pertama.
2. **(Terbuka/belum tuntas)** Dekripsi body loose \x00IAP container hanya partial-statistik; header sudah pasti tapi isi belum bisa diparse penuh tanpa Frida runtime hook.

Kedua-duanya mengarah langsung pada TODO #7 "Web/PWA build" yang sekarang sudah mulai berdiri dan bisa dimainkan dasar-dasarnya.

---
*Laporan digenerate dari inspeksi mtime & isi source tree.*

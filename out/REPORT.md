# BitLife 3.25.3 — hasil reverse engineering

Paket: `com.candywriter.bitlife`, versionName 3.25.3, versionCode 1066, minSdk 25, targetSdk 35.
APK ini base split (`requiredSplitTypes="base__abi"`), jadi `lib/*.so` tidak ada di dalamnya;
kode native il2cpp ada di split ABI terpisah. Metadata il2cpp tetap ada di base.

## Yang berhasil diambil

| Output | Isi |
|---|---|
| `out/strings.txt` | 72 143 string literal game dari `global-metadata.dat`: nama skenario, narasi, dialog, semua pilihan, data gameplay |
| `out/scenarios/` | Katalog skenario per kategori milik game (89 kategori, 1 090 skenario) + 1 686 kelas skenario tanpa path |
| `out/strings_by_topic/` | Korpus string dipilah: choices, narasi, karier, uang, relasi, kriminal, kesehatan, UI |
| `out/assets/` | 279 sprite/tekstur PNG dari bundle Unity |
| `out/audio/` | 418 audio WAV |
| `out/scenarios_csv/` | Header kolom CSV hasil dekripsi tiap container skenario |
| `out/row1/` | Baris 1 (header) tiap container, terdekripsi penuh 1 181 byte |
| `out/asset_manifest.json` | Inventaris 13 279 objek serialized |

Katalog skenario bersumber dari record MonoScript yang menyimpan path sumber aslinya
(`\Assets\Game\Scenario\Actual Scenarios\<Kategori>\<Nama>.cs`), jadi pengelompokan
kategorinya mengikuti struktur proyek Candywriter.

## Format container `\x00IAP`

Teridentifikasi dari 28 file `assets/*` berukuran 150–400 KB:

```
00 "IAP" | u32 versi | u16 tipe | 18 byte tag grup | 46 byte | payload … | 8 byte ekor
```

- Payload mulai offset **2**.
- Baris 1 payload **selalu** baris header CSV 68 kolom, dan teksnya identik di semua file
  (terverifikasi: 8 dari 8 file segrup cocok sampai byte 1 180).
- Isi 64-byte header berbeda per grup; 8 file yang berbagi tag grup juga berbagi 118 byte
  ciphertext pertama, konsisten dengan plaintext yang sama.

Keystream di rentang baris 1 pulih dengan men-drag daftar kolom milik game
(`ScenarioCSVHeaders`) lalu di-cross-check antar file; hasilnya ditulis ke `out/row1/`
dan `out/scenarios_csv/`.

## Status cipher: belum tuntas

Yang sudah diuji dan hasilnya negatif: XOR kunci berulang (kunci dari header, mentah
maupun lewat char-map milik game), AES CTR/CBC/CFB/OFB dengan kunci/IV turunan header,
PBKDF2/HMAC atas passphrase game, ChaCha20, RC4, dan inflate pasca-dekripsi.
Repo `bitlife-edit` hanya menangani save/var (format berbeda).

Bukti yang mengarahkan pekerjaan lanjutan:

- Keystream **bergantung pada posisi**, bukan pada isi: keystream baris 1 dari file A
  mendekripsi baris 1 file B pada posisi yang sama dengan hasil 89–91 % benar.
- Tiga file (M2BU, TtPu, ttyR) stabil pada offset 0; empat file lain bergeser +3/-5
  dan hanya benar ~12 %, jadi ada sisipan byte di dalam baris pada file-file itu
  (29 byte sisipan terlihat pada satu sampel).
- Keystream baris 1 **tidak** dipakai ulang untuk baris 2 (0,45–0,50 printable saja),
  jadi cipher melakukan re-key per baris.

## Batas yang jujur

Isi teks lengkap seluruh skenario tetap terbaca dari `out/strings.txt`, karena narasi dan
pilihan memang dikompilasi ke metadata il2cpp — tidak perlu membongkar container.
Yang belum: pemetaan baris-per-baris isi container ke kolomnya, karena generator keystream
per baris belum dipecahkan.

## Catatan tambahan: `assets/dic`

`assets/dic` (4 016 byte) bukan file kunci, melainkan **ELF32 x86** yang di-XOR
dengan kunci `dic` — jadi cara menyamarkannya sama dengan menyamarkan isi container.
Isinya `libc` shim minimal yang cuma memanggil `printf`, `__cxa_atexit`, `__libc_init`,
jadi bukan bagian dari jalur dekripsi container. Hasil bersihnya ada di `out/dic.elf`.

Cara menemukannya berguna untuk kerja lanjutan: XOR berulang dengan kunci pendek bisa
dideteksi dengan mencari kunci yang membuat seluruh file jadi printable. Itu yang berhasil
di sini, dan itu juga sebabnya XOR kunci berulang sudah diuji lebih dulu terhadap container
sebelum beralih ke AES.

## Peta data pendukung

| File | Isi |
|---|---|
| `out/designer_headers.txt` | 68 nama kolom CSV (urutan kolom format desainer) dari `ScenarioCSVHeaders` |
| `out/scenario_catalog.json` | Katalog mesin: skenario per kategori + daftar tanpa path |
| `out/audio_manifest.json` | Metadata tiap klip (pathId, kanal, frekuensi, durasi, nama file) |
| `out/asset_manifest.json` | Inventaris 13 279 objek serialized (tipe, pathId, nama) |

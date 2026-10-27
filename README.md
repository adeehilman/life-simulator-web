# Panduan pakai

## Isi

| Folder | Isi |
|---|---|
| `out/REPORT.md` | Ringkasan hasil + batasnya |
| `out/strings.txt` | Seluruh string literal game (72 143) dari metadata il2cpp |
| `out/scenarios/` | Katalog skenario per kategori asli game (1 090) + 1 686 tanpa path |
| `out/strings_by_topic/` | Korpus string dipilah per topik (pilihan, narasi, karier, uang, relasi, kriminal, kesehatan, UI) |
| `out/assets/` | 279 sprite/tekstur PNG |
| `out/audio/` | 418 audio WAV |
| `out/scenarios_csv/` | Header CSV hasil dekripsi 28 container skenario |
| `out/asset_manifest.json` | Inventaris 13 279 objek serialized |
| `out/dic.elf` | `assets/dic` setelah di-XOR kunci `dic` — ELF32 x86 shim libc |
| `tools/` | Skrip ekstraksi + cracker |

## Reproduksi dari APK

Semua skrip relatif terhadap folder ini dan mengasumsikan APK sudah diekstrak ke `work/apk`
(`python -c "import zipfile;zipfile.ZipFile('BitLife.apk').extractall('work/apk')"`).

```bash
python tools/dump_literals.py            # string literal -> out/strings.txt
python tools/build_scenario_catalog.py   # katalog skenario dari path MonoScript
python tools/dump_assets.py              # sprite/tekstur PNG + manifest
python tools/dump_audio.py               # audio WAV
python tools/build_deliverables.py       # pecah per kategori + per topik
python tools/classify_containers.py      # klasifikasi 17 grup container IAP
python tools/decrypt_iap.py              # baris 1 + header CSV terdekripsi per file
```

Butuh `pip install UnityPy pillow pycryptodome capstone`.

## Struktur metadata yang dipakai

`global-metadata.dat` (versi 39) punya tabel chunk 66 entri di offset 8. Batas tiap chunk
tidak bisa diambil dari kolom ukuran (banyak yang melewati EOF di build ini), jadi
dipakai offset terdekat berikutnya. Yang relevan:

- `0x00017c` tabel offset literal, 72 144 entri menaik
- `0x046740` heap literal, literal ke-i = heap[off[i]:off[i+1]]
- `0x219458` heap identifier (dipisah NUL) — nama kelas, field, method
- `0x590eac` tabel tipe, `0xa7b7ac` tabel field, keduanya stride 12
- `0xac1346` kumpulan path sumber `.cs` asli, sumber katalog skenario

## Container `\x00IAP`

```
00 "IAP" | u32 versi | u16 tipe | 18 byte tag grup | 46 byte | payload … | 8 byte ekor
```

Payload mulai offset 2. Cipher stream dengan keystream konstan per grup; 2 file segrup
berbagi 118 byte ciphertext identik yang merupakan baris header CSV. Keystream di rentang
itu dipulihkan dengan crib-drag daftar kolom `ScenarioCSVHeaders` dan divalidasi ke semua
anggota grup (skor printable 0,75–1,00 vs 0,43 baseline).

Status cipher: baris 1 tiap file terdekripsi penuh (1 181 byte) karena teksnya diketahui.
Baris 2 ke atas belum: cipher re-key per baris dan generator keystream-nya belum dipecahkan.
Keystream terbukti fungsi posisi (keystream file A mendekripsi file B 89-91 % benar),
tetapi sebagian file punya sisipan byte sehingga posisinya bergeser.

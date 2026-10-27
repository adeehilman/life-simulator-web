# BitLife 3.25.3 — Tiga pertanyaan RNG, dijawab dari byte native

Sumber: `work/native/libil2cpp.so` (sha256 `b69f574e…`, ELF32 ARM, 93.898.144 byte)
+ `out/il2cpp/script.json` + `out/il2cpp/method_by_address.json`.

Probe: `tools/rng_q123_probe.py` (dekoder ARM32 mandiri, batas fungsi diambil segar
dari `method_by_address.json`). Output mentah:
`out/reverse-engineering/rng_q123_probe.txt` dan `rng_q123_probe.json`.

Catatan metode: `out/ghidra/rng_3253.c` TIDAK dipakai sebagai sumber kebenaran untuk
badan fungsi. Skrip `DecompileRng3253.java` yang lama menghancurkan boundary `.cctor`
sebelum output itu ditulis, sehingga pseudo-C-nya tidak dapat dipercaya. Semua bukti
di bawah berasal dari pembacaan byte langsung.

---

## Q1 — `Next(min, max)` atau `Next(min, max+1)`? Inklusif atau eksklusif?

### `DataHub.GetRandomNumber(int,int)` @ `0x015C4E50` (bounds `0x015C4E50..0x015C4FB0`)

```
015c4e50  push     {r4, r6, lr}
015c4e54  sub      sp, sp, #0x18
015c4e5c  mov      r5, r0              ; r5 = min      (arg0, apa adanya)
015c4e60  mov      r8, r1              ; r8 = max      (arg1, APA ADANYA — tidak ada +1)
...
015c4ec8  ldr      r0, [r0, #0xa74]    ; r0 = DataHub.getrandom
015c4edc  bl       Monitor$$Enter      ; veneer 0x011009EC
015c4efc  ldr      r7, [r0, #0xa74]    ; r7 = DataHub.getrandom
015c4f0c  ldr      r0, [r7]            ; r0 = getrandom->klass
015c4f10  ldr      r4, [r0, #0xf0]     ; r4 = vtable method at klass+0xF0
015c4f14  ldr      r3, [r0, #0xf4]     ; r3 = MethodInfo
015c4f18  mov      r0, r7              ; r0 = this
015c4f1c  mov      r1, r5              ; r1 = min
015c4f20  mov      r2, r8              ; r2 = max      (MENTAH, tidak diinkrementasi)
015c4f24  blx      r4                  ; VIRTUAL CALL = Random.Next(min, max)
015c4f48  bl       Monitor$$Exit       ; veneer 0x010D8658
```

### `GameReference.GetRandomNumber(int,int)` @ `0x01F6E348` (bounds `0x01F6E348..0x01F6E4B0`)

```
01f6e348  push     {r4-r8, r10, r11, lr}
01f6e34c  sub      sp, sp, #0x18
01f6e354  mov      r8, r0              ; r8 = min      (arg0)
01f6e358  mov      r4, r1              ; r4 = max      (arg1, mentah)
...
01f6e384  cmp      r4, #0x1            ; bandingkan max dengan 1
01f6e38c  movle    r4, #0x1            ; if (max <= 1) max = 1     <-- SATU-SATUNYA modifikasi
...
01f6e3c8  ldr      r0, [r0, #0xc]      ; r0 = GameReference.getrandom
01f6e3dc  bl       Monitor$$Enter
01f6e3fc  ldr      r7, [r0, #0xc]      ; r7 = GameReference.getrandom
01f6e40c  ldr      r0, [r7]            ; klass
01f6e410  ldrd     sl, fp, [r0, #0xf0] ; vtable method + MethodInfo at klass+0xF0
01f6e414  mov      r0, r7              ; this
01f6e418  mov      r1, r8              ; r1 = min
01f6e41c  mov      r2, r4              ; r2 = max (setelah clamp, TANPA +1)
01f6e420  mov      r3, r11             ; MethodInfo
01f6e424  blx      r10                 ; VIRTUAL CALL = Random.Next(min, max)
01f6e448  bl       Monitor$$Exit
```

### Metode yang dipanggil

Kedua wrapper memanggil metode virtual yang SAMA di `vtable+0xF0` dengan tanda tangan
`(this, int, int) -> int`. Satu-satunya anggota `System.Random` yang cocok adalah
`Next(int minValue, int maxValue)`, yang di binary ini ada di `0x047E11D0`.

### Jawaban Q1

**`Next(min, max)` — max EXCLUSIVE (tidak inklusif).**

- `DataHub`: max diteruskan **apa adanya** (`mov r8, r1` → `mov r2, r8`). Nol operasi aritmetika.
- `GameReference`: max diteruskan setelah **satu-satunya** modifikasi, yaitu clamp
  `if (max <= 1) max = 1`. Tidak ada `+1` di mana pun.
- Batas eksklusif dikonfirmasi dari badan `Next(int,int)` @ `0x047E11D0`
  (`out/REPORT_RNG_3253.md` §6b): `vcvt.s32.f64` memotong ke nol pada produk non-negatif,
  dan `diff = (long)(max - min)`.

---

## Q2 — `new Random()` atau `new Random(seed)`?

### Kedua `.cctor` memanggil ctor yang SAMA

```
DataHub..cctor    @ 0x018B0B30 (bounds ..0x018B1174)
  0x018B0CC4  bl  0x0100F660            ; alokasi objek
  0x018B0CC8  mov r1, #0                ; (diabaikan — lihat bawah)
  0x018B0CCC  mov r4, r0                ; r4 = objek baru
  0x018B0CD0  bl  0x020B89A4            ; veneer -> 0x047E0BA4 System.Random$$.ctor

GameReference..cctor @ 0x01F7F5D8 (bounds ..0x01F7F964)
  0x01F7F7A8  bl  0x0100F660            ; alokasi objek
  0x01F7F7AC  mov r1, #0                ; (diabaikan)
  0x01F7F7B0  mov r4, r0                ; r4 = objek baru
  0x01F7F7B4  bl  0x020B89A4            ; veneer -> 0x047E0BA4 System.Random$$.ctor
```

`script.json` memuat **dua** ctor `System.Random`:

| Address | Peran |
|---|---|
| `0x047E0BA4` | parameterless `Random()` — dipanggil oleh KEDUA `.cctor` |
| `0x047E0DFC` | `Random(int seed)` — dipanggil oleh yang parameterless |

### `0x047E0BA4` adalah parameterless (bukti, bukan asumsi)

```
047e0ba4  push     {r4, r5, fp, lr}
047e0bac  mov      r4, r0              ; r4 = this
047e0bf0  bl       0x047e0c10          ; -> System.Random$$GenerateSeed
047e0bf4  mov      r1, r0              ; r1 = HASIL GenerateSeed()  <-- MENIMPA r1
047e0bf8  mov      r0, r4              ; r0 = this
047e0bfc  pop      {r4, r5, fp, lr}
047e0c00  b        0x047e0dfc          ; tail-call Random..ctor(int seed)
```

Baris `mov r1, r0` adalah bukti langsung: ctor **menimpa** `r1` dengan hasil
`GenerateSeed()`. Karena itu `mov r1, #0` yang terlihat sebelum pemanggilan di kedua
`.cctor` **bukan** argumen seed — nilainya dibuang.

### `0x047E0DFC` adalah `Random(int seed)` (konfirmasi bentuk .NET)

```
047e0dfc  push     {...}
047e0e08  mov      sb, r0              ; this
047e0e0c  mov      r5, r1              ; r5 = seed
047e0e60  bl       System.Object$$.ctor
047e0e64  cmp      r5, #0x80000000     ; seed == Int32.MinValue ?
047e0e6c  movw     r8, #0xec87
047e0e70  movt     r8, #0x89a4         ; r8 = 0x89A4EC87 = MBIG
047e0e94  eor      r0, r5, r5, asr #31 ; abs(seed)
047e0e98  movw     r1, #0xec86
047e0ea0  movt     r1, #0x9a4          ; r1 = 0x9A4EC86 = MSEED
047e0ea4  add      r8, r0, r1          ; r8 = MSEED - abs(seed)
```

Persis implementasi .NET: `subtraction = (seed == Int32.MinValue) ? Int32.MaxValue : Math.Abs(seed)`
lalu `mj = MSEED - subtraction`.

### `GenerateSeed()` @ `0x047E0C10`

```
047e0cc0  bl       Monitor$$Enter      ; thread-safe
047e0cf0  ldr      r0, [r5]            ; objek statis
047e0cf4  ldrd     r2, r3, [r0, #0xe8] ; metode virtual di vtable+0xE8
047e0d00  blx      r2                  ; VIRTUAL CALL -> seed
047e0d04  mov      r8, r0
047e0d28  bl       Monitor$$Exit
```

Seed berasal dari panggilan virtual pada objek statis, bukan konstanta.

### Jawaban Q2

**`new Random()` parameterless — untuk KEDUA instance (`DataHub.getrandom` dan
`GameReference.getrandom`). Tidak ada seed eksplisit.**

Rantai: `.cctor` → `Random()` @ `0x047E0BA4` → `GenerateSeed()` @ `0x047E0C10`
(thread-safe, sumber berbasis runtime) → `Random(int)` @ `0x047E0DFC`.

**Konsekuensi parity:** nilai seed runtime **tidak dapat dipulihkan secara statis**.
Port harus menyuntikkan seed (dari save game atau fixture), bukan merekonstruksinya.

---

## Q3 — Apakah `UnityEngine.Random.Range` dipanggil di `Sim*.IncrementAge`?

Cakupan pemindaian (`tools/rng_q123_probe.py`):

- **Scope A** — 141 method `Sim*$$IncrementAge`, seluruh badan fungsi, panggilan langsung.
- **Scope B** — satu hop dari setiap callee langsung yang kelas pemiliknya berawalan
  `Sim`, `SocialMediaUtility`, `PersonGenerator`, `DataHub`, atau `GameReference`
  (511 badan fungsi helper).

### Hasil

```
Sim*$$IncrementAge methods found: 141
bodies scanned: 141; one-hop helper bodies scanned: 511
UnityEngine hits: 14
```

**Scope A (langsung di badan `Sim*.IncrementAge`): 0 hit. NOL.**

Keempat belas hit semuanya di Scope B:

| Helper | UnityEngine call | Konteks |
|---|---|---|
| `SimHero$$CurrentlyInPrison` | `Object.op_Inequality` | null-check |
| `SimHero$$IsARoyal` | `Object.op_Inequality` | null-check |
| `GameReference$$CurrencyStringForAmount` | `Object.op_Inequality` | null-check |
| `GameReference$$KeepItClean` | `Object.op_Equality` | null-check |
| `SimFinances$$AdjustBankBalanceByAmount` | `PlayerPrefs.HasKey/GetInt/SetInt/Save` | persistensi |
| `SimHero$$CheckForWholeSomeLife` | `PlayerPrefs.GetInt/SetInt/Save` | persistensi |
| `SimCasino$$CancelAllCasinoScenarios` | `Debug.Log` | logging |

### Jawaban Q3

**TIDAK. `UnityEngine.Random.Range` tidak dipanggil — baik langsung maupun satu hop
dari `Sim*.IncrementAge`.**

UnityEngine **memang** terjangkau di jalur tahunan, tapi hanya untuk:
- null-check (`Object.op_Inequality` / `op_Equality`)
- persistensi (`PlayerPrefs`)
- logging (`Debug.Log`)

Tidak ada satu pun `UnityEngine.Random.*` di antara 141 + 511 badan fungsi yang dipindai.
Ini konsisten dengan temuen sebelumnya pada `Life.IncrementAgeSimulation`
(`out/REPORT_RNG_3253.md` §8): tepat satu call-site RNG, yaitu
`GameReference.GetRandomNumber` @ `0x0257AB20`, dan nol `UnityEngine.Random`.

**Batasan yang harus dinyatakan jujur:** Scope B hanya **satu hop**. Panggilan
`UnityEngine.Random` pada kedalaman dua hop atau lebih TIDAK tertutup oleh pemindaian
ini. Yang terbukti adalah: tidak ada di badan `Sim*.IncrementAge` sendiri, dan tidak
ada di helper langsungnya.

---

## Ringkasan untuk port

| Pertanyaan | Jawaban | Dampak |
|---|---|---|
| Batas wrapper | `Next(min,max)`, max **eksklusif**; GameReference clamp `max<=1 → 1` | `web/src/rng.ts` dan `clone/monorandom.py` sudah benar |
| Seeding | `new Random()` parameterless, seed runtime | seed tidak bisa direkonstruksi statis; harus disuntikkan |
| `UnityEngine.Random` | Tidak ada di `Sim*.IncrementAge` maupun helper langsungnya | jalur tahunan murni `System.Random` |

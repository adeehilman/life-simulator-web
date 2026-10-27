# Loose `\x00IAP` containers — format and cipher status

28 files in `work/apk/assets/` with random 16-character names (152 KB – 401 KB). They
are the legacy-format scenario tables and they are **not** in the asset pack, so they
are the only copy of that data in the build.

Tooling: `tools/decrypt_loose.py`, `tools/crib_drag.py`.

## Container format (verified on all 28)

```
offset 0    00 "IAP"
offset 4    u32  version, always 2
offset 8    u16  type, always 0x0807
offset 10   18-byte group tag
offset 28   payload
EOF-8       8-byte trailer (ends 407c3d62 on 24 of 28 files)
```

The 18-byte tag is literally the header bytes + payload[0..3] of the group's first
member (`0807` + first 16 bytes of its CRC), and it is not a hash of the file name —
MD5 and SHA-1 of the name both miss. Its only job is grouping: the 28 files form 17
groups of size 1–8.

Payload is a legacy-schema scenario CSV. Its first 152 bytes are the column header row.

## What is solved

- **Header row.** All members of a group are byte-identical over `0..179`, and the
  header plaintext is known, so the group's header keystream falls out by XOR and
  cross-validates on every member. `tools/decrypt_loose.py` writes
  `out/loose/<name>.header.csv` for all 28 files — the full schema of every table is
  recovered.

  Header: `IsEntryPoint, EntryNarrative, ChoiceList, ActionList, IntValue, StringValue,
  ChoiceScenarioID, DropDownList, DropDownTitles, SliderList, SliderTitles,
  ResultNarratives, GiveItem, TableValues, …`

- **Not AES, not the EncryptionManager cipher.** Both were tried first, per the plan.
  Neither produces anything printable.

## What is not solved

Past payload byte 152 the keystream **re-keys per file**, so the shared header span is
where the group-wide keystream ends.

The re-key is not a fresh random stream, though. Within a group, members that carry
near-identical plaintext keep a ~68 % identical keystream, and the divergence sits on
a 2-of-3 byte cadence — a self-synchronising construction where agreement in the
plaintext pulls the keystream back into step. Concretely, in the 8-member group,
`B1KY5e6LXK1pY4NZ` and `M2BUXYz1txVYeTdY` share 697 of 1029 keystream bytes while
`IKFv7jSMaTPTmNQg` shares 14 with either — i.e. keystream agreement tracks plaintext
agreement, which is why the pair clusters.

So the body is recoverable **only statistically**, as a two-time pad:

```
pt_a[i] ^ pt_b[i] == ct_a[i] ^ ct_b[i]      (holds where the keystream agrees)
```

`decrypt_loose.py` runs an iterated-conditional-modes pass over each group, choosing a
per-position keystream byte against a trigram model built from the game's own scenario
CSVs, and writes `out/loose/<name>.partial.csv`. The result is readable prose with
broken spots — good enough to read and cite, not good enough to feed a parser.

Ruled out along the way: 4-byte repeating key (`SecurityHelper.Cryption`), periodicity
at 1–1200 bytes, plaintext autokey, ciphertext feedback, 8- and 16-bit LCG, and a
single global keystream reused across groups.

## Where the answer actually is

The cipher is applied by code the dump does not name usefully. `System.Random`-based
`SecurityHelper.Cryption` is the game's *own* bulk cipher and is fully recovered
(see `out/REPORT_MECHANICS.md` § 7) — but it is the save path, and it does not decrypt
these payloads. The remaining candidates, in order of cost:

1. **Frida hook on `SecurityHelper.Decrypt` / `EncryptionManager.DecryptString`** while
   the game boots. Dump post-decryption buffers. Cracks it in one run and needs no
   further crypto work.
2. Find the container reader by string cross-reference in the DEX. The 16-character
   names live in `classes2.dex` string pool 706 but are consumed from
   `com.pairip.licensecheck.RepeatedCheckMetadata`, an obfuscated blob, so static
   reference chasing is short-circuited.
3. Search `libil2cpp.so` for the reader by the `\x00IAP` magic — no literal occurrence
   of the 4-byte magic or of `0x50414900` exists, so the magic must be compared bytewise
   or assembled; grep by instruction shape rather than data.

## Confidence

Header recovery is exact and reproducible. Body recovery is a best-effort read, and any
counts derived from `out/loose/*.partial.csv` should be treated as approximate.

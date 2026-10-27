---
name: bitlife-port-parity
description: Use when extending or validating the BitLife 3.25.3 web port. Keep versioned evidence, preserve raw scenario data, and require tests before semantic claims.
---

# BitLife Port Parity Skill

## Version discipline

- Treat BitLife 3.25.3 as the semantic target.
- Use 3.26.0 only as a labelled development/UI oracle.
- Never merge newer-version runtime observations into target fixtures without an explicit delta classification.

## Evidence discipline

- Track extracted content, static native evidence, web-side tests, visible APK evidence, and target-version runtime parity separately.
- A build, copied asset, or pseudo-C output is not semantic parity.
- Record source paths, version labels, hashes, and test commands in `PORT_100_PLAN.md` and `out/EVIDENCE_LEDGER.json`.

## IL2CPP workflow

- Validate an RVA against the matching `dump.cs` signature/class before using it.
- Treat unresolved function boundaries or unresolved relevant `FUN_*`/`DAT_*` dependencies as evidence-only.
- Promote a recovered rule only after an interpretation and fixture/test exist.

## RNG and annual state

- Use the Mono/System.Random implementation and persist a complete snapshot: seed array, indexes, and draw count.
- Record annual stage order and RNG draws.
- Do not claim the APK seed or call order until a target-version runtime fixture observes it.

## Scenario and Genesis

- Preserve raw impacts, conditions, routes, costs, age-up flags, and blueprint payloads before interpretation.
- Evaluate typed Genesis filters conservatively.
- Apply supported Genesis actions transactionally.
- Return unsupported action types as diagnostics; never silently claim success.

## Runtime instrumentation

- Verify the actual Frida daemon UID with `ps`; `su -c id` alone is insufficient on WSA.
- Use `su -c`, not `su 0 <command>`.
- Keep hooks read-only and sanitize captured output. Never store authentication/session data.
- On WSA ARM64 APKs running under x86_64 translation, verify that `libil2cpp.so` and `libunity.so` are actually mapped before applying RVAs.

## Completion gate

Only report 100% when all parity gates have evidence and the plan contains:

```text
Status: [x] 100% COMPLETE
Final verification: PASS
Unexplained parity gaps: 0
```

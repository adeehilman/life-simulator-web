# Learned Workflow and Evidence Rules

## Version-aware oracle work

Use the installed APK for development and visible-flow observation, but never relabel a newer runtime as the target version. Record installed version, version code, ABI, split APKs, and target version in every fixture directory.

## Unity/IL2CPP recovery

Validate every RVA against the matching `dump.cs` signature and class before using it. A successful Ghidra run is an artifact, not proof of a recovered rule. Require clean function boundaries, resolved relevant `FUN_*`/`DAT_*` dependencies, and a test or runtime fixture before translating pseudo-C into TypeScript behavior.

## WSA Frida setup

`adb shell su -c id` can report root while a child `frida-server` is demoted to UID `shell`. Always inspect the daemon UID with `ps`. Use `su -c`, not `su 0 <command>`, because Magisk parses flags such as `-D` itself. In this environment, Frida 17.24.3 server was eventually verified as UID 0 and attach succeeded. The installed BitLife APK is ARM64 running on WSA x86_64/Houdini; `libil2cpp.so` and `libunity.so` are present in the APK native directory but were not mapped during the probe. Treat that as a module-loading/ABI blocker, not an attach failure.

## Runtime capture safety

Instrumentation must be read-only. Capture function arguments, return values, module bases, event ordering, and sanitized gameplay state only. Never retain JWTs, refresh tokens, credentials, telemetry identifiers, raw PlayerPrefs, or authentication/session payloads.

## Scenario and Genesis parity

Preserve raw scenario payloads before interpreting them. Generic domain storage is inventory preservation, not semantic parity. Execute supported Genesis state actions transactionally and report unsupported blueprint types explicitly. Do not silently turn unsupported actions into success.

## Completion reporting

Separate these claims: extracted content, web-side tests, static native evidence, visible APK oracle evidence, and target-version runtime parity. A build or a playable prototype does not close the parity gate. The project is complete only when the plan has no unexplained parity gaps and the final verification marker is present.

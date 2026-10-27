# Decrypt all *-enc TextAssets in datapack.unity3d.
# Cipher (from EncryptionManager in libil2cpp.so, verified 2026-10-25):
import base64
import json
import os
import sys
import zipfile

import UnityPy

ROOT = os.path.join(os.path.dirname(os.path.abspath(__file__)), '..')
PACK = os.path.join(ROOT, 'work', 'abi', 'UnityDataAssetPack.apk')
DATA_ENTRY = 'assets/bin/Data/datapack.unity3d'
OUT_DIR = os.path.join(ROOT, 'out', 'decrypted')
LOOSE_DIR = os.path.join(ROOT, 'work', 'apk', 'assets')

# EncryptionManager.DefaultCipherKey() returns this literal (found via
# disassembly @ 0x11553a0 + metadata-usage slot 0x5697a78):
RAW_KEY = 'com.wtfapps.apollo16'

# EncryptionManager.ObfuscateChar: 26-entry uint16 substitution table
# for a..z (read from libil2cpp.so @ 0x8dc04a).
OBFUSCATE_TABLE = {
    'a': 'z', 'b': 'm', 'c': 'y', 'd': 'l', 'e': 'x', 'f': 'k', 'g': 'w',
    'h': 'j', 'i': 'v', 'j': 'i', 'k': 'u', 'l': 'h', 'm': 't', 'n': 'g',
    'o': 's', 'p': 'f', 'q': 'r', 'r': 'e', 's': 'q', 't': 'd', 'u': 'p',
    'v': 'c', 'w': 'o', 'x': 'b', 'y': 'n', 'z': 'a',
}

def obfuscate(s):
    return ''.join(OBFUSCATE_TABLE.get(c, c) for c in s)

# EncryptionManager.XORCipherString: text[i] ^ key[(i+1) % len(key)]
KEY = obfuscate(RAW_KEY).encode('utf-8')

def decrypt(b64_text):
    ct = base64.b64decode(b64_text)
    key = KEY
    n = len(key)
    # XORCipherString: text[i] ^ key[i % len(key)] (offset 0, verified
    # against a16_birth-circumstances and a16_zoo-fundraiser)
    return bytes(c ^ key[i % n] for i, c in enumerate(ct))

def main():
    os.makedirs(OUT_DIR, exist_ok=True)
    z = zipfile.ZipFile(PACK)
    data = z.read(DATA_ENTRY)
    env = UnityPy.load(data)
    ok, fail, skipped = 0, 0, 0
    for obj in env.objects:
        if obj.type.name != 'TextAsset':
            continue
        d = obj.read()
        name = getattr(d, 'm_Name', None) or getattr(d, 'name', '')
        s = d.m_Script
        if not name.endswith('-enc'):
            skipped += 1
            continue
        if isinstance(s, str):
            s = s.encode('utf-8', 'surrogateescape')
        try:
            pt = decrypt(s.decode('ascii'))
            out = os.path.join(OUT_DIR, name[:-4] + '.csv')
            with open(out, 'wb') as f:
                f.write(pt)
            ok += 1
        except Exception as e:
            fail += 1
            print(f"FAIL {name}: {e}", file=sys.stderr)
    print(f"decrypted: {ok}, failed: {fail}, non-enc skipped: {skipped}")
    print(f"output: {OUT_DIR}")

if __name__ == '__main__':
    main()

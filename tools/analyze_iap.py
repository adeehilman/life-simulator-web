import glob, os

RAW_KEY = 'com.wtfapps.apollo16'
OBF = {'a':'z','b':'m','c':'y','d':'l'}
KEY = ''.join(OBF.get(c,c) for c in RAW_KEY).encode()

def decrypt(b):
    n = len(KEY)
    return bytes(c ^ KEY[i % n] for i,c in enumerate(b))

f = 'work/apk/assets/1fSkbsSMkf0QNTeK'
data = open(f,'rb').read()
out = decrypt(data)
print(out[:64].hex())

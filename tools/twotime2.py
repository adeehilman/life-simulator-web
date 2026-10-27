import os,pickle,math,sys
tri,bi,uni,alpha=pickle.load(open('tools/model4.pkl','rb'))
A=set(alpha); tot=sum(uni.values())
U=[(uni.get(b,0)+0.5)/(tot+0.5*256) for b in range(256)]
LU=[math.log(U[b]) if b in A else -16.0 for b in range(256)]
def logp(ctx, b):
    if b not in A: return -16.0
    t=tri.get(ctx)
    if t:
        s=sum(t.values())
        return math.log((t.get(b,0)+2.0*U[b])/(s+2.0))
    t=bi.get(ctx[1]) if ctx[1] in A else None
    if t:
        s=sum(t.values())
        return math.log((t.get(b,0)+2.0*U[b])/(s+2.0))
    return LU[b]
d='work/apk/assets'
files=['B1KY5e6LXK1pY4NZ','M2BUXYz1txVYeTdY','TtPubu0VVqQXcPEv','ttyRbnlGJl8xAk0x']
blobs=[open(os.path.join(d,f),'rb').read() for f in files]
OFF=28
N=int(sys.argv[1])
ct=[[bl[OFF+152+i] for i in range(N)] for bl in blobs]
pt=[[0]*N for _ in range(4)]; ks=[0]*N
for p in range(N):
    best=None
    for k in range(256):
        s=sum(LU[c[p]^k] for c in ct)
        if best is None or s>best[0]: best=(s,k)
    ks[p]=best[1]
    for j in range(4): pt[j][p]=ct[j][p]^ks[p]
for it in range(8):
    for p in range(N):
        ctxs=[(pt[j][p-2] if p>1 else 0x2c, pt[j][p-1] if p else 0x2c) for j in range(4)]
        best=None
        for k in range(256):
            s=0.0
            for j in range(4): s+=logp(ctxs[j], ct[j][p]^k)
            if best is None or s>best[0]: best=(s,k)
        ks[p]=best[1]
        for j in range(4): pt[j][p]=ct[j][p]^ks[p]
    print('iter',it,repr(bytes(pt[0][:120])))
print('FINAL')
print(bytes(pt[0]).decode('latin1'))

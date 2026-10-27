import os,pickle,math,sys
bi,uni,alpha=pickle.load(open('tools/model2.pkl','rb'))
A=set(alpha); LA=sorted(A)
tot=sum(uni.values())
U=[(uni.get(b,0)+0.5)/(tot+0.5*256) for b in range(256)]
LU=[math.log(U[b]) if b in A else math.log(1e-7) for b in range(256)]
LB={}
for a in range(256):
    row=bi.get(a,{}); t=sum(row.values())
    LB[a]=[math.log((row.get(b,0)+3.0*U[b])/(t+3.0)) if b in A else math.log(1e-7) for b in range(256)]
d='work/apk/assets'
files=['B1KY5e6LXK1pY4NZ','M2BUXYz1txVYeTdY','TtPubu0VVqQXcPEv','ttyRbnlGJl8xAk0x']
blobs=[open(os.path.join(d,f),'rb').read() for f in files]
OFF=28
N=int(sys.argv[1]) if len(sys.argv)>1 else 4000
ct=[[bl[OFF+152+i] for i in range(N)] for bl in blobs]
pt=[[0]*N for _ in range(4)]; ks=[0]*N
cnt=[0]*N
for p in range(N):
    best=None
    for k in range(256):
        s=0.0
        for c in ct: s+=LU[c[p]^k]
        if best is None or s>best[0]: best=(s,k)
    ks[p]=best[1]
    for j in range(4): pt[j][p]=ct[j][p]^ks[p]
for it in range(20):
    for p in range(N):
        pr=[pt[j][p-1] if p else 0x2c for j in range(4)]
        best=None; n=0
        for k in range(256):
            s=0.0
            for j in range(4):
                b=ct[j][p]^k
                if b in A: s+=LB[pr[j]][b]
                else: s+=LU[b]
            if best is None or s>best[0]-1e-9: 
                if best is None or s>best[0]+1e-9: best=(s,k); n=1
                else: n+=1
        ks[p]=best[1]; cnt[p]=n
        for j in range(4): pt[j][p]=ct[j][p]^ks[p]
    if it in (0,5,10,19):
        print('--- iter',it,'ambig frac',round(sum(1 for x in cnt if x==1)/N,3))
        print(repr(bytes(pt[0][:200])))
print(repr(bytes(pt[0])))

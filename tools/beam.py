import os,pickle,math,sys,heapq
tri,bi,uni,alpha=pickle.load(open('tools/model4.pkl','rb'))
A=set(alpha); tot=sum(uni.values())
U=[(uni.get(b,0)+0.5)/(tot+0.5*256) for b in range(256)]
LU=[math.log(U[b]) if b in A else -16.0 for b in range(256)]
BC={}
def logp(ctx,b):
    key=(ctx,b)
    v=BC.get(key)
    if v is not None: return v
    if b not in A: r=-16.0
    else:
        t=tri.get(ctx)
        if t:
            s=sum(t.values()); r=math.log((t.get(b,0)+2.0*U[b])/(s+2.0))
        else:
            t=bi.get(ctx[1]) if ctx[1] in A else None
            if t:
                s=sum(t.values()); r=math.log((t.get(b,0)+2.0*U[b])/(s+2.0))
            else: r=LU[b]
    BC[key]=r; return r
d='work/apk/assets'
files=['B1KY5e6LXK1pY4NZ','M2BUXYz1txVYeTdY','TtPubu0VVqQXcPEv','ttyRbnlGJl8xAk0x']
blobs=[open(os.path.join(d,f),'rb').read() for f in files]
OFF=28; N=int(sys.argv[1]); B=int(sys.argv[2])
ct=[[bl[OFF+152+i] for i in range(N)] for bl in blobs]
# candidates per position: ks such that all 4 bytes allowed
cands=[]
for p in range(N):
    cs=[k for k in range(256) if all((ct[j][p]^k) in A for j in range(4))]
    cands.append(cs if cs else list(range(256)))
print('avg cands', sum(len(c) for c in cands)/N, 'max', max(len(c) for c in cands))
# state: (score, kspath tuple? ) -> keep (last2 ks) and path list
beam=[(0.0,(),(),())]  # (score, ks_hist(2), pt_prev2_0..)  store per-file last2 chars
beam=[(0.0,(0x2c,0x2c),(0x2c,0x2c),(0x2c,0x2c),(0x2c,0x2c))]
# simple: store last2 chars per file, plus ks list
beams=[(0.0,[],[(0x2c,0x2c)]*4,[])]
for p in range(N):
    new=[]
    for score,ksl,ctxs,kss in beams:
        for k in cands[p]:
            s=score; nc=[]
            for j in range(4):
                b=ct[j][p]^k
                s+=logp(ctxs[j],b); nc.append((ctxs[j][1],b))
            new.append((s,ksl,nc,kss+[k]))
    if len(new)>B:
        new.sort(key=lambda x:-x[0]); new=new[:B]
    beams=new
    if p%200==0: print(p, len(beams), round(beams[0][0],1), repr(bytes(beams[0][3][-40:])))

ks=beams[0][3]
out=bytes(ct[0][i]^ks[i] for i in range(N))
open('/tmp/b0.txt','wb').write(out)
print(out[:1500].decode('latin1'))

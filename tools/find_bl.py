import struct
d=open('work/native/libil2cpp.so','rb').read()
e_phoff=struct.unpack_from('<I',d,28)[0]
e_phnum=struct.unpack_from('<H',d,44)[0]
e_phentsize=struct.unpack_from('<H',d,42)[0]
segs=[]
for i in range(e_phnum):
    t,off,va,pa,fs,ms,fl,al=struct.unpack_from('<IIIIIIII',d,e_phoff+i*e_phentsize)
    segs.append((t,off,va,fs))
def off2va(o):
    for t,off,v,fs in segs:
        if t==1 and off<=o<off+fs: return v+(o-off)
    return None
targets={0x25DA97C:'Decrypt(string)',0x25DA958:'Decrypt(int)'}
res={}
for i in range(0,len(d)-4,4):
    w=struct.unpack_from('<I',d,i)[0]
    if (w & 0xFF000000)!=0xEB000000: continue
    imm=w & 0x00FFFFFF
    if imm & 0x800000: imm-=0x1000000
    pc=off2va(i)
    if pc is None: continue
    tgt=pc+8+imm*4
    if tgt in targets: res.setdefault(tgt,[]).append(pc)
for k,v in res.items(): print(targets[k], len(v), [hex(x) for x in v][:30])

"""Extract il2cpp string literals from global-metadata.dat (metadata v39, this build).

Layout confirmed by inspection:
  0x00017c  u32 offset table, 72144 entries, monotonically increasing
  0x046740  literal heap; literal i spans heap[off[i] : off[i+1]]
  0x219458  identifier/string heap (start of the next chunk)
"""
import struct

META = 'work/apk/assets/bin/Data/Managed/Metadata/global-metadata.dat'
TABLE = 0x17C
HEAP = 0x46740
COUNT = 72144


def main():
    d = open(META, 'rb').read()
    offs = list(struct.unpack_from('<%dI' % COUNT, d, TABLE))
    if offs != sorted(offs):
        raise SystemExit('offset table is not monotonic, aborting')
    out = []
    for i in range(COUNT - 1):
        raw = d[HEAP + offs[i]:HEAP + offs[i + 1]]
        out.append(raw.decode('utf-8', 'replace'))
    with open('out/strings.txt', 'w', encoding='utf-8') as fh:
        for s in out:
            fh.write(s.replace('\n', '\\n') + '\n')
    print('wrote', len(out), 'literals, heap bytes', offs[-1])


if __name__ == '__main__':
    main()

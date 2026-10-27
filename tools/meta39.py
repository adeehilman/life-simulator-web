"""Parser metadata il2cpp v39 (layout mengikuti Il2CppDumper MetadataClass.cs).

Dipakai untuk memetakan kelas -> field/metode -> token, sehingga rutin enkripsi
bisa dicari berdasarkan nama. Baseline chunk diambil dari offset header (kolom
ukuran di build ini tidak bisa dipercaya, jadi batas diturunkan dari offset
berikutnya yang terdekat).
"""
import struct

CHUNKS = 66
HEAP_IDX = 6
TYPES_IDX = 2
FIELDS_IDX = 3
METHODS_IDX = 5
PARAMS_IDX = 4

TYPE_STRIDE = 76      # v39, terverifikasi
METHOD_STRIDE = 40    # nameIndex, declaringType, returnType, returnParameterToken,
                      # parameterStart, genericContainerIndex, token, flags, iflags, slot


class Meta:
    def __init__(self, path):
        self.d = open(path, 'rb').read()
        if self.d[:4] != b'\xaf\x1b\xb1\xfa':
            raise ValueError('magic salah')
        self.ver = struct.unpack_from('<i', self.d, 4)[0]
        vals = struct.unpack_from('<%dI' % (2 * CHUNKS), self.d, 8)
        self.off = list(vals[:CHUNKS])
        self.end = len(self.d)
        self.b = self._bounds()

    def _bounds(self):
        ordered = sorted(set(self.off) | {self.end})
        nxt = {a: b for a, b in zip(ordered, ordered[1:])}
        out = {}
        for i, s in enumerate(self.off):
            out[i] = (s, nxt.get(s, self.end)) if s <= self.end else (self.end, self.end)
        return out

    def s(self, i):
        start, end = self.b[HEAP_IDX]
        p = start + i
        if not start <= p < end:
            return ''
        e = self.d.find(b'\x00', p, end)
        return self.d[p:e].decode('utf-8', 'replace')

    def types(self):
        start, end = self.b[TYPES_IDX]
        for i in range((end - start) // TYPE_STRIDE):
            row = struct.unpack_from('<19I', self.d, start + i * TYPE_STRIDE)
            yield i, row

    def methods(self):
        start, end = self.b[METHODS_IDX]
        n = (end - start) // METHOD_STRIDE
        for i in range(n):
            yield struct.unpack_from('<10i', self.d, start + i * METHOD_STRIDE)

    def fields(self):
        start, end = self.b[FIELDS_IDX]
        for i in range((end - start) // 12):
            yield struct.unpack_from('<3i', self.d, start + i * 12)


def find_type(m, name):
    for idx, row in m.types():
        if m.s(row[0]) == name:
            return idx, row
    return None, None


def dump_type(m, idx, row):
    name = m.s(row[0])
    ns = m.s(row[1])
    field_start, method_start = row[15], row[16]
    n_methods, n_fields = row[20], row[22]
    print(f'\n== {ns}.{name}  (typeIdx {idx})')
    for j in range(n_fields):
        f = struct.unpack_from('<3i', m.d, m.b[FIELDS_IDX][0] + (field_start + j) * 12)
        print('   field:', m.s(f[0]), 'token 0x%x' % f[2])
    for j in range(n_methods):
        md = list(m.methods())[:0]
    start = m.b[METHODS_IDX][0]
    for j in range(n_methods):
        r = struct.unpack_from('<10i', m.d, start + (method_start + j) * METHOD_STRIDE)
        print('   method:', m.s(r[0]), 'token 0x%x' % r[6], 'paramStart', r[4])

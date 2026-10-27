// Lockstep comparison: TypeScript MonoRandom vs Python clone, per construction step.
// Run: node clone/debug_divergence.mjs
const MBIG = 2147483647;
const MSEED = 161803398;

function tsConstruct(seed) {
  const seedArray = new Int32Array(56);
  const subtraction =
    seed === undefined ? Date.now() | 0 : seed === -2147483648 ? MBIG : Math.abs(seed | 0);
  let mj = MSEED - subtraction;
  seedArray[55] = mj;
  let mk = 1;
  const trace = [];
  for (let i = 1; i < 55; i++) {
    const ii = (21 * i) % 55;
    seedArray[ii] = mk;
    trace.push({ step: `loop1 i=${i}`, mj, mk, written: seedArray[ii] });
    mk = mj - mk;
    if (mk < 0) mk += MBIG;
    mj = seedArray[ii];
  }
  for (let k = 1; k < 5; k++) {
    for (let i = 1; i < 56; i++) {
      seedArray[i] -= seedArray[1 + ((i + 30) % 55)];
      if (seedArray[i] < 0) seedArray[i] += MBIG;
    }
  }
  return { seedArray: Array.from(seedArray), trace };
}

function pyConstruct(seed) {
  const seedArray = new Array(56).fill(0);
  const subtraction = seed === -2147483648 ? MBIG : Math.abs(seed);
  let mj = MSEED - subtraction;
  seedArray[55] = mj;
  let mk = 1;
  const trace = [];
  for (let i = 1; i < 55; i++) {
    const ii = (21 * i) % 55;
    seedArray[ii] = mk;
    trace.push({ step: `loop1 i=${i}`, mj, mk, written: seedArray[ii] });
    mk = mj - mk;
    if (mk < 0) mk += MBIG;
    mj = seedArray[ii];
  }
  for (let k = 1; k < 5; k++) {
    for (let i = 1; i < 56; i++) {
      seedArray[i] -= seedArray[1 + ((i + 30) % 55)];
      if (seedArray[i] < 0) seedArray[i] += MBIG;
    }
  }
  return { seedArray, trace };
}

// .NET reference: unchecked int32 arithmetic on BOTH mj/mk and seedArray.
function netConstruct(seed) {
  const i32 = (x) => (x | 0);
  const seedArray = new Array(56).fill(0);
  const subtraction = seed === -2147483648 ? MBIG : Math.abs(seed | 0);
  let mj = i32(MSEED - subtraction);
  seedArray[55] = mj;
  let mk = 1;
  for (let i = 1; i < 55; i++) {
    const ii = (21 * i) % 55;
    seedArray[ii] = mk;
    mk = i32(mj - mk);
    if (mk < 0) mk = i32(mk + MBIG);
    mj = seedArray[ii];
  }
  for (let k = 1; k < 5; k++) {
    for (let i = 1; i < 56; i++) {
      seedArray[i] = i32(seedArray[i] - seedArray[1 + ((i + 30) % 55)]);
      if (seedArray[i] < 0) seedArray[i] = i32(seedArray[i] + MBIG);
    }
  }
  return { seedArray };
}

for (const seed of [1, 42, 123, 7, 999983, -2147483648, 2147483647, -1]) {
  const ts = tsConstruct(seed);
  const py = pyConstruct(seed);
  const net = netConstruct(seed);
  const tsPy = JSON.stringify(ts.seedArray) === JSON.stringify(py.seedArray);
  const tsNet = JSON.stringify(ts.seedArray) === JSON.stringify(net.seedArray);
  const pyNet = JSON.stringify(py.seedArray) === JSON.stringify(net.seedArray);
  console.log(`seed=${seed}  TS==PY:${tsPy}  TS==NET:${tsNet}  PY==NET:${pyNet}`);
  if (!tsPy || !tsNet) {
    for (let i = 0; i < 56; i++) {
      if (ts.seedArray[i] !== py.seedArray[i] || ts.seedArray[i] !== net.seedArray[i]) {
        console.log(`   idx ${i}: TS=${ts.seedArray[i]} PY=${py.seedArray[i]} NET=${net.seedArray[i]}`);
      }
    }
    // first trace divergence
    for (let i = 0; i < ts.trace.length; i++) {
      if (ts.trace[i].mk !== py.trace[i].mk || ts.trace[i].mj !== py.trace[i].mj) {
        console.log(`   first trace divergence at ${ts.trace[i].step}: TS(mj=${ts.trace[i].mj},mk=${ts.trace[i].mk}) PY(mj=${py.trace[i].mj},mk=${py.trace[i].mk})`);
        break;
      }
    }
  }
}

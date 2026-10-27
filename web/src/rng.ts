// Mono `System.Random`, ported verbatim.
//
// The game funnels every roll through `DataHub.GetRandomNumber` -> a single static
// `System.Random`. `Math.random()` is not interchangeable: the consumption pattern
// differs, and seeded reproducibility (save/restore, replays) needs the same
// generator. See out/REPORT_MECHANICS.md § 1.

const MBIG = 2147483647;
const MSEED = 161803398;

export interface MonoRandomSnapshot {
  seedArray: number[];
  inext: number;
  inextp: number;
  drawCount: number;
}

export class MonoRandom {
  private readonly seedArray = new Int32Array(56);
  private inext = 0;
  private inextp = 21;
  private drawCount = 0;

  constructor(seed?: number) {
    const subtraction =
      seed === undefined
        ? Date.now() | 0
        : seed === -2147483648
          ? MBIG
          : Math.abs(seed | 0);

    let mj = MSEED - subtraction;
    this.seedArray[55] = mj;
    let mk = 1;
    for (let i = 1; i < 55; i++) {
      const ii = (21 * i) % 55;
      this.seedArray[ii] = mk;
      mk = mj - mk;
      if (mk < 0) mk += MBIG;
      mj = this.seedArray[ii];
    }
    for (let k = 1; k < 5; k++) {
      for (let i = 1; i < 56; i++) {
        this.seedArray[i] -= this.seedArray[1 + ((i + 30) % 55)];
        if (this.seedArray[i] < 0) this.seedArray[i] += MBIG;
      }
    }
  }

  snapshot(): MonoRandomSnapshot {
    return { seedArray: Array.from(this.seedArray), inext: this.inext, inextp: this.inextp, drawCount: this.drawCount };
  }

  restore(snapshot: MonoRandomSnapshot): void {
    if (snapshot.seedArray.length !== 56) throw new Error('Invalid MonoRandom snapshot length');
    if (snapshot.inext < 0 || snapshot.inext >= 56 || snapshot.inextp < 0 || snapshot.inextp >= 56) {
      throw new Error('Invalid MonoRandom snapshot indices');
    }
    this.seedArray.set(snapshot.seedArray);
    this.inext = snapshot.inext;
    this.inextp = snapshot.inextp;
    this.drawCount = snapshot.drawCount ?? 0;
  }

  /** InternalSample(): the raw MBIG-bounded draw. */
  private sample(): number {
    if (++this.inext >= 56) this.inext = 1;
    if (++this.inextp >= 56) this.inextp = 1;
    let ret = this.seedArray[this.inext] - this.seedArray[this.inextp];
    if (ret === MBIG) ret--;
    if (ret < 0) ret += MBIG;
    this.seedArray[this.inext] = ret;
    this.drawCount += 1;
    return ret;
  }

  /** Random.Next(min, max) — inclusive lower bound, exclusive upper. */
  next(min = 0, max = MBIG): number {
    if (min > max) [min, max] = [max, min];
    const range = max - min;
    return range <= MBIG ? min + Math.floor(this.sample() * (range / MBIG)) : min;
  }

  /** Random.Next() — 0 .. MBIG-1. */
  nextInt(): number {
    return this.sample();
  }

  /** Random.NextDouble() — 0.0 .. 1.0. */
  nextDouble(): number {
    return this.sample() * (1 / MBIG);
  }

  /** Random.NextBytes() — one low byte per draw, exactly `(byte)Next()`. */
  nextBytes(count: number): Uint8Array {
    const out = new Uint8Array(count);
    for (let i = 0; i < count; i++) out[i] = this.sample() & 0xff;
    return out;
  }

  /** `min + Next() % (max - min)`, the shape a lot of the game's call sites use. */
  range(min: number, max: number): number {
    if (max <= min) return min;
    return min + (this.sample() % (max - min));
  }

  pick<T>(items: readonly T[]): T | undefined {
    if (items.length === 0) return undefined;
    return items[this.next(0, items.length)];
  }

  /** True with probability `p` (0..1), matching `NextDouble() < p` call sites. */
  chance(p: number): boolean {
    return this.nextDouble() < p;
  }
}

// Name generation.
//
// BitLife draws first names from a per-country, per-gender pool and surnames from a
// separate per-country pool. The shipped build keeps those pools server-side, so this
// module carries a compact per-country table extracted by hand from the gameplay
// strings and falls back to a generic pool for countries it does not know.

import type { MonoRandom } from '../rng';
import type { Gender } from './life';

export interface PersonName {
  first: string;
  last: string;
}

const FIRST: Record<Gender, Record<string, string[]>> = {
  male: {
    us: ['James', 'Michael', 'Robert', 'Daniel', 'Christopher', 'Ethan', 'Noah', 'Liam', 'Mason', 'Logan'],
    gb: ['Oliver', 'Harry', 'Jack', 'George', 'Charlie', 'Thomas', 'Alfie', 'Freddie'],
    id: ['Budi', 'Agus', 'Joko', 'Eko', 'Rizky', 'Fajar', 'Dimas', 'Arief'],
    mx: ['José', 'Luis', 'Carlos', 'Miguel', 'Diego', 'Javier', 'Alejandro'],
    ca: ['Liam', 'Noah', 'Owen', 'Lucas', 'Nathan', 'Émile', 'Xavier'],
    au: ['Oliver', 'Jack', 'William', 'Noah', 'Cooper', 'Hunter', 'Flynn'],
    de: ['Lukas', 'Felix', 'Jonas', 'Maximilian', 'Paul', 'Leon', 'Ben'],
    fr: ['Louis', 'Gabriel', 'Raphaël', 'Jules', 'Adam', 'Hugo'],
    br: ['Gabriel', 'Lucas', 'Matheus', 'Pedro', 'Rafael', 'João'],
    in: ['Aarav', 'Rohan', 'Arjun', 'Vivek', 'Aryan', 'Karan'],
    jp: ['Haruto', 'Yuto', 'Sota', 'Ren', 'Kaito', 'Riku'],
    kr: ['Minjun', 'Seojun', 'Dohyun', 'Jihoon', 'Hyunwoo'],
  },
  female: {
    us: ['Mary', 'Jennifer', 'Linda', 'Emily', 'Emma', 'Olivia', 'Ava', 'Sophia', 'Isabella', 'Mia'],
    gb: ['Olivia', 'Amelia', 'Isla', 'Ava', 'Emily', 'Poppy', 'Ella', 'Freya'],
    id: ['Siti', 'Dewi', 'Rina', 'Putri', 'Anisa', 'Intan', 'Maya', 'Sari'],
    mx: ['María', 'Guadalupe', 'Sofía', 'Valentina', 'Ximena', 'Camila'],
    ca: ['Emma', 'Olivia', 'Charlotte', 'Ava', 'Sophie', 'Chloé', 'Léa'],
    au: ['Charlotte', 'Olivia', 'Amelia', 'Isla', 'Mia', 'Ruby', 'Chloe'],
    de: ['Mia', 'Emma', 'Hannah', 'Sofia', 'Lina', 'Lea', 'Marie'],
    fr: ['Emma', 'Jade', 'Louise', 'Alice', 'Chloé', 'Léa'],
    br: ['Alice', 'Sophia', 'Helena', 'Valentina', 'Laura', 'Manuela'],
    in: ['Aadhya', 'Ananya', 'Diya', 'Isha', 'Meera', 'Priya'],
    jp: ['Yui', 'Aoi', 'Hina', 'Sakura', 'Rin', 'Mei'],
    kr: ['Seoyeon', 'Jiwoo', 'Hayoon', 'Sua', 'Yuna'],
  },
};

const LAST: Record<string, string[]> = {
  us: ['Smith', 'Johnson', 'Williams', 'Brown', 'Jones', 'Miller', 'Davis', 'Garcia'],
  gb: ['Smith', 'Jones', 'Taylor', 'Brown', 'Williams', 'Wilson', 'Davies', 'Evans'],
  id: ['Santoso', 'Wijaya', 'Pratama', 'Saputra', 'Hidayat', 'Nugroho'],
  mx: ['García', 'Hernández', 'López', 'Martínez', 'Ramírez', 'Flores'],
  ca: ['Tremblay', 'Gagnon', 'Roy', 'Côté', 'Bouchard', 'Gauthier'],
  au: ['Smith', 'Jones', 'Williams', 'Brown', 'Wilson', 'Taylor'],
  de: ['Müller', 'Schmidt', 'Schneider', 'Fischer', 'Weber', 'Meyer'],
  fr: ['Martin', 'Bernard', 'Dubois', 'Thomas', 'Robert', 'Petit'],
  br: ['Silva', 'Santos', 'Oliveira', 'Souza', 'Lima', 'Pereira'],
  in: ['Sharma', 'Patel', 'Singh', 'Kumar', 'Reddy', 'Iyer'],
  jp: ['Sato', 'Suzuki', 'Takahashi', 'Tanaka', 'Watanabe', 'Ito'],
  kr: ['Kim', 'Lee', 'Park', 'Choi', 'Jung', 'Kang'],
};

const FALLBACK_FIRST = ['Alex', 'Sam', 'Jordan', 'Charlie', 'Robin', 'Casey'];
const FALLBACK_LAST = ['Doe', 'Roe', 'Poe', 'Vale', 'Hale', 'Stone'];

export function generateName(rng: MonoRandom, gender: Gender, country = 'us'): PersonName {
  const firstPool = FIRST[gender][country] ?? FALLBACK_FIRST;
  const lastPool = LAST[country] ?? FALLBACK_LAST;
  return {
    first: rng.pick(firstPool) ?? 'Alex',
    last: rng.pick(lastPool) ?? 'Doe',
  };
}

export function fullName(name: PersonName): string {
  return `${name.first} ${name.last}`;
}

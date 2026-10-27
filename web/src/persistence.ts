import type { Life } from './engine/life';

export const SAVE_VERSION = 2;
const DB_NAME = 'bitlife-web';
const STORE_NAME = 'saves';
const DEFAULT_SLOT = 'autosave';

function slotKey(slot: string): string {
  return `slot:${slot.replace(/[^a-zA-Z0-9_-]/g, '_')}`;
}

export interface SaveEnvelope {
  version: number;
  savedAt: string;
  life: Life;
}

export function makeSaveEnvelope(life: Life, now = new Date()): SaveEnvelope {
  return {
    version: SAVE_VERSION,
    savedAt: now.toISOString(),
    life: structuredClone(life),
  };
}

export function serializeSave(life: Life): string {
  return JSON.stringify(makeSaveEnvelope(life));
}

export function migrateSave(input: unknown): SaveEnvelope | null {
  if (!input || typeof input !== 'object') return null;
  const raw = input as Partial<SaveEnvelope> & { life?: Partial<Life> };
  if (!raw.life || typeof raw.life.age !== 'number') return null;
  const life = {
    ...raw.life,
    log: raw.life.log ?? [],
    previous: raw.life.previous ?? {},
    incrementing: raw.life.incrementing ?? false,
    domainState: raw.life.domainState ?? {},
    scenarioQueue: raw.life.scenarioQueue ?? [],
    ...(raw.life.rngState ? { rngState: raw.life.rngState } : {}),
  } as Life;
  return {
    version: SAVE_VERSION,
    savedAt: raw.savedAt ?? new Date(0).toISOString(),
    life,
  };
}

export function deserializeSave(serialized: string): SaveEnvelope | null {
  try {
    return migrateSave(JSON.parse(serialized));
  } catch {
    return null;
  }
}

function openDb(): Promise<IDBDatabase> {
  return new Promise((resolve, reject) => {
    const request = indexedDB.open(DB_NAME, 1);
    request.onerror = () => reject(request.error ?? new Error('IndexedDB open failed'));
    request.onupgradeneeded = () => {
      request.result.createObjectStore(STORE_NAME);
    };
    request.onsuccess = () => resolve(request.result);
  });
}

async function putSlot(slot: string, envelope: SaveEnvelope): Promise<void> {
  const db = await openDb();
  await new Promise<void>((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    tx.objectStore(STORE_NAME).put(envelope, slotKey(slot));
    tx.onerror = () => reject(tx.error ?? new Error('IndexedDB save failed'));
    tx.oncomplete = () => resolve();
  });
  db.close();
}

async function getSlot(slot: string): Promise<SaveEnvelope | null> {
  const db = await openDb();
  const value = await new Promise<SaveEnvelope | undefined>((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readonly');
    const request = tx.objectStore(STORE_NAME).get(slotKey(slot));
    request.onerror = () => reject(request.error ?? new Error('IndexedDB read failed'));
    request.onsuccess = () => resolve(request.result as SaveEnvelope | undefined);
  });
  db.close();
  if (!value || value.version !== SAVE_VERSION || !value.life || typeof value.life.age !== 'number') return null;
  return value;
}

export function validateSave(value: SaveEnvelope | null): SaveEnvelope | null {
  return value && value.version === SAVE_VERSION && value.life && typeof value.life.age === 'number' ? value : null;
}

export async function saveLife(life: Life, slot = DEFAULT_SLOT): Promise<void> {
  await putSlot(slot, makeSaveEnvelope(life));
}

export async function loadLife(slot = DEFAULT_SLOT): Promise<SaveEnvelope | null> {
  return getSlot(slot);
}

export async function listSaveSlots(): Promise<string[]> {
  const db = await openDb();
  const keys = await new Promise<IDBValidKey[]>((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readonly');
    const request = tx.objectStore(STORE_NAME).getAllKeys();
    request.onerror = () => reject(request.error ?? new Error('IndexedDB list failed'));
    request.onsuccess = () => resolve(request.result);
  });
  db.close();
  return keys.filter((key): key is string => typeof key === 'string' && key.startsWith('slot:'))
    .map((key) => key.slice('slot:'.length));
}

export async function clearSavedLife(slot = DEFAULT_SLOT): Promise<void> {
  const db = await openDb();
  await new Promise<void>((resolve, reject) => {
    const tx = db.transaction(STORE_NAME, 'readwrite');
    tx.objectStore(STORE_NAME).delete(slotKey(slot));
    tx.onerror = () => reject(tx.error ?? new Error('IndexedDB delete failed'));
    tx.oncomplete = () => resolve();
  });
  db.close();
}

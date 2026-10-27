const BASE = `${import.meta.env.BASE_URL}audio/`;

const cache = new Map<string, HTMLAudioElement>();

/** Explicit web event registry; APK trigger parity is pending evidence. */
const AUDIO_EVENTS: Readonly<Record<string, string>> = {
  'age-up': 'a16_SFX_BdaySH_Completed.wav',
};

export function audioEventFile(event: string): string | null {
  return AUDIO_EVENTS[event] ?? null;
}

export function audioUrl(file: string): string {
  return `${BASE}${encodeURIComponent(file)}`;
}

export function preloadAudio(file: string): HTMLAudioElement {
  const existing = cache.get(file);
  if (existing) return existing;
  const audio = new Audio(audioUrl(file));
  audio.preload = 'auto';
  cache.set(file, audio);
  return audio;
}

export function playAudio(file: string, volume = 1): void {
  const audio = preloadAudio(file);
  audio.currentTime = 0;
  audio.volume = Math.max(0, Math.min(1, volume));
  void audio.play().catch(() => {
    // Browsers require a user gesture; the next explicit interaction can retry.
  });
}

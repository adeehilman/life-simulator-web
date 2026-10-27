import { useCallback, useEffect, useMemo, useRef, useState } from 'react';
import { MonoRandom } from './rng';
import { DISPLAY_STATS, STAT_NAMES, StatType } from './stats';
import { createLife, logEvent, runAnnualPipeline, type Life } from './engine/life';
import { choiceIsAvailable, consumeRoute, enqueueRoute, rollQueuedScenario, rollScenario, type Scenario } from './engine/scenario';
import { applyChoiceEffects } from './engine/actions';
import { fullName } from './engine/names';
import { tableIndex } from './data/loader';
import { loadLife, saveLife } from './persistence';
import { audioEventFile, playAudio } from './audio';

const COUNTRIES: ReadonlyArray<[string, string, string[]]> = [
  ['us', 'United States', ['New York', 'Los Angeles', 'Chicago', 'Houston']],
  ['gb', 'United Kingdom', ['London', 'Manchester', 'Leeds', 'Glasgow']],
  ['id', 'Indonesia', ['Jakarta', 'Bandung', 'Surabaya', 'Medan']],
  ['mx', 'Mexico', ['Mexico City', 'Guadalajara', 'Monterrey']],
  ['ca', 'Canada', ['Toronto', 'Vancouver', 'Montreal']],
  ['au', 'Australia', ['Sydney', 'Melbourne', 'Brisbane']],
  ['de', 'Germany', ['Berlin', 'Hamburg', 'Munich']],
  ['fr', 'France', ['Paris', 'Lyon', 'Marseille']],
  ['br', 'Brazil', ['São Paulo', 'Rio de Janeiro', 'Salvador']],
  ['in', 'India', ['Mumbai', 'Delhi', 'Bengaluru']],
  ['jp', 'Japan', ['Tokyo', 'Osaka', 'Sapporo']],
  ['kr', 'South Korea', ['Seoul', 'Busan', 'Incheon']],
];

type Phase = 'boot' | 'setup' | 'playing' | 'dead';

function money(value: number): string {
  const sign = value < 0 ? '-' : '';
  return `${sign}$${Math.abs(Math.round(value)).toLocaleString('en-US')}`;
}

function StatCell({ stat, value, previous }: { stat: StatType; value: number; previous: number }) {
  const delta = value - previous;
  const cls = value <= 25 ? 'low' : value <= 55 ? 'mid' : '';
  return (
    <div className={`stat ${cls}`}>
      <b>{STAT_NAMES[stat]}</b>
      <div className="value">
        <i>{Math.round(value)}</i>
        {delta !== 0 && (
          <span className={`delta ${delta > 0 ? 'up' : 'down'}`}>
            {delta > 0 ? '+' : ''}
            {Math.round(delta)}
          </span>
        )}
      </div>
      <div className="meter">
        <i style={{ width: `${Math.max(0, Math.min(100, value))}%` }} />
      </div>
    </div>
  );
}

export default function App() {
  const [phase, setPhase] = useState<Phase>('boot');
  const [life, setLife] = useState<Life | null>(null);
  const [scenario, setScenario] = useState<Scenario | null>(null);
  const [country, setCountry] = useState('us');
  const [city, setCity] = useState('New York');
  const [busy, setBusy] = useState(false);
  const [tableCount, setTableCount] = useState(0);
  const rng = useRef(new MonoRandom());

  useEffect(() => {
    let mounted = true;
    Promise.allSettled([tableIndex(), loadLife()]).then(([tables, saved]) => {
      if (!mounted) return;
      if (tables.status === 'fulfilled') setTableCount(Object.keys(tables.value).length);
      if (saved.status === 'fulfilled' && saved.value) {
        if (saved.value.life.rngState) {
          try {
            rng.current.restore(saved.value.life.rngState);
          } catch {
            // Reject malformed RNG state and use a fresh stream rather than crash boot.
            rng.current = new MonoRandom(saved.value.life.seed);
          }
        }
        setLife(saved.value.life);
        setPhase(saved.value.life.alive ? 'playing' : 'dead');
      } else {
        setPhase('setup');
      }
    });
    return () => {
      mounted = false;
    };
  }, []);

  useEffect(() => {
    if (!life || (phase !== 'playing' && phase !== 'dead')) return;
    void saveLife(life).catch(() => {
      // Persistence is best-effort; gameplay must still work in private mode.
    });
  }, [life, phase]);

  const cities = useMemo(
    () => COUNTRIES.find(([code]) => code === country)?.[2] ?? [],
    [country],
  );

  useEffect(() => {
    if (cities.length && !cities.includes(city)) setCity(cities[0]);
  }, [cities, city]);

  const start = useCallback(() => {
    rng.current = new MonoRandom();
    const fresh = createLife(rng.current, country, city);
    setLife(fresh);
    setScenario(null);
    setPhase('playing');
  }, [country, city]);

  const ageUp = useCallback(async () => {
    if (!life || busy || !life.alive) return;
    setBusy(true);
    const next: Life = {
      ...life,
      stats: { ...life.stats },
      domainState: { ...(life.domainState ?? {}) },
      scenarioQueue: [...(life.scenarioQueue ?? [])],
    };
    const result = runAnnualPipeline(next, rng.current);
    if (result.died) {
      logEvent(next, `Died of ${result.cause} at ${next.age}.`);
      setLife(next);
      setScenario(null);
      setPhase('dead');
      setBusy(false);
      return;
    }
    const ageUpAudio = audioEventFile('age-up');
    if (ageUpAudio) playAudio(ageUpAudio, 0.8);
    const queuedRoute = consumeRoute(next.scenarioQueue ?? []);
    const rolled = queuedRoute
      ? await rollQueuedScenario(next, rng.current, queuedRoute)
      : await rollScenario(next, rng.current);
    next.rngState = rng.current.snapshot();
    setLife(next);
    setScenario(rolled);
    setBusy(false);
  }, [life, busy]);

  const choose = useCallback(
    (index: number) => {
      if (!life || !scenario) return;
      const choice = scenario.choices[index];
      if (!choice || !choiceIsAvailable(choice, life)) return;
      const next: Life = {
        ...life,
        stats: { ...life.stats },
        domainState: { ...(life.domainState ?? {}) },
        scenarioQueue: [...(life.scenarioQueue ?? [])],
      };
      applyChoiceEffects(next, choice);
      enqueueRoute(next.scenarioQueue ??= [], choice.routeTo);
      logEvent(next, choice.log);
      setLife(next);
      setScenario(null);
    },
    [life, scenario],
  );

  if (phase === 'boot') {
    return (
      <div className="app">
        <div className="hero">
          <h1>BitLife</h1>
          <p>Loading game data…</p>
        </div>
      </div>
    );
  }

  if (phase === 'setup') {
    return (
      <div className="app">
        <div className="hero">
          <h1>BitLife</h1>
          <p>How will you live your life?</p>
        </div>
        <div className="card">
          <h3>Country</h3>
          <select value={country} onChange={(e) => setCountry(e.target.value)}>
            {COUNTRIES.map(([code, label]) => (
              <option key={code} value={code}>
                {label}
              </option>
            ))}
          </select>
          <div style={{ height: 10 }} />
          <h3>City</h3>
          <select value={city} onChange={(e) => setCity(e.target.value)}>
            {cities.map((name) => (
              <option key={name} value={name}>
                {name}
              </option>
            ))}
          </select>
        </div>
        <button className="primary" onClick={start}>
          Start Life
        </button>
        <p className="foot">{tableCount} data tables loaded</p>
      </div>
    );
  }

  if (!life) return null;

  if (phase === 'dead') {
    return (
      <div className="app">
        <div className="card obit">
          <h3>Obituary</h3>
          <p>
            {fullName(life.name)} — <span className="age">{life.age}</span>
          </p>
          <p>
            Died of {life.causeOfDeath} in {life.city}, {life.country}.
          </p>
          <p>
            Final happiness {Math.round(life.stats[StatType.Happiness])}, health{' '}
            {Math.round(life.stats[StatType.Health])}, smarts{' '}
            {Math.round(life.stats[StatType.Smarts])}, looks{' '}
            {Math.round(life.stats[StatType.Looks])}.
          </p>
        </div>
        <div className="card">
          <h3>Life log</h3>
          <div className="log">
            {life.log.map((entry, i) => (
              <div key={i}>
                <b>{entry.age}</b>
                <span>{entry.text}</span>
              </div>
            ))}
          </div>
        </div>
        <button className="primary" onClick={() => setPhase('setup')}>
          New Life
        </button>
      </div>
    );
  }

  return (
    <div className="app">
      <div className="topbar">
        <div className="who">
          <strong>{fullName(life.name)}</strong>
          <span>
            Age {life.age} · {life.city}, {life.country}
          </span>
        </div>
        <span className="cash">{money(life.money)}</span>
      </div>

      <div className="stats">
        {DISPLAY_STATS.map((stat) => (
          <StatCell
            key={stat}
            stat={stat}
            value={life.stats[stat]}
            previous={life.previous[stat]}
          />
        ))}
      </div>

      {scenario ? (
        <div className="card">
          {scenario.title && <h3>{scenario.title}</h3>}
          <p>{scenario.body}</p>
          <div className="cta">{scenario.cta}</div>
          <div className="choices">
            {scenario.choices.map((choice, i) => {
              const available = choiceIsAvailable(choice, life);
              return (
                <button
                  key={i}
                  className="choice"
                  onClick={() => choose(i)}
                  disabled={!available}
                  title={available ? undefined : 'Requirements not met'}
                >
                  {choice.text}
                </button>
              );
            })}
          </div>
        </div>
      ) : (
        <div className="card">
          <h3>Age {life.age}</h3>
          <p>Nothing is happening right now.</p>
        </div>
      )}

      <button className="primary" onClick={ageUp} disabled={busy}>
        {busy ? '…' : 'Age Up'}
      </button>

      <div className="card">
        <h3>Life log</h3>
        <div className="log">
          {[...life.log].reverse().map((entry, i) => (
            <div key={i} className={i === 0 ? 'hot' : ''}>
              <b>{entry.age}</b>
              <span>{entry.text}</span>
            </div>
          ))}
        </div>
      </div>
    </div>
  );
}

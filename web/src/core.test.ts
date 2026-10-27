import { describe, expect, it } from 'vitest';
import type { Life } from './engine/life';
import { decodeCsvBytes, parseCsv } from './csv';
import { MonoRandom } from './rng';
import { StatType, impactStat, pointsForImpact } from './stats';
import { executeGenesisActions, evaluateGenesisFilters, type GenesisState } from './engine/genesis';

describe('Mono System.Random compatibility', () => {
  it('snapshots and restores the exact generator position', () => {
    const rng = new MonoRandom(42);
    rng.nextDouble();
    const snapshot = rng.snapshot();
    const expected = [rng.nextDouble(), rng.next(0, 100), rng.nextInt()];
    rng.restore(snapshot);
    expect([rng.nextDouble(), rng.next(0, 100), rng.nextInt()]).toEqual(expected);
    expect(snapshot.seedArray).toHaveLength(56);
  });

  it('matches the known Mono seed-1 sequence', () => {
    const rng = new MonoRandom(1);
    expect(rng.nextDouble()).toBeCloseTo(0.24866858415709278, 15);
    expect(rng.nextDouble()).toBeCloseTo(0.11074397718102856, 15);
    expect(rng.next(0, 100)).toBe(46);
  });

  it('uses an exclusive upper bound for integer ranges', () => {
    const rng = new MonoRandom(123);
    for (let i = 0; i < 100; i++) {
      const value = rng.next(3, 7);
      expect(value).toBeGreaterThanOrEqual(3);
      expect(value).toBeLessThan(7);
    }
  });
});

describe('stat impact mapping', () => {
  it('maps authored impact scores and clamps at both boundaries', () => {
    expect(pointsForImpact(-6)).toBe(-100);
    expect(pointsForImpact(-1)).toBe(-4);
    expect(pointsForImpact(1)).toBe(4);
    expect(pointsForImpact(6)).toBe(100);

    const stats = { [StatType.Happiness]: 2 } as Record<StatType, number>;
    const result = impactStat(stats, StatType.Happiness, -1, 20);
    expect(result.after).toBe(0);
    expect(result.delta).toBe(-2);
  });

  it('ignores negative impact for children through age four', () => {
    const stats = { [StatType.Health]: 50 } as Record<StatType, number>;
    const result = impactStat(stats, StatType.Health, -6, 4);
    expect(result.applied).toBe(false);
    expect(stats[StatType.Health]).toBe(50);
  });
});

describe('annual pipeline ordering', () => {
  it('records annual stage order and RNG draws for a deterministic trace', async () => {
    const { runAnnualPipeline } = await import('./engine/life');
    const trace: string[] = [];
    const rng = new MonoRandom(1);
    const life = {
      age: 20,
      alive: true,
      stats: { [StatType.Health]: 50 } as Life['stats'],
      previous: {} as Life['previous'],
      incrementing: false,
    } as Life;
    const result = runAnnualPipeline(life, rng, {
      onSimulation: (_life, annual) => trace.push(`simulation:${annual.aged}:${annual.died}`),
      onUi: () => trace.push('ui'),
      onMemory: () => trace.push('memory'),
    });
    expect(result.aged).toBe(true);
    expect(trace).toEqual(['simulation:true:false', 'ui', 'memory']);
    expect(result.rngDraws).toBe(1);
    expect(life.rngState?.drawCount).toBeGreaterThan(0);
  });

  it('snapshots previous stats before simulation and runs memory after UI', async () => {
    const { runAnnualPipeline } = await import('./engine/life');
    const events: string[] = [];
    const life = {
      age: 0,
      alive: true,
      stats: { [StatType.Health]: 50 } as Life['stats'],
      previous: {} as Life['previous'],
      incrementing: false,
    } as Life;
    const result = runAnnualPipeline(life, new MonoRandom(1), {
      onSimulation: () => events.push('simulation'),
      onUi: () => events.push('ui'),
      onMemory: () => events.push('memory'),
    });
    expect(result.aged).toBe(true);
    expect(events).toEqual(['simulation', 'ui', 'memory']);
    expect(life.previous[StatType.Health]).toBe(50);
  });
});

describe('persistence format', () => {
  it('round-trips a life through export/import and preserves the save version', async () => {
    const { deserializeSave, serializeSave } = await import('./persistence');
    const life = {
      seed: 7,
      age: 12,
      alive: true,
      name: { first: 'A', last: 'B' },
      gender: 'male' as const,
      country: 'us',
      city: 'New York',
      causeOfDeath: null,
      stats: {} as Life['stats'],
      money: 10,
      log: [],
      previous: {} as Life['previous'],
      incrementing: false,
      domainState: { karma: 2 },
      scenarioQueue: ['queued-route'],
      rngState: new MonoRandom(7).snapshot(),
    };
    const restored = deserializeSave(serializeSave(life));
    expect(restored?.version).toBe(2);
    expect(restored?.life).toEqual(life);
  });

  it('migrates version-one saves by adding the current envelope fields', async () => {
    const { migrateSave } = await import('./persistence');
    const migrated = migrateSave({
      version: 1,
      savedAt: '2026-01-01T00:00:00.000Z',
      life: { age: 3, alive: true },
    });
    expect(migrated?.version).toBe(2);
    expect(migrated?.life.incrementing).toBe(false);
  });
});

describe('audio manifest', () => {
  it('exposes a browser audio URL for extracted WAV files', async () => {
    const { audioUrl } = await import('./audio');
    expect(audioUrl('a16_SFX_BdaySH_Completed.wav')).toContain('/audio/');
    expect(audioUrl('a16_SFX_BdaySH_Completed.wav')).toContain('.wav');
  });

  it('maps only explicitly registered audio events', async () => {
    const { audioEventFile } = await import('./audio');
    expect(audioEventFile('age-up')).toBe('a16_SFX_BdaySH_Completed.wav');
    expect(audioEventFile('unknown-event')).toBeNull();
  });
});

describe('APK scenario header schema', () => {
  it('matches the enum counts and preserves exact enum order', async () => {
    const { DESIGNER_HEADERS, LEGACY_HEADERS } = await import('./engine/scenario-schema');
    expect(DESIGNER_HEADERS).toHaveLength(54);
    expect(LEGACY_HEADERS).toHaveLength(33);
    expect(DESIGNER_HEADERS[16]).toBe('Choice1_Text');
    expect(DESIGNER_HEADERS[48]).toBe('BlueprintPayloadForRoute');
    expect(LEGACY_HEADERS[13]).toBe('ActionList');
    expect(LEGACY_HEADERS[31]).toBe('RandomSelection');
  });
});

describe('domain effect registry', () => {
  it('contains every authored domain from the extracted coverage report', async () => {
    const { DOMAIN_DEFINITIONS, normalizeDomainName } = await import('./engine/domain-registry');
    expect(Object.keys(DOMAIN_DEFINITIONS).length).toBe(102);
    expect(normalizeDomainName('Street Smarts')).toBe('street_smarts');
    expect(DOMAIN_DEFINITIONS.karma.category).toBe('special');
    expect(DOMAIN_DEFINITIONS.relationship.category).toBe('relationship');
  });
});

describe('choice effect application', () => {
  it('applies authored stat effects to only the named stats', async () => {
    const { applyChoiceEffects } = await import('./engine/actions');
    const life = {
      age: 20,
      stats: {
        [StatType.Happiness]: 50,
        [StatType.Health]: 50,
        [StatType.Smarts]: 50,
        [StatType.Looks]: 50,
      } as Record<StatType, number>,
    };
    const result = applyChoiceEffects(life, {
      impact: 0,
      effects: { happiness: 2, health: -1 },
    });
    expect(result.applied).toEqual({ happiness: 8, health: -4 });
    expect(life.stats[StatType.Happiness]).toBe(58);
    expect(life.stats[StatType.Health]).toBe(46);
    expect(life.stats[StatType.Smarts]).toBe(50);
  });

  it('reports authored domain effects that have no implemented state target', async () => {
    const { applyChoiceEffects } = await import('./engine/actions');
    const life = {
      age: 20,
      stats: { [StatType.Happiness]: 50 } as Record<StatType, number>,
    };
    const result = applyChoiceEffects(life, {
      impact: 0,
      effects: { karma: 2, relationship: -1, happiness: 1 },
    });
    expect(result.applied).toEqual({ happiness: 4 });
    expect(result.unsupported).toEqual({ karma: 2, relationship: -1 });
  });

  it('records authored domain effects in domain state when the target state exists', async () => {
    const { applyChoiceEffects } = await import('./engine/actions');
    const life = {
      age: 20,
      stats: { [StatType.Happiness]: 50 } as Record<StatType, number>,
      domainState: {},
    };
    const result = applyChoiceEffects(life, {
      impact: 0,
      effects: { karma: 2, relationship: -1 },
    });
    expect(result.applied).toEqual({});
    expect(result.unsupported).toEqual({});
    expect(life.domainState).toEqual({ karma: 2, relationship: -1 });
  });
});

describe('scenario eligibility and weighting', () => {
  it('applies age, gender, country, and stat gates from a CSV row', async () => {
    const { scenarioRowAccepts } = await import('./engine/scenario');
    const csv = parseCsv(
      'Hero Min Age,Hero Max Age,Hero Gender,Country,Min Happiness,Max Health,Scenario,Choice 1\n' +
        '18,40,male,us,60,80,Body,Go\n',
    );
    const life = {
      age: 25,
      gender: 'male' as const,
      country: 'us',
      city: 'New York',
      stats: {
        [StatType.Happiness]: 70,
        [StatType.Health]: 75,
      } as Life['stats'],
    };
    expect(scenarioRowAccepts(csv, csv.rows[0], life)).toBe(true);
    life.stats[StatType.Happiness] = 59;
    expect(scenarioRowAccepts(csv, csv.rows[0], life)).toBe(false);
  });

  it('weighted selection never chooses a zero-weight row', async () => {
    const { weightedPick } = await import('./engine/scenario');
    const rng = new MonoRandom(1);
    expect(weightedPick(['zero', 'chosen'], [0, 100], rng)).toBe('chosen');
  });
});

describe('scenario row compiler', () => {
  it('compiles designer rows with four choices and named stat effects', async () => {
    const { compileScenarioRow } = await import('./engine/scenario');
    const csv = parseCsv(
      'Index,Title,Body,CTA,Choice 1,Route To 1,Happiness Impact 1,Choice 2,Route To 2,Health Impact 2,Choice 3,Choice 4\n' +
        '7,Title,Body text,Choose,Train,next,4,Rest,,-8,Run,Dance\n'
    );
    const result = compileScenarioRow(csv, csv.rows[0], 0);
    expect(result?.choices).toHaveLength(4);
    expect(result?.body).toBe('Body text');
    expect(result?.choices[0]).toMatchObject({ text: 'Train', routeTo: 'next', effects: { happiness: 4 } });
    expect(result?.choices[1]).toMatchObject({ effects: { health: -8 } });
  });

  it('captures domain-specific impacts that have no stat handler yet', async () => {
    const { compileScenarioRow } = await import('./engine/scenario');
    const csv = parseCsv(
      'Index,Body,Choice 1,Narrative 1,Respect Impact 1,Flight Impact 1,Karma Impact 1\n' +
        '1,Body,Go,Log,3,2,-1\n',
    );
    const result = compileScenarioRow(csv, csv.rows[0], 0);
    expect(result?.choices[0].effects).toEqual({
      respect: 3,
      flight: 2,
      karma: -1,
    });
  });

  it('does not invent random effects when a row has no impact columns', async () => {
    const { compileScenarioRow } = await import('./engine/scenario');
    const csv = parseCsv('Scenario,CTA,Yes Choice,No Choice\nEvent,Choose,Yes,No\n');
    const result = compileScenarioRow(csv, csv.rows[0], 0);
    expect(result?.choices[0].impact).toBe(0);
    expect(result?.choices[0].effects).toEqual({});
  });

  it('preserves designer route metadata, advanced logic, cost, and age-up flags', async () => {
    const { compileScenarioRow } = await import('./engine/scenario');
    const csv = parseCsv(
      'ScenarioID,Body,Choice 1 Text,Choice 1 Route To,Choice 1 Impacts,Choice 1 Advanced Logic,Choice Currency Cost,Is Age Up Scenario,Blueprint Payload For Route\n' +
        's1,Body,Accept,next,Health=2,Health>=50,25,true,route-data\n',
    );
    const result = compileScenarioRow(csv, csv.rows[0], 0);
    expect(result).toMatchObject({
      id: 's1',
      currencyCost: 25,
      isAgeUpScenario: true,
      blueprintPayload: 'route-data',
    });
    expect(result?.choices[0]).toMatchObject({
      routeTo: 'next',
      impactsPayload: 'Health=2',
      advancedLogic: 'Health>=50',
      effects: { health: 2 },
    });
  });

  it('evaluates typed Genesis logic with grouping, negation, contains, and in', async () => {
    const { evaluateAdvancedLogic } = await import('./engine/scenario');
    const life = {
      age: 25,
      gender: 'male' as const,
      country: 'us',
      city: 'New York',
      money: 100,
      alive: true,
      stats: {
        [StatType.Health]: 75,
        [StatType.Happiness]: 40,
      } as Life['stats'],
    } as Life;
    expect(evaluateAdvancedLogic('(Health>=50 && Age in [18,25]) && !Gender=female', life)).toBe(true);
    expect(evaluateAdvancedLogic('City contains "York"', life)).toBe(true);
    expect(evaluateAdvancedLogic('Gender=female || Country=ca', life)).toBe(false);
    expect(evaluateAdvancedLogic('UnknownThing>=1', life)).toBe(false);
  });

  it('exposes whether a choice advanced-logic gate is satisfied', async () => {
    const { choiceIsAvailable } = await import('./engine/scenario');
    const life = { age: 25, gender: 'male' as const, country: 'us', money: 0, alive: true, stats: { [StatType.Health]: 70 } as Life['stats'] } as Life;
    expect(choiceIsAvailable({ advancedLogic: 'Health>=50' }, life)).toBe(true);
    expect(choiceIsAvailable({ advancedLogic: 'Health>=80' }, life)).toBe(false);
    expect(choiceIsAvailable({}, life)).toBe(true);
  });

  it('follows a route target through a queued scenario map', async () => {
    const { followChoiceRoute } = await import('./engine/scenario');
    const result = followChoiceRoute(
      { id: 'start', title: '', body: '', cta: '', choices: [{ text: 'go', impact: 0, effects: {}, routeTo: 'next', log: '' }] },
      new Map([
        ['next', { id: 'next', title: 'Next', body: 'Follow-up', cta: '', choices: [] }],
      ]),
    );
    expect(result?.id).toBe('next');
  });

  it('queues and consumes a route without losing order', async () => {
    const { enqueueRoute, consumeRoute } = await import('./engine/scenario');
    const queue: string[] = [];
    enqueueRoute(queue, 'first');
    enqueueRoute(queue, 'second');
    expect(consumeRoute(queue)).toBe('first');
    expect(consumeRoute(queue)).toBe('second');
    expect(consumeRoute(queue)).toBeNull();
  });

  it('compiles a queued route identifier from a real table row', async () => {
    const { compileQueuedScenario } = await import('./engine/scenario');
    const csv = parseCsv('ScenarioID,Body,Choice 1\nnext,Follow-up,Continue\n');
    await expect(compileQueuedScenario('next', csv)).resolves.toMatchObject({ id: 'next', body: 'Follow-up' });
  });
});

describe('Genesis typed filters and blueprint interpreter', () => {
  it('evaluates native Genesis filter operators against vars and entity properties', () => {
    const state: GenesisState = {
      vars: { mood: 'happy', score: '8' },
      entities: { npc1: { id: 'npc1', type: 'npc', properties: { role: 'friend', score: '8' } } },
      collections: {}, slots: {}, featureContainers: {}, transient: {},
    };
    expect(evaluateGenesisFilters(state, [
      { filter: 'Entity', data: 'role', operator: 'EQUAL', parameters: ['friend'], entityId: 'npc1' },
      { filter: 'Genesis', data: 'mood', operator: 'EQUAL', parameters: ['happy'] },
      { filter: 'Genesis', data: 'score', operator: 'GREAT', parameters: ['7'] },
    ])).toBe(true);
    expect(evaluateGenesisFilters(state, [{ filter: 'Genesis', data: 'mood', operator: 'EQUAL', parameters: ['sad'], not: true }])).toBe(true);
  });

  it('executes supported BlueprintType actions transactionally and reports unsupported types', () => {
    const state: GenesisState = { vars: {}, entities: {}, collections: {}, slots: {}, featureContainers: {}, transient: {} };
    const result = executeGenesisActions(state, [
      { type: 'SetGenesisVar', varName: 'score', value: '9' },
      { type: 'CreateEntity', entityId: 'npc1', entityType: 'npc', properties: { role: 'friend' } },
      { type: 'ModifyEntity', entityId: 'npc1', modifications: { score: '9' } },
      { type: 'AddToGfcCollection', containerId: 'social', collectionName: 'friends', entityId: 'npc1' },
      { type: 'AssignSlot', root: 'hero', referenceProperty: 'bestFriend', entityRef: 'npc1' },
      { type: 'Telemetry', eventName: 'ignored' },
    ]);
    expect(result.applied).toEqual(['SetGenesisVar', 'CreateEntity', 'ModifyEntity', 'AddToGfcCollection', 'AssignSlot']);
    expect(result.unsupported).toEqual(['Telemetry']);
    expect(state.vars.score).toBe('9');
    expect(state.entities.npc1.properties.score).toBe('9');
    expect(state.collections['social:friends']).toEqual(['npc1']);
    expect(state.slots['hero:bestFriend']).toBe('npc1');
  });

  it('rolls back the whole action batch when a supported action has invalid payload', () => {
    const state: GenesisState = { vars: { score: '1' }, entities: {}, collections: {}, slots: {}, featureContainers: {}, transient: {} };
    expect(() => executeGenesisActions(state, [
      { type: 'SetGenesisVar', varName: 'score', value: '2' },
      { type: 'CreateEntity', entityType: 'npc', properties: {} },
    ])).toThrow(/entityId/i);
    expect(state.vars.score).toBe('1');
  });
});

describe('CSV parser', () => {
  it('decodes Windows-1252 bytes without replacement characters', () => {
    const decoded = decodeCsvBytes(new Uint8Array([0x53, 0x61, 0x79, 0x20, 0x93, 0x79, 0x65, 0x73, 0x94]), 'cp1252');
    expect(decoded).toBe('Say “yes”');
  });

  it('preserves quoted commas and escaped quotes', () => {
    const table = parseCsv('Name,Text\nA,"hello, world"\nB,"say ""yes"""');
    expect(table.rows).toEqual([
      ['A', 'hello, world'],
      ['B', 'say "yes"'],
    ]);
  });

  it('preserves multiline quoted fields', () => {
    const table = parseCsv('Name,Text\nA,"line one\nline two"');
    expect(table.rows).toEqual([['A', 'line one\nline two']]);
  });
});

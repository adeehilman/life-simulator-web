export interface GenesisEntity {
  id: string;
  type: string;
  properties: Record<string, string>;
  alive?: boolean;
}

export interface GenesisState {
  vars: Record<string, string>;
  entities: Record<string, GenesisEntity>;
  collections: Record<string, string[]>;
  slots: Record<string, string | null>;
  featureContainers: Record<string, Record<string, string>>;
  transient: Record<string, GenesisEntity>;
}

export type GenesisFilter = {
  filter: string;
  data?: string;
  operator?: string;
  parameters?: unknown[];
  entityId?: string;
  not?: boolean;
};

export type GenesisAction = {
  type: string;
  [key: string]: unknown;
};

export interface GenesisExecutionResult {
  applied: string[];
  unsupported: string[];
}

const OPERATOR_ALIASES: Record<string, string> = {
  GREAT: '>',
  GREATER: '>',
  LESS: '<',
  GREATER_OR_EQUAL: '>=',
  LESS_OR_EQUAL: '<=',
  EQUAL: '=',
  NOT_EQUAL: '!=',
  '>': '>',
  '<': '<',
  '>=': '>=',
  '<=': '<=',
  '=': '=',
  '==': '=',
  '!=': '!=',
};

function compare(actual: string | undefined, operator: string, expected: unknown): boolean {
  if (actual === undefined) return false;
  const op = OPERATOR_ALIASES[operator.toUpperCase()] ?? operator;
  const expectedText = String(expected ?? '');
  const leftNumber = Number(actual);
  const rightNumber = Number(expectedText);
  if (actual.trim() !== '' && expectedText.trim() !== '' && Number.isFinite(leftNumber) && Number.isFinite(rightNumber)) {
    switch (op) {
      case '>': return leftNumber > rightNumber;
      case '<': return leftNumber < rightNumber;
      case '>=': return leftNumber >= rightNumber;
      case '<=': return leftNumber <= rightNumber;
      case '=': return leftNumber === rightNumber;
      case '!=': return leftNumber !== rightNumber;
      default: return false;
    }
  }
  switch (op) {
    case '=': return actual.toLowerCase() === expectedText.toLowerCase();
    case '!=': return actual.toLowerCase() !== expectedText.toLowerCase();
    default: return false;
  }
}

function filterValue(state: GenesisState, filter: GenesisFilter): string | undefined {
  const data = filter.data ?? '';
  const filterName = filter.filter.toLowerCase();
  if (filterName === 'genesis' || filterName === 'alias' || filterName === 'feature') return state.vars[data];
  if (filterName === 'entity') {
    const entity = filter.entityId ? state.entities[filter.entityId] : undefined;
    return entity?.properties[data];
  }
  if (filterName === 'hero') return state.vars[data] ?? state.entities.hero?.properties[data];
  return undefined;
}

export function evaluateGenesisFilters(state: GenesisState, filters: readonly GenesisFilter[]): boolean {
  return filters.every((filter) => {
    const operator = filter.operator ?? 'EQUAL';
    const expected = filter.parameters?.[0] ?? filter.data;
    const result = compare(filterValue(state, filter), operator, expected);
    return filter.not ? !result : result;
  });
}

function cloneState(state: GenesisState): GenesisState {
  return {
    vars: { ...state.vars },
    entities: Object.fromEntries(Object.entries(state.entities).map(([id, entity]) => [id, {
      ...entity,
      properties: { ...entity.properties },
    }])),
    collections: Object.fromEntries(Object.entries(state.collections).map(([key, values]) => [key, [...values]])),
    slots: { ...state.slots },
    featureContainers: Object.fromEntries(Object.entries(state.featureContainers).map(([key, values]) => [key, { ...values }])),
    transient: Object.fromEntries(Object.entries(state.transient).map(([id, entity]) => [id, {
      ...entity,
      properties: { ...entity.properties },
    }])),
  };
}

function replaceState(target: GenesisState, source: GenesisState): void {
  target.vars = source.vars;
  target.entities = source.entities;
  target.collections = source.collections;
  target.slots = source.slots;
  target.featureContainers = source.featureContainers;
  target.transient = source.transient;
}

function requiredString(action: GenesisAction, key: string): string {
  const value = action[key];
  if (typeof value !== 'string' || !value.trim()) throw new Error(`${action.type} requires ${key}`);
  return value;
}

function collectionKey(action: GenesisAction): string {
  return `${requiredString(action, 'containerId')}:${requiredString(action, 'collectionName')}`;
}

function applyAction(state: GenesisState, action: GenesisAction): boolean {
  switch (action.type) {
    case 'SetGenesisVar': {
      state.vars[requiredString(action, 'varName')] = requiredString(action, 'value');
      return true;
    }
    case 'CreateEntity': {
      const id = requiredString(action, 'entityId');
      const type = requiredString(action, 'entityType');
      const properties = action.properties;
      if (!properties || typeof properties !== 'object' || Array.isArray(properties)) throw new Error('CreateEntity requires properties');
      state.entities[id] = { id, type, properties: { ...(properties as Record<string, string>) }, alive: true };
      return true;
    }
    case 'CreateTransientObject': {
      const id = requiredString(action, 'entityId');
      const type = requiredString(action, 'entityType');
      state.transient[id] = { id, type, properties: { ...((action.properties ?? {}) as Record<string, string>) }, alive: true };
      return true;
    }
    case 'ClearTransientObject': {
      delete state.transient[requiredString(action, 'entityId')];
      return true;
    }
    case 'ModifyEntity': {
      const id = requiredString(action, 'entityId');
      const entity = state.entities[id];
      if (!entity) throw new Error(`ModifyEntity unknown entity ${id}`);
      const modifications = action.modifications;
      if (!modifications || typeof modifications !== 'object' || Array.isArray(modifications)) throw new Error('ModifyEntity requires modifications');
      Object.assign(entity.properties, modifications as Record<string, string>);
      return true;
    }
    case 'ResetEntities': {
      const type = requiredString(action, 'entityType');
      for (const id of Object.keys(state.entities)) if (state.entities[id].type === type) delete state.entities[id];
      return true;
    }
    case 'AddToGfcCollection':
    case 'AddToCappedCollection': {
      const key = collectionKey(action);
      const id = requiredString(action, 'entityId');
      const values = state.collections[key] ?? (state.collections[key] = []);
      if (!values.includes(id)) values.push(id);
      if (action.type === 'AddToCappedCollection' && typeof action.cap === 'number' && action.cap >= 0) {
        state.collections[key] = values.slice(-action.cap);
      }
      return true;
    }
    case 'RemoveFromGfcCollection': {
      const key = collectionKey(action);
      const id = requiredString(action, 'entityId');
      state.collections[key] = (state.collections[key] ?? []).filter((item) => item !== id);
      return true;
    }
    case 'AssignEntity': {
      const key = collectionKey(action);
      const id = requiredString(action, 'targetEntityId');
      if (!state.entities[id] && !state.transient[id]) throw new Error(`AssignEntity unknown entity ${id}`);
      state.collections[key] = [id];
      if (typeof action.flagProperty === 'string') {
        const entity = state.entities[id] ?? state.transient[id];
        entity.properties[action.flagProperty] = 'true';
      }
      return true;
    }
    case 'AssignSlot': {
      const root = requiredString(action, 'root');
      const property = requiredString(action, 'referenceProperty');
      state.slots[`${root}:${property}`] = action.isClear === true ? null : requiredString(action, 'entityRef');
      return true;
    }
    case 'InitFeatureContainer': {
      state.featureContainers[requiredString(action, 'containerId')] ??= {};
      return true;
    }
    case 'GfcSetString': {
      const container = state.featureContainers[requiredString(action, 'containerId')] ??= {};
      container[requiredString(action, 'propertyName')] = requiredString(action, 'value');
      return true;
    }
    case 'GfcModifyProperty': {
      const container = state.featureContainers[requiredString(action, 'containerId')] ??= {};
      const name = requiredString(action, 'propertyName');
      const operation = requiredString(action, 'operation').toLowerCase();
      const current = Number(container[name] ?? 0);
      const value = Number(action.value ?? action.amount);
      if (!Number.isFinite(value)) throw new Error('GfcModifyProperty requires numeric value or amount');
      container[name] = String(operation === 'subtract' || operation === '-' ? current - value : current + value);
      return true;
    }
    default:
      return false;
  }
}

export function executeGenesisActions(state: GenesisState, actions: readonly GenesisAction[]): GenesisExecutionResult {
  const snapshot = cloneState(state);
  const applied: string[] = [];
  const unsupported: string[] = [];
  try {
    for (const action of actions) {
      if (applyAction(state, action)) applied.push(action.type);
      else unsupported.push(action.type);
    }
  } catch (error) {
    replaceState(state, snapshot);
    throw error;
  }
  return { applied, unsupported };
}

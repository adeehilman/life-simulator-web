import { getNumber, get, type CsvTable } from '../csv';
import { table, tablesWith } from './loader';

export interface CareerRecord {
  career: string;
  companyType: string;
  requiredEducation: string;
  salary: number;
  salaryCap: number;
  attribute: string;
}

export interface CountryRecord {
  country: string;
  code: string;
  region: string;
}

export interface DiseaseRecord {
  disease: string;
  healthImpact: number;
  happinessImpact: number;
  appearanceImpact: number;
  intelligenceImpact: number;
}

export interface RelationshipScenarioRecord {
  feedback: string;
  minRelationship: number;
  maxRelationship: number;
  minAge: number;
  maxAge: number;
}

let careerPromise: Promise<CareerRecord[]> | null = null;
let countryPromise: Promise<CountryRecord[]> | null = null;
let diseasePromise: Promise<DiseaseRecord[]> | null = null;
let relationshipPromise: Promise<RelationshipScenarioRecord[]> | null = null;

async function firstTable(columns: readonly string[], fallback: RegExp): Promise<CsvTable | null> {
  const names = await tablesWith(columns);
  const selected = names.find((name) => fallback.test(name)) ?? names[0];
  return selected ? table(selected) : null;
}

export function loadCareers(): Promise<CareerRecord[]> {
  careerPromise ??= table('a16_careers').then((csv) => csv.rows.map((row) => ({
    career: get(csv, row, 'Career'),
    companyType: get(csv, row, 'Company Type'),
    requiredEducation: get(csv, row, 'Required Education'),
    salary: getNumber(csv, row, 'Starting Salary'),
    salaryCap: getNumber(csv, row, 'Salary Cap'),
    attribute: get(csv, row, 'Success Defining Attribute'),
  })));
  return careerPromise;
}

export function loadCountries(): Promise<CountryRecord[]> {
  countryPromise ??= firstTable(['Country', 'Country Code'], /country/i).then((csv) =>
    csv ? csv.rows.map((row) => ({
      country: get(csv, row, 'Country'),
      code: get(csv, row, 'Country Code'),
      region: get(csv, row, 'Region'),
    })) : [],
  );
  return countryPromise;
}

export function loadDiseases(): Promise<DiseaseRecord[]> {
  diseasePromise ??= firstTable(['Health Impact Score'], /disease-types/i).then((csv) =>
    csv ? csv.rows.map((row) => ({
      disease: get(csv, row, 'Disease'),
      healthImpact: getNumber(csv, row, 'Health Impact Score'),
      happinessImpact: getNumber(csv, row, 'Happiness Impact Score'),
      appearanceImpact: getNumber(csv, row, 'Appearance Impact Score'),
      intelligenceImpact: getNumber(csv, row, 'Intelligence Impact Score'),
    })) : [],
  );
  return diseasePromise;
}

export function loadRelationshipScenarios(): Promise<RelationshipScenarioRecord[]> {
  relationshipPromise ??= firstTable(['Min Relationship', 'Max Relationship'], /relationship/i).then((csv) =>
    csv ? csv.rows.map((row) => ({
      feedback: get(csv, row, 'Feedback'),
      minRelationship: getNumber(csv, row, 'Min Relationship', -100),
      maxRelationship: getNumber(csv, row, 'Max Relationship', 100),
      minAge: getNumber(csv, row, 'Min Age', 0),
      maxAge: getNumber(csv, row, 'Max Age', 200),
    })) : [],
  );
  return relationshipPromise;
}

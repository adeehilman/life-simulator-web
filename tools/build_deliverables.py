"""Build the full scenario + asset deliverable set.

Inputs already on disk:
  out/strings.txt            every il2cpp string literal (72k)
  out/scenario_catalog.json  scenario classes grouped by the game's own category
  work/apk/assets/bin/.../global-metadata.dat

Outputs:
  out/scenarios/<category>.txt  one scenario per line, so a category is a file
  out/scenarios/_index.md       category table with counts
  out/strings_by_topic/         literal corpus split by topic keyword
"""
import json
import os
import re
import textwrap

CATALOG = 'out/scenario_catalog.json'
SCEN_DIR = 'out/scenarios'
TOPIC_DIR = 'out/strings_by_topic'

TOPICS = {
    'choices': [r'What will you do', r'^(Yes|No|Accept|Decline|Refuse)$'],
    'narrative': [r'\.\s', r'\byou\b'],
    'ui': [r'^UI[A-Z]', r'Button$', r'Label$'],
    'careers': [r'career', r'job', r'salar', r'boss', r'promotion'],
    'money': [r'money', r'\$', r'bank', r'balance', r'price'],
    'relationships': [r'marri', r'dating', r'lover', r'friend', r'divorce'],
    'crime': [r'prison', r'police', r'arrest', r'crime', r'heist'],
    'health': [r'health', r'doctor', r'hospital', r'disease'],
}


def safe(name):
    return re.sub(r'[^A-Za-z0-9._ -]', '_', name).strip() or 'unnamed'


def write_scenarios():
    os.makedirs(SCEN_DIR, exist_ok=True)
    catalog = json.load(open(CATALOG))
    by_cat = catalog['scenarios_by_category']
    index = ['# Scenario catalog', '',
             'Extracted from BitLife 3.25.3 (com.candywriter.bitlife, versionCode 1066).',
             'Source: il2cpp metadata MonoScript records carrying the original',
             r'`\Assets\Game\Scenario\Actual Scenarios\<Category>\<Name>.cs` paths.', '']
    total = 0
    for category in sorted(by_cat):
        names = by_cat[category]
        total += len(names)
        with open(os.path.join(SCEN_DIR, safe(category) + '.txt'), 'w', encoding='utf-8') as fh:
            fh.write('\n'.join(names) + '\n')
        index.append(f'- `{category}` — {len(names)}')
    with open(os.path.join(SCEN_DIR, '_uncategorized.txt'), 'w', encoding='utf-8') as fh:
        fh.write('\n'.join(catalog['uncategorized']) + '\n')
    index += ['', f'Uncategorized scenario classes: {len(catalog["uncategorized"])}',
              f'Total categorized: {total}']
    with open(os.path.join(SCEN_DIR, '_index.md'), 'w', encoding='utf-8') as fh:
        fh.write('\n'.join(index) + '\n')
    return total, len(catalog['uncategorized'])


def write_topics():
    os.makedirs(TOPIC_DIR, exist_ok=True)
    lines = open('out/strings.txt', encoding='utf-8', errors='replace').read().split('\n')
    buckets = {k: [] for k in TOPICS}
    for line in lines:
        if not line.strip():
            continue
        for topic, patterns in TOPICS.items():
            if any(re.search(p, line, re.I) for p in patterns):
                buckets[topic].append(line)
    for topic, rows in buckets.items():
        with open(os.path.join(TOPIC_DIR, topic + '.txt'), 'w', encoding='utf-8') as fh:
            fh.write('\n'.join(rows) + '\n')
    return {k: len(v) for k, v in buckets.items()}


def main():
    total, uncategorized = write_scenarios()
    topics = write_topics()
    print('scenarios', total, 'uncategorized', uncategorized)
    print('topic buckets', topics)


if __name__ == '__main__':
    main()

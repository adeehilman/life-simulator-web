const mods = Process.enumerateModules().filter(m =>
  m.name.startsWith('lib') && (m.size > 10 * 1024 * 1024 || /il2cpp|unity|dCC/i.test(m.name))
).map(m => ({ name: m.name, base: m.base.toString(), size: m.size, path: m.path }));
send({ kind: 'modules', modules: mods, arch: Process.arch });

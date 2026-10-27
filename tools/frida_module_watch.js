function report() {
  const hits = Process.enumerateModules().filter(m => /il2cpp|unity|libmain|dCC/i.test(m.name));
  send({ kind: 'modules', modules: hits.map(m => ({name:m.name, base:m.base.toString(), size:m.size, path:m.path})), arch: Process.arch });
}
report();
let dlopen = null;
try {
  const libdl = Process.getModuleByName('libdl.so');
  dlopen = libdl.getExportByName('android_dlopen_ext');
} catch (_) {}
if (!dlopen) {
  try { dlopen = Process.getModuleByName('libdl.so').getExportByName('dlopen'); } catch (_) {}
}
if (dlopen) {
  Interceptor.attach(dlopen, { onEnter(args) { this.path = args[0].isNull() ? '' : args[0].readCString(); }, onLeave(retval) { if (this.path && /il2cpp|unity|\.so/i.test(this.path)) send({kind:'dlopen', path:this.path, result:retval.toString()}); report(); } });
}
setInterval(report, 2000);
setInterval(() => {}, 1000);

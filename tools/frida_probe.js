const targets = {
  DataHub_GetRandomNumber: 0x15c11e4,
  GameReference_GetRandomNumber: 0x1f6e4b0,
  IncrementAgeSimulation: 0x2575e18,
  IncrementAge: 0x2575df4,
  IncrementAgeUI: 0x257b1ac,
  RandomRangeInt: 0x5047e0c,
};

function sendMsg(kind, data) {
  send({ kind, ...data });
}

const mod = Process.findModuleByName('libil2cpp.so');
if (!mod) {
  sendMsg('error', { message: 'libil2cpp.so not found', modules: Process.enumerateModules().map(m => m.name) });
} else {
  sendMsg('module', { name: mod.name, base: mod.base.toString(), size: mod.size, path: mod.path, arch: Process.arch });
  sendMsg('il2cpp-check', { range: mod.base.toString() + '-' + mod.base.add(mod.size).toString() });
  for (const [name, rva] of Object.entries(targets)) {
    const address = mod.base.add(rva);
    let hooked = false;
    try {
      Interceptor.attach(address, {
        onEnter(args) {
          this.t0 = Date.now();
          sendMsg('enter', { name, rva: '0x' + rva.toString(16), address: address.toString(), args: [args[0].toString(), args[1].toString(), args[2].toString(), args[3].toString()] });
        },
        onLeave(retval) {
          sendMsg('leave', { name, retval: retval.toString(), elapsedMs: Date.now() - this.t0 });
        }
      });
      hooked = true;
    } catch (e) {
      sendMsg('hook-error', { name, rva: '0x' + rva.toString(16), address: address.toString(), error: String(e) });
    }
    sendMsg('hook', { name, rva: '0x' + rva.toString(16), address: address.toString(), hooked });
  }
}
setInterval(() => {}, 1000);

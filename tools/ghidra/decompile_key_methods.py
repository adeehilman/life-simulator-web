# Ghidra headless script: decompile key methods from libil2cpp.so
# Usage (from ghidra_12.2_PUBLIC/support):
#   ./analyzeHeadless <projDir> <projName> -import <libil2cpp.so> \
#     -scriptPath <dir with this> -postScript decompile_key_methods.py \
#     -scriptLog out.log
#
# Outputs C pseudo-code for each target RVA to a file.

import os

from ghidra.app.decompiler import DecompInterface
from ghidra.program.model.listing import CodeUnit
from ghidra.util.task import ConsoleTaskMonitor

TARGETS = {
    # Life.IncrementAge -> IncrementAgeSimulation + UI
    0x2575DF4: "Life_IncrementAge",
    0x2575E18: "Life_IncrementAgeSimulation",
    0x257B1AC: "Life_IncrementAgeUI",
}

monitor = ConsoleTaskMonitor()
fm = currentProgram.getFunctionManager()
listing = currentProgram.getListing()

decomp = DecompInterface()
decomp.openProgram(currentProgram)

out_path = os.path.join(os.environ.get('GHIDRA_OUT', '.'), 'ghidra_decompile.txt')
with open(out_path, 'w') as fh:
    for rva, label in TARGETS.items():
        addr = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(rva)
        func = fm.getFunctionContaining(addr)
        if func is None:
            # try to create function at address
            func = fm.createFunction(None, addr)
        fh.write("\n\n===== %s @ 0x%X (%s) =====" % (label, rva, func.getName() if func else "NOFUNC"))
        fh.write("\n")
        if func is None:
            continue
        res = decomp.decompileFunction(func, 60, monitor)
        if res and res.decompileCompleted():
            fh.write(res.getDecompiledFunction().getC())
        else:
            fh.write("DECOMPILE FAILED\n")

print("done ->", out_path)

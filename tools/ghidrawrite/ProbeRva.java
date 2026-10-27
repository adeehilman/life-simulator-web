// Probe: print image base and what function contains target RVAs.
import ghidra.program.model.address.Address;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.listing.Function;

public class ProbeRva extends GhidraScript {
    public void run() throws Exception {
        long[] rvas = { 0x2575DF4L, 0x2575E18L };
        Address min = currentProgram.getMinAddress();
        Address max = currentProgram.getMaxAddress();
        println("MIN " + min + " MAX " + max);
        for (long rva : rvas) {
            Address a = currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(rva);
            Function f = getFunctionContaining(a);
            println("rva=0x" + Long.toHexString(rva) + " -> func=" +
                    (f == null ? "NULL" : f.getName()));
        }
    }
}


// Decompile key methods at RVAs; reuse existing fn if present.
import java.io.File;
import java.io.PrintWriter;
import ghidra.app.decompiler.DecompInterface;
import ghidra.app.decompiler.DecompileResults;
import ghidra.app.script.GhidraScript;
import ghidra.program.model.address.Address;
import ghidra.program.model.listing.Function;

public class DecompileKeyMethods extends GhidraScript {
    private static final long[] RVAS = { 0x2575DF4L, 0x2575E18L, 0x257B1ACL, 0x1D18318L,
        0x5047DB8L, 0x5047E0CL, 0x1BDB3CCL, 0x1BDB8E8L,
        0x2575954L, 0x1D8BA6CL, 0x1D98320L, 0x1D97C08L,
        0x1D909DCL, 0x1A6B61CL,
        0x1064660L, 0x1F760A0L, 0x1D10B48L, 0x1D10C44L,
        0x15C11E4L, 0x1F6E4B0L };
    private static final String[] LABELS = {
        "Life_IncrementAge", "Life_IncrementAgeSimulation", "Life_IncrementAgeUI",
        "Sim_UpdateStatesForAge", "UnityEngine_Random_RangeFloat", "UnityEngine_Random_RangeInt",
        "ZooAnimal_GetHappiness", "SimPerson_GetSmarts", "Life_ValidateAndSetScenario",
        "Scenario_LoadDesignerFormat", "Scenario_CreateDesignerScenarioCondition",
        "Scenario_ParseDesignerBluePrintPayload", "Scenario_LoadLegacyFormat",
        "RandomDeckCollection_ValidateAndSetScenario",
        "Life_IncrementAgeSimulation_Thunk", "GameReference_AttributeAdjustmentPointsForImpactScore",
        "SimPerson_ImpactHappiness", "SimPerson_ImpactHealth",
        "DataHub_GetRandomNumber", "GameReference_GetRandomNumber"
    };
    public void run() throws Exception {
        DecompInterface decomp = new DecompInterface();
        decomp.openProgram(currentProgram);
        File outFile = new File(System.getProperty("user.home"), "ghidra_decompile.txt");
        try (PrintWriter pw = new PrintWriter(outFile)) {
            for (int i = 0; i < RVAS.length; i++) {
                pw.println("===== " + LABELS[i] + " @ 0x" + Long.toHexString(RVAS[i]) + " =====");
                pw.flush();
                Address a = addr(RVAS[i]);
                Function f = getFunctionContaining(a);
                int txId = currentProgram.startTransaction("t");
                try {
                    if (f == null || !f.getName().equals(LABELS[i])) {
                        if (f != null) currentProgram.getFunctionManager().removeFunction(f.getEntryPoint());
                        disassemble(a);
                        currentProgram.getFunctionManager().createFunction(
                                LABELS[i], a,
                                new ghidra.program.model.address.AddressSet(a),
                                ghidra.program.model.symbol.SourceType.USER_DEFINED);
                    }
                } finally { currentProgram.endTransaction(txId, true); }
                f = getFunctionContaining(a);
                if (f == null) { pw.println("NO FUNCTION"); pw.flush(); continue; }
                try {
                    DecompileResults res = decomp.decompileFunction(f, 60, monitor);
                    if (res != null && res.decompileCompleted()) { pw.println(res.getDecompiledFunction().getC()); }
                    else { pw.println("DECOMPILE INCOMPLETE"); }
                } catch (Exception e) { pw.println("EXC: " + e.getMessage()); }
                pw.flush();
            }
            System.out.println("[DONE]");
            println("WROTE -> " + outFile.getAbsolutePath());
            System.out.flush();
        }
    }
    private Address addr(long rva) {
        return currentProgram.getAddressFactory().getDefaultAddressSpace().getAddress(rva);
    }
}


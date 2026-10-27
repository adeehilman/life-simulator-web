@echo off
set JAVA_HOME=C:\Users\Ade\jdk25\jdk-25.0.4.1+1
set GHIDRA=C:\Users\Ade\ghidra_extract\ghidra_12.2_PUBLIC
set PROJ=C:\Users\Ade\ghidra_proj
set SCRIPTS=D:\Clean Folder\Gabut\reverse-engineer-bitlife\tools\ghidrawrite
cd /d "%GHIDRA%\support"
call analyzeHeadless.bat "%PROJ%" BitLife -process libil2cpp.so -noanalysis -scriptPath "%SCRIPTS%" -postScript ProbeRva.java

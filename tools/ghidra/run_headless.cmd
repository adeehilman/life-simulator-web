@echo off
set JAVA_HOME=C:\Users\Ade\jdk25\jdk-25.0.4.1+1
set GHIDRA=C:\Users\Ade\ghidra_extract\ghidra_12.2_PUBLIC
set PROJ=C:\Users\Ade\ghidra_proj
set SO=D:\Clean Folder\Gabut\reverse-engineer-bitlife\work\native\libil2cpp.so
set SCRIPTS=D:\Clean Folder\Gabut\reverse-engineer-bitlife\tools\ghidra
cd /d "%GHIDRA%\support"
call analyzeHeadless.bat "%PROJ%" BitLife -import "%SO%" -scriptPath "%SCRIPTS%" -postScript decompile_key_methods.py

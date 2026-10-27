@echo off
set VENV=C:\Users\Ade\AppData\Roaming\Ghidra\ghidra_12.2_PUBLIC\venv
"%VENV%\Scripts\python.exe" -m pip install --no-index --find-links "C:\Users\Ade\ghidra_extract\ghidra_12.2_PUBLIC\Ghidra\Features\PyGhidra\pypkg\dist" pyghidra
if errorlevel 1 exit /b 1
"%VENV%\Scripts\python.exe" -c "import pyghidra; print('pyghidra OK', pyghidra.__version__)"
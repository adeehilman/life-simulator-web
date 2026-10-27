@echo off
"C:\Program Files\FlyEnv-Data\app\python-3.14.6\python.exe" -m venv "C:\Users\Ade\AppData\Roaming\Ghidra\ghidra_12.2_PUBLIC\venv"
if errorlevel 1 exit /b 1
dir "C:\Users\Ade\AppData\Roaming\Ghidra\" | findstr venv
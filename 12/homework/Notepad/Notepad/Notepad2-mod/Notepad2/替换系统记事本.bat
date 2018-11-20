@ECHO OFF & CD /D %~DP0
>NUL 2>&1 REG.exe query "HKU\S-1-5-19" || (
    ECHO SET UAC = CreateObject^("Shell.Application"^) > "%TEMP%\Getadmin.vbs"
    ECHO UAC.ShellExecute "%~f0", "%1", "", "runas", 1 >> "%TEMP%\Getadmin.vbs"
    "%TEMP%\Getadmin.vbs"
    DEL /f /q "%TEMP%\Getadmin.vbs" 2>NUL
    Exit /b
)
if "%PROCESSOR_ARCHITECTURE%"=="x86" reg add "HKLM\Software\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\notepad.exe" /f /v "Debugger" /t REG_SZ /d "\"%~dp0Notepad2.exe\" /z" >NUL 2>NUL
If "%PROCESSOR_ARCHITECTURE%"=="AMD64" reg add "HKLM\Software\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\notepad.exe" /f /v "Debugger" /t REG_SZ /d "\"%~dp0Notepad2_x64.exe\" /z" >NUL 2>NUL
CLS & ECHO. & ECHO 替换完成，任意键退出！ &&PAUSE>NUL & EXIT

@ECHO OFF & CD /D %~DP0
>NUL 2>&1 REG.exe query "HKU\S-1-5-19" || (
    ECHO SET UAC = CreateObject^("Shell.Application"^) > "%TEMP%\Getadmin.vbs"
    ECHO UAC.ShellExecute "%~f0", "%1", "", "runas", 1 >> "%TEMP%\Getadmin.vbs"
    "%TEMP%\Getadmin.vbs"
    DEL /f /q "%TEMP%\Getadmin.vbs" 2>NUL
    Exit /b
)
taskkill /f /im notepad* >NUL 2>NUL
reg delete "HKLM\Software\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\notepad.exe" /f
reg delete "HKLM\Software\Wow6432Node\Microsoft\Windows NT\CurrentVersion\Image File Execution Options\notepad.exe" /f
ECHO. & ECHO 恢复完成，任意键退出！ &&PAUSE>NUL & EXIT
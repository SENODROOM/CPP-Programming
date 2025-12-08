@echo off
set PATH=C:\msys64\ucrt64\bin;%PATH%
echo Building Chess...
g++ main.cpp -IC:/msys64/ucrt64/include -LC:/msys64/ucrt64/lib -lsfml-graphics -lsfml-window -lsfml-system -o app.exe
if %errorlevel% neq 0 (
    echo Build failed!
    pause
    exit /b %errorlevel%
)
echo Build successful! Running app.exe...
app.exe

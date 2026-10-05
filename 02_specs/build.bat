@echo off
setlocal

set "SCRIPT_DIR=%~dp0"
set "SOURCE_DIR=%SCRIPT_DIR%"
set "BUILD_DIR=%SCRIPT_DIR%_build\html"

where sphinx-build >nul 2>&1
if errorlevel 1 (
    echo sphinx-build was not found on PATH.
    echo Install the documentation dependencies with:
    echo   python -m pip install -r "%SCRIPT_DIR%requirements.txt"
    exit /b 1
)

echo Building AUTOSAR specifications...
sphinx-build -b html -c "%SOURCE_DIR%" "%SOURCE_DIR%" "%BUILD_DIR%"
if errorlevel 1 (
    echo Sphinx build failed.
    exit /b 1
)

echo Build complete:
echo %BUILD_DIR%\index.html
exit /b 0

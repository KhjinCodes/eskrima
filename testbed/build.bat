REM Build script for Testbed
@ECHO OFF
SetLocal EnableDelayedExpansion

REM Get a list of all the .c files
SET cFilenames=
For /R %%f in (*.c) do (
    SET cFilenames=!Filenames! %%f
)

REM echo "Files:" %cFilenames%

SET assembly=testbed
SET compilerFlags=-g
REM -Wall -Werror
SET includeFlags=-Isrc -I../engine/src
SET linkerFlags=-L../bin/ -lengine.lib
SET defines=-D_DEBUG -DEIMPORT

ECHO Building !assembly!...
clang %cFilenames% %compilerFlags% -o ../bin/%assembly%.exe %defines% %includeFlags% %linkerFlags%
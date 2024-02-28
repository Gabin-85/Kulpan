@ECHO OFF
REM Build Everything

@rem ECHO "Building everything..."

@rem PUSHD engine
@rem CALL build.bat
@rem POPD
@rem IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

@rem PUSHD testbed
@rem CALL build.bat
@rem POPD
@rem IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

REM Engine
make -f "Makefile.engine.windows.mak" all
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

REM Testbed
make -f "Makefile.testbed.windows.mak" all
IF %ERRORLEVEL% NEQ 0 (echo Error:%ERRORLEVEL% && exit)

ECHO "All assemblies built successfully."
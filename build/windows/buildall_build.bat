:create ./bin/windows directory
set BUILDROOT=%3
set winout=win_%1_%2
set bindir=%BUILDROOT%\bin\%winout%
if exist %bindir% (
    echo %bindir% exist
) else (
    mkdir %bindir%
)

:REM build commonlib
set makefile=%BUILDROOT%/commonlib/build/windows/makefile
cd %BUILDROOT%/commonlib
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
cd ..


:REM build sqlenforcer
set makefile=%BUILDROOT%/sqlenforcer/build/windows/makefile
cd %BUILDROOT%/sqlenforcer
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy %winout%\sqlenforcer.dll  %bindir%
copy %winout%\sqlenforcer.lib  %bindir%
copy %winout%\sqlenforcer.dll.pdb  %bindir%
cd ..

REM :REM build policymgr
REM set makefile=%BUILDROOT%/policymgr/build/windows/makefile
REM cd %BUILDROOT%/policymgr
REM call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
REM IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
REM copy %winout%\policymgr.dll  %bindir%
REM copy %winout%\policymgr.lib  %bindir%
REM copy %winout%\policymgr.dll.pdb  %bindir%
REM cd ..

:REM build sqlparser
set makefile=%BUILDROOT%/sqlparser/libsql2003/build/windows/makefile
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
cd %BUILDROOT%/sqlparser/libsql2003
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
copy %winout%\sql2003.dll  %bindir%
copy %winout%\sql2003.lib  %bindir%
copy %winout%\sql2003.dll.pdb  %bindir%



:REM build odbc32
set makefile=%BUILDROOT%/odbcdm/win32/build/windows/makefile
cd %BUILDROOT%/odbcdm/win32
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy %winout%\odbc32.dll  %bindir%
copy %winout%\odbc32.lib  %bindir%
copy %winout%\odbc32.dll.pdb  %bindir%

:REM build jdbc_jni
set makefile=%BUILDROOT%/jdbc/jdbc_jni/build/makefile
cd %BUILDROOT%/jdbc/jdbc_jni
call %BUILDROOT%/build/windows/build.bat %makefile%
:IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy .\bin\com.nextlabs.jdbc.jni.jar  %bindir%

:REM build jdbc_oracle
set makefile=%BUILDROOT%/jdbc/jdbc_oracle/build/makefile
cd %BUILDROOT%/jdbc/jdbc_oracle
call %BUILDROOT%/build/windows/build.bat %makefile%
:IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy .\bin\ojdbc8.jar  %bindir%

:REM build jdbc_hana
set makefile=%BUILDROOT%/jdbc/jdbc_hana/build/makefile
cd %BUILDROOT%/jdbc/jdbc_hana
call %BUILDROOT%/build/windows/build.bat %makefile%
:IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy .\bin\ngdbc.jar  %bindir%

:REM build jdbc_mssql
set makefile=%BUILDROOT%/jdbc/jdbc_mssql/build/makefile
cd %BUILDROOT%/jdbc/jdbc_mssql
call %BUILDROOT%/build/windows/build.bat %makefile%
:IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy .\bin\mssql-jdbc.jar  %bindir%

:REM build jdbc_emdb_sdk
set makefile=%BUILDROOT%/jdbc_emdb_sdk/build/makefile
cd %BUILDROOT%/jdbc_emdb_sdk
call %BUILDROOT%/build/windows/build.bat %makefile%
:IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy .\bin\emdb1.3.jar  %bindir%


:REM build user attribute
set makefile=%BUILDROOT%/userattribute/build/windows/makefile
cd %BUILDROOT%/userattribute
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy %winout%\userattribute.dll  %bindir%
copy %winout%\userattribute.lib  %bindir%
copy %winout%\userattribute.dll.pdb  %bindir%

:REM build odbc32_ms
set makefile=%BUILDROOT%/odbctest/win32/build/windows/makefile
cd %BUILDROOT%/odbctest/win32
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
copy %winout%\odbc32_ms.dll  %bindir%
copy %winout%\odbc32_ms.lib  %bindir%
copy %winout%\odbc32_ms.dll.pdb  %bindir%

:REM build query_cloud_az_sdk
cd %BUILDROOT%/query_cloud_az_sdk
copy %winout%\QueryCloudAZSDKCpp.dll  %bindir%

:REM build ssleay32
cd %BUILDROOT%/ssleay32
copy %winout%\ssleay32.dll  %bindir%

:REM build libeay32
cd %BUILDROOT%/libeay32
copy %winout%\libeay32.dll  %bindir%

:REM build oci
set makefile=%BUILDROOT%/oci/build/makefile
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
cd %BUILDROOT%/oci
call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
copy %winout%\oci.dll  %bindir%
copy %winout%\oci.lib  %bindir%
copy %winout%\oci.dll.pdb  %bindir%

:REM build install_manager
set makefile=%BUILDROOT%/install/tool/install_manager/build/windows/makefile
IF %1 EQU x64 (
    cd %BUILDROOT%/install/tool/install_manager
    call %BUILDROOT%/build/windows/build.bat %makefile% %1 %2
    IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
    copy %winout%\install_manager.exe  %bindir%
    copy %winout%\install_manager.lib  %bindir%
    copy %winout%\install_manager.exe.pdb  %bindir%
    copy %winout%\NSudoAPI.dll  %bindir%
    copy %winout%\NSudoAPI.pdb  %bindir%
    copy %winout%\NSudoAPI.lib  %bindir%
)

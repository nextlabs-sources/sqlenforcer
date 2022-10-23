
@set PATH=%PATH%;%CYGWINPATH%

set rootdir=%1

cd %rootdir%/commonlib
make.exe -f ./build/windows/makefile clean
cd..

cd %rootdir%/sqlenforcer
make.exe -f ./build/windows/makefile clean
cd..

REM cd %rootdir%/policymgr
REM make.exe -f ./build/windows/makefile clean
REM cd ..

cd %rootdir%/sqlparser/libsql2003
make.exe -f ./build/windows/makefile clean
cd ..

cd %rootdir%/odbcdm/win32
make.exe -f ./build/windows/makefile clean
cd ..

cd %rootdir%/odbctest/win32
make.exe -f ./build/windows/makefile clean
cd ..

cd %rootdir%/userattribute
make.exe -f ./build/windows/makefile clean
cd ..

cd %rootdir%/oci
make.exe -f ./build/makefile clean
cd ..

cd %rootdir%/bin
make.exe -f %rootdir%/build/windows/makefile clean
cd ..

cd %rootdir%/install/tool/install_manager
make.exe -f %rootdir%/build/windows/makefile clean
cd ..

:build.bat {x86|x64} {release|debug}
echo JAVAPATH=%JAVAPATH%
echo BUILDROOT=%BUILDROOT%
echo BOOSTDIR=%BOOSTDIR%
echo OPENSSLDIR=%OPENSSLDIR%
echo CYGWINPATH=%CYGWINPATH%
echo VERSION_BUILD=%VERSION_BUILD%
echo VERSION_BUILD_SHORT=%VERSION_BUILD_SHORT%
echo MAKEFILE=%1
setlocal
set TARGETENVARCH=%2
set BUILDTYPE=%3
call "C:\Program Files (x86)\Microsoft Visual Studio\2019\Professional\Common7\Tools\VsDevCmd.bat" -arch=%2
set PATH=%PATH%;%CYGWINPATH%;%JAVAPATH%\bin
make.exe  -f %1 versioninfo
make.exe  -f %1 copyfiles
make.exe  -f %1
endlocal

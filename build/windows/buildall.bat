:this command is called by Jenkins build job

IF "%1"=="x86" (exit 0)

:set env
set NLEXTERNALDIR=s:/build/P4/source_external
set NLEXTERNALDIR2=s:/build/p4/source_main_external
set NL_SOURCE_GIT_EXTERNAL=s:/build/P4/source_git_external
set JAVAPATH=C:/Program Files/Java/jdk1.8.0_201
set BOOSTDIR="%NLEXTERNALDIR%/boost/boost_1_71_0"
set MSENFORCECOMMON=//nxt-build26.nextlabs.com/workspace
set OPENSSLDIR=%NLEXTERNALDIR%/openssl
set BUILDROOT=%3
set NLBUILDROOT=%3
set MAKE_INSTALLFLAGS="OFFICIALCERT=1 BUILDTYPE=release VERSION_BUILD="
set BUILDTYPE=release
set OFFICIALCERT=1
set VERSION_BUILD=%BUILD_NUMBER%
set	VERSION_BUILD_SHORT=%BUILD_NUMBER%
set VERSION_PRODUCT_EMDB=DAE for Windows
set VERSION_MAJOR_EMDB=2021
set VERSION_MINOR_EMDB=12
set VERSION_STR_EMDB=%VERSION_MAJOR_EMDB%.%VERSION_MINOR_EMDB%.%VERSION_BUILD%
set msbuild="C:/Program Files (x86)/Microsoft Visual Studio/2019/Professional/MSBuild/Current/Bin/MSBuild.exe"

:build for x64
set TARGETENVARCH=x64
call %BUILDROOT%/build/windows/buildall_build.bat %TARGETENVARCH% %BUILDTYPE% %BUILDROOT%

:build for x86
set TARGETENVARCH=x86
call %BUILDROOT%/build/windows/buildall_build.bat %TARGETENVARCH% %BUILDTYPE% %BUILDROOT%

:REM build dae_for_ado_net
set sln=%BUILDROOT%/dae_for_ado_net/DAEforADONET.sln
call %msbuild% %sln% /property:Platform=x86 /p:Configuration=%BUILDTYPE%
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
call %msbuild% %sln% /property:Platform=x64 /p:Configuration=%BUILDTYPE%
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
call %msbuild% %sln% /property:Platform="Any CPU" /p:Configuration=%BUILDTYPE%
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)

:REM build dae_for_windows_service
set sln=%BUILDROOT%/install/tool/dae_for_windows_service/dae_for_windows_service.sln
call %msbuild% %sln% /property:Platform=x64 /p:Configuration=%BUILDTYPE%
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)

:make install package
call %BUILDROOT%/build/windows/buildall_install.bat
IF %ERRORLEVEL% NEQ 0 (exit %ERRORLEVEL%)
#target
EXETARGET=install_manager

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#add include path
compilerflags += /I./include \
              /I./include/commands \
              /I./third_party \
              /I"$(BUILDROOT)/commonlib/include" \
              /I"$(BOOSTDIR)"


#library path
linkerflags += /LIBPATH:"$(BUILDROOT)/commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)"
ifeq ($(TARGETENVARCH), x64)
linkerflags += /LIBPATH:"$(BOOSTDIR)/lib64-msvc-14.2"
linkerflags += /LIBPATH:"./third_party/NSudo/x64"
outputcopyfiles   += ./third_party/NSudo/x64/NSudoAPI.dll
outputcopyfiles   += ./third_party/NSudo/x64/NSudoAPI.pdb
outputcopyfiles   += ./third_party/NSudo/x64/NSudoAPI.lib
else
linkerflags += /LIBPATH:"$(BOOSTDIR)/lib32-msvc-14.2"
linkerflags += /LIBPATH:"./third_party/NSudo/Win32"
outputcopyfiles   += ./third_party/NSudo/Win32/NSudoAPI.dll
outputcopyfiles   += ./third_party/NSudo/Win32/NSudoAPI.pdb
outputcopyfiles   += ./third_party/NSudo/Win32/NSudoAPI.lib
endif


#library
linkerflags += NSudoAPI.lib shell32.lib commonlib.lib Advapi32.lib

SRC=$(wildcard ./src/*.cpp) $(wildcard ./src/commands/*.cpp)

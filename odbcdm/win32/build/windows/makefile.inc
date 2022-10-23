
#target
SUBTARGET=odbc32

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#add include path
compilerflags += /I./include \
                 /I../../sqlenforcer/include \
                 /I"$(BOOSTDIR)" \
                 /I"$(BUILDROOT)/commonlib/include" \
                 /I../../sqlparser/libsql2003/include

#library path
linkerflags += /LIBPATH:"$(BUILDROOT)/commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)"
ifeq ($(TARGETENVARCH), x64)
linkerflags += /LIBPATH:$(BOOSTDIR)/lib64-msvc-14.2
else
linkerflags += /LIBPATH:$(BOOSTDIR)/lib32-msvc-14.2
endif

#library
linkerflags +=  commonlib.lib Shell32.lib Advapi32.lib
           
SRC=$(wildcard  ./src/*.cpp)


DEF=./src/odbc.def

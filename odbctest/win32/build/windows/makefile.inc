#target
SUBTARGET=odbc32_ms

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#add include path
compilerflags += /I./include \
                 /I"$(BUILDROOT)/commonlib/include"

#library path
linkerflags += /LIBPATH:"$(BUILDROOT)/commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)"

#library
linkerflags +=  commonlib.lib Shell32.lib
           
SRC=$(wildcard  ./src/*.cpp)

DEF=./src/odbctest.def

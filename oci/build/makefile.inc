
#target
SUBTARGET=oci

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#add include path
compilerflags += /I./include \
                 /I./include/oci \
                 /I../../sqlenforcer/include \
                 /I"$(BUILDROOT)/commonlib/include" \
                 /I"$(BOOSTDIR)"

#library path
linkerflags += /LIBPATH:"$(BUILDROOT)/commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)"

ifeq ($(TARGETENVARCH), x64)
linkerflags += /LIBPATH:$(BOOSTDIR)/lib64-msvc-14.2
else
linkerflags += /LIBPATH:$(BOOSTDIR)/lib32-msvc-14.2
endif

#library
linkerflags +=  commonlib.lib Shell32.lib Advapi32.lib

OCI_VERSION_PATH=./src/windows/19_11/#end

SRC=$(wildcard  ./src/*.cpp $(OCI_VERSION_PATH)*.cpp)



DIR=$(notdir $(SRC))


DEF=$(OCI_VERSION_PATH)oci.def

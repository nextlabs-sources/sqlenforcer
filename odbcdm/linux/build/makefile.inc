#target
SUBTARGET=libnxlodbc


#define
ccpflag += 

#add include path
ccpflag += -I./include \
           -I$(BUILDROOT)/commonlib/include \


#library path
ccpflag += -L$(BUILDROOT)/commonlib/linux_$(TARGETENVARCH)

#library
ccpflag += -lcommon -ldl

#library
ccpflag += 
           
SRC=$(wildcard  ./src/*.cpp)

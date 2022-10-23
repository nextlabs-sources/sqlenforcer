
#target
SUBTARGET=libsqlenforcer


#define
ccpflag += -DBOOST_LOG_DYN_LINK

#add include path
ccpflag += -I./include \
           -I../commonlib/include \
           -I../sqlparser/libtsql/include  \
           -I$(JAVAPATH)/include  \
           -I$(JAVAPATH)/include/linux \


#library path
ccpflag += -L../commonlib/linux_$(TARGETENVARCH)

#library
ccpflag += -lcommon -lboost_thread -lboost_log
           
SRC=$(wildcard  ./src/*.cpp)

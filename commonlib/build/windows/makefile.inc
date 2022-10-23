

#target
STATICTARGET=commonlib

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#define
compilerflags += 

#add include path
compilerflags += /I./include \
                 /I../sqlenforcer/include \
                 /I../sqlparser/libsql2003/include \
                 /I"$(BOOSTDIR)" \
                 /I"$(OPENSSLDIR)" \
			  /I"$(MSENFORCECOMMON)/prod/QueryCloudAZSDK_C++/QueryCloudAZSDKCpp/include" \
#library path
linkerflags += 

#library
linkerflags +=
           
SRC=$(wildcard  ./src/*.cpp) 
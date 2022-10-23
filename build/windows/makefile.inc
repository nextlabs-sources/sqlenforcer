

#target
SUBTARGET=sqlenforcer

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#define
compilerflags += /DSQLENFORCER_EXPORT \
                /DEMDB_SDK_EXPORT


#add include path
compilerflags += /I./include \
              /I../sqlparser/libsql2003/include \
              /I../policymgr/include \
              /I../userattribute/include \
              /I../commonlib/include \
              /I"$(JAVAPATH)/include" \
              /I"$(JAVAPATH)/include/win32" \
              /I"$(MSENFORCECOMMON)/prod/QueryCloudAZSDK_C++/QueryCloudAZSDKCpp/include" \
              /I"$(BOOSTDIR)"


#library path
linkerflags += /LIBPATH:../commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)
ifeq ($(TARGETENVARCH), x64)
linkerflags += /LIBPATH:$(BOOSTDIR)/lib64-msvc-14.2
else
linkerflags += /LIBPATH:$(BOOSTDIR)/lib32-msvc-14.2
endif



#library
linkerflags += shell32.lib Ole32.lib commonlib.lib Advapi32.lib
           
SRC=$(wildcard  ./src/*.cpp)


#target
SUBTARGET=userattribute

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#define
compilerflags += /DENFORCER_EXPORT

#add include path
compilerflags += /I./include \
                 /I../policymgr/include \
                /I"$(BOOSTDIR)" \
                /I"$(BUILDROOT)/commonlib/include" \
                /I"$(MSENFORCECOMMON)/prod/QueryCloudAZSDK_C++/QueryCloudAZSDKCpp/include" \


#library path
linkerflags += /LIBPATH:"$(BUILDROOT)/commonlib/win_$(TARGETENVARCH)_$(BUILDTYPE)"

#library
linkerflags +=  commonlib.lib Shell32.lib Activeds.lib ADSIid.lib
           
SRC=$(wildcard ./src/*.cpp)

#target
SUBTARGET=sql2003

#DYNAMICCRT: yes/no
DYNAMICCRT=no

#add include path
compilerflags += /I./include \
                 /I../../commonlib/include \

#preprocessor
compilerflags += /DYY_NO_UNISTD_H /DSQLPARSER_EXPORT

SRC=$(wildcard  ./src/*.cpp)
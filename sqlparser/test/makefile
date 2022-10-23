cc=g++
execute=unit_test
src=$(wildcard ./*.cpp)
objs=$(patsubst *.cpp,*.o,${src})
cxxflag = -fPIC -fvisibility=hidden -I./thirdparty

ifeq ($(TARGETENVARCH), x86)
ccpflag +=  -m32
else
ccpflag +=  -m64
endif  

$(execute):$(objs)
	$(cc) $(include) -o $(execute) $(objs) -L ../libtsql/linux_x64 -l tsql -I ../libtsql/include

clean:
	rm -f $(objs) $(execute)





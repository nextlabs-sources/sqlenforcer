cc=g++
artool=ar
SUBTARGET_EXT=so
ccpflag = -fPIC -fvisibility=hidden -std=c++17

ifeq ($(TARGETENVARCH), x86)
ccpflag +=  -m32
else
ccpflag +=  -m64
endif

include $(MAKEFILE_INC) 


BINDIR=linux_$(TARGETENVARCH)
objs = $(addprefix $(BINDIR)/, $(addsuffix .o, $(basename $(notdir $(SRC)))))

#build .so
ifneq ($(SUBTARGET), )
$(BINDIR)/$(SUBTARGET).$(SUBTARGET_EXT):$(objs)
	$(cc) -shared -o $@ $(objs) $(ccpflag)
endif

#build .a
ifneq ($(STATICTARGET), )
$(BINDIR)/$(STATICTARGET).a:$(objs)
	$(artool) crf $@ $(objs)
endif

#compile source file
$(BINDIR)/%.o:./src/%.cpp
	@if [ ! -d $(BINDIR) ] ; then \
		mkdir -p $(BINDIR) ; \
	fi
	$(cc) -c $(ccpflag) $<  -o $@

clean:
	rm -rf linux_x86 linux_x64
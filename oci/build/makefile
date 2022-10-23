MAKEFILE_INC=${BUILDROOT}/oci/build/makefile.inc
#include ${BUILDROOT}/build/windows/makefile


cl=cl.exe
ld=link.exe
RC=rc.exe
static_ld=lib.exe
SUBTARGET_EXT=dll
srcdir=./src
compilerflags= /c  /Fd /Zi /EHsc /W3 /Gm-  /DWIN32 /DNANODBC_THROW_NO_SOURCE_LOCATION
linkerflags=/DLL /DEBUG 
staticflags= 
DYNAMICCRT=no

ifeq ($(VERSION_BUILD), )
VERSION_BUILD=1
endif



RCFLAGS += -D_UNICODE -DUNICODE

BUILDROOT_LINUX=$(subst \,/,$(BUILDROOT))

PROGRAM_FILES_X86=C:/Program Files (x86)

# By default, use build/config/use_default.rc. RCSRC in Makefile.inc overrides 
# this value.
RCSRC = $(srcdir)/use_default.rc

include $(BUILDROOT)/build/Makefile.ver
include $(MAKEFILE_INC)


ifeq ($(BUILDTYPE), release)
compilerflags +=  /O2 
compilerflags +=  /DNDEBUG
ifeq ($(DYNAMICCRT), yes)
compilerflags += /MD
else
compilerflags += /MT
endif 

else
compilerflags += /Od  /D"_DEBUG"

ifeq ($(DYNAMICCRT), yes)
compilerflags += /MDd
else
compilerflags += /MTd
endif 

endif  

ifneq ($(DEF),)
linkerflags += /DEF:$(DEF)
endif

BINDIR=win_$(TARGETENVARCH)_$(BUILDTYPE)
OBJS = $(addprefix $(BINDIR)/, $(addsuffix .obj, $(basename $(notdir $(SRC)))))
RCOBJS = $(addprefix $(BINDIR)/, $(addsuffix .res, $(basename $(notdir $(RCSRC)))))
TARGET = $(BINDIR)/$(SUBTARGET).$(SUBTARGET_EXT);

#build for dll
ifneq ($(SUBTARGET), )
$(BINDIR)/$(SUBTARGET).$(SUBTARGET_EXT): $(OBJS) $(RCOBJS)
	$(ld) $(linkerflags) $(OBJS) $(RCOBJS) /OUT:$@ /PDB:$@.pdb
endif

#build for static library
ifneq ($(STATICTARGET), )
$(BINDIR)/$(STATICTARGET).lib: $(OBJS)
	$(static_ld) $(staticflags) $(OBJS) /OUT:$@
endif

#source file compile
$(BINDIR)/%.obj:$(srcdir)/%.cpp
	@if [ ! -d $(BINDIR) ] ; then \
		mkdir -p $(BINDIR) ; \
	fi
	$(cl) $(compilerflags) $< /Fo$@

$(BINDIR)/%.obj:$(OCI_VERSION_PATH)%.cpp
	@if [ ! -d $(BINDIR) ] ; then \
		mkdir -p $(BINDIR) ; \
	fi
	$(cl) $(compilerflags) $< /Fo$@

# Rule for building the resources
$(BINDIR)/%.res: $(srcdir)/%.rc
	@if [ ! -d $(BINDIR) ] ; then \
	  mkdir -p $(BINDIR) ; \
	fi
	$(RC) $(RCFLAGS) $(RCFLAGS2) $(INCP) -Fo$@ $<

versioninfo:
	@if [ "$(RCSRC)" == "$(srcdir)/use_default.rc" ]; then \
		cp --force ${BUILDROOT_LINUX}/build/windows/config/use_default.rc $(RCSRC); \
		sed --in-place -e 's#VERSION_MAJOR#$(VERSION_MAJOR_EMDB)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_MINOR#$(VERSION_MINOR_EMDB)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_MAINTENANCE#$(VERSION_MAINTENANCE_EMDB)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_PATCH#$(VERSION_PATCH_EMDB)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_PRODUCT#$(VERSION_PRODUCT_EMDB)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_BUILD#$(VERSION_BUILD)#g' $(RCSRC); \
		sed --in-place -e 's#VERSION_ARCHITECTURE#$(TARGETENVARCH)#g' $(RCSRC); \
	else \
		perl $(BUILDROOT)/build/updateVersionInfo_make.pl $(RCSRC) $(VERSION_MAJOR_EMDB) $(VERSION_MINOR_EMDB) $(VERSION_MAINTENANCE_EMDB) $(VERSION_PATCH_EMDB) "$(VERSION_BUILD)" "$(VERSION_PRODUCT_EMDB)" $(TARGETENVARCH); \
	fi

clean:
	rm -rf win_x64_release win_x64_debug win_x86_release win_x86_debug
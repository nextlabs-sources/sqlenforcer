ifeq ($(BUILDROOT),)
  $(error BUILDROOT undefined.)
endif

#ifeq ($(NLEXTERNALDIR),)
#  $(error NLEXTERNALDIR undefined.)
#endif

include $(BUILDROOT)/build/Makefile.ver

PRODUCT_DIR_NAME=DAEForWindows
VERSION_STR=$(VERSION_MAJOR_EMDB).$(VERSION_MINOR_EMDB)
#ISM_TEMPLATE_FILE_NAME_X86=DAEforWin32.ism
ISM_TEMPLATE_FILE_NAME_X64=DAEForWindows.ism
ISM_RELEASE=msi
ISM_PRODUCT_CONFIG64=64bit
MSI_FILE64=NextLabs_DAEForWindows.msi	
TARGETMSI_FILE64_NAME=NextLabs_DAEForWindows.msi	

#ifeq ($(BUILDTYPE),)
#	BUILDTYPE=dev
#endif

ifeq ($(VERSION_BUILD),)
	VERSION_BUILD=1
endif

include $(BUILDROOT)/install/Makefile.install

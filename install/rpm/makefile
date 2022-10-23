# Make sure "make_debuginfo" is run before "make_installer". Otherwise it packs the debug files into the release package.
.PHONY:all
all: make_debuginfo make_installer

.PHONY:make_debuginfo
make_debuginfo:
	rpmbuild -bb emdb_debuginfo.spec

.PHONY:make_installer
make_installer:
	rpmbuild -bb emdb.spec ; \
	cd ${WORKSPACE}/install/rpm/package ; \
	cp -rf ${WORKSPACE}/build/bin/* . ; \
	tar -zcv --remove-files -f ${VER_PROJECT_NAME}-${VER_PROJECT_VERSION}-${VER_BUILD_NUMBER}.tar.gz *

#!/bin/bash

#create ./bin/linux directory
outdir=linux_$1
bindir=./bin/${outdir}
if [ ! -d "$bindir" ];then
mkdir -p $bindir
fi

# build commonlib
cd ./commonlib
make -f ./build/linux/makefile TARGETENVARCH=$1
cd ..


# build sqlenforcer
cd ./sqlenforcer
make -f ./build/linux/makefile TARGETENVARCH=$1
cp  ${outdir}/libsqlenforcer.so ../${bindir}/libsqlenforcer.so
cd ..

# # build policymgr
# cd ./policymgr
# make -f ./build/linux/makefile TARGETENVARCH=$1
# cp ${outdir}/libpolicymgr.so ../${bindir}/libpolicymgr.so
# cd ..

# build tsql
cd ./sqlparser/libtsql
make -f ./build/linux/makefile TARGETENVARCH=$1
cp ${outdir}/libtsql.so ../../${bindir}/libtsql.so
cd ../..

# build nxlodbc
cd ./odbcdm/linux
make -f ./build/makefile TARGETENVARCH=$1
cp ${outdir}/libnxlodbc.so ../../${bindir}/libnxlodbc.so
cd ../..

# build JDBC
cd ./jdbc
make -f ./build/makefile
cp ./bin/nxljdbc1.3.jar ../${bindir}/nxljdbc1.3.jar
cd ../..

# build emdb_sdk
cd ./jdbc_emdb_sdk
make -f ./build/makefile
cp ./bin/emdb1.3.jar ../${bindir}/emdb1.3.jar
cd ../..
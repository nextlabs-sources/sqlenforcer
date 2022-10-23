#!/bin/bash

#create ./bin/linux directory
bindir=./bin/linux/$1


# build sqlenforcer
cd ./sqlenforcer
make -f ./build/linux/makefile clean
cd ..

# # build policymgr
# cd ./policymgr
# make -f ./build/linux/makefile clean
# cd ..

cd ./sqlparser/libtsql
make -f ./build/linux/makefile clean
cd ../..

cd ./odbcdm/linux
make -f ./build/makefile clean
cd ../..


cd ./jdbc
make -f ./build/makefile clean
cd ../

#rm -r -f ./bin/linux/
#!/bin/bash
source /opt/rh/devtoolset-7/enable

#get parameters
TARGETENVARCH=x64
if [[ -n $1 ]]
then
TARGETENVARCH=$1
fi
echo "TARGETENVARCH=${TARGETENVARCH}"

CMAKE="cmake3"

export VER_PROJECT_NAME=NextLabs_DAEForLinux
export VERSION_MAJOR=2022
export VERSION_MINOR=07
export VERSION_PATCH=0
export VER_BUILD_NUMBER=${BUILD_NUMBER:=1}
export VER_PROJECT_VERSION=${VERSION_MAJOR}.${VERSION_MINOR}.${VERSION_PATCH}

RELEASE_CANDIDATE_PATH="${SDRIVE}/build/release_candidate/${VER_PROJECT_NAME}/${VER_PROJECT_VERSION}/${VER_BUILD_NUMBER}"
RELEASE_CANDIDATE_ARTIFACTS_PATH="${SDRIVE}/build/release_candidate/artifacts/${VER_PROJECT_NAME}/${VER_PROJECT_VERSION}/${VER_BUILD_NUMBER}"

cd ${WORKSPACE}/build
#cmake -DTARGETENVARCH=${TARGETENVARCH} -DOPENSSL_ROOT=/usr/local/openssl/openssl-1.1 .
${CMAKE} -DTARGETENVARCH=${TARGETENVARCH} -DCMAKE_BUILD_TYPE=RelWithDebInfo -DOPENSSL_ROOT_DIR=/usr/local/openssl/openssl-1.1 -DBOOSTROOT=/usr/local/boost_1_67_0/ ..
make clean
make -j4

cd ${WORKSPACE}/install/rpm
make

# Archive the release package
${CMAKE} -E make_directory "${RELEASE_CANDIDATE_PATH}"
${CMAKE} -E copy ${WORKSPACE}/install/rpm/package/*.tar.gz "${RELEASE_CANDIDATE_PATH}"
ls -l "${RELEASE_CANDIDATE_PATH}"

# Archive the debug info package
${CMAKE} -E make_directory "${RELEASE_CANDIDATE_ARTIFACTS_PATH}"
${CMAKE} -E copy ${WORKSPACE}/install/rpm/package-debuginfo/*.rpm "${RELEASE_CANDIDATE_ARTIFACTS_PATH}"
ls -l "${RELEASE_CANDIDATE_ARTIFACTS_PATH}"
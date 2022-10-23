//
// Created by jeff on 2021/6/15.
//

#include "DAEOciWrapper.h"
__attribute__((constructor))
void OCI_INIT() {
    DAEOCIMgrApi::Instance();
}
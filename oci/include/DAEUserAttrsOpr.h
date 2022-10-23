//
// Created by jeff on 2021/6/22.
//

#ifndef DAE_DAEUSERATTRSOPR_H
#define DAE_DAEUSERATTRSOPR_H

#include "stdafx.h"
#include <map>
#include <string>

class DAEUserAttrsOpr {
public:
    virtual ~DAEUserAttrsOpr(){}

    static void QueryUserAttrs(const std::string & username, std::map<std::string,std::string> & userattrs);

};


#endif //DAE_DAEUSERATTRSOPR_H

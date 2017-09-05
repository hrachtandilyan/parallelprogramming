//
//  TLogLogic.cpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#include "TLogLogic.hpp"

using std::cout;
using std::endl;

using log::TLogLogic;

TLogLogic::TLogLogic() :
stream(std::cout) {
}

TLogLogic::~TLogLogic() {
}

TLogLogic& TLogLogic::operator<<(const string& str) {
    stream << str;
    return *this;
}
//
//  Log.cpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#include "Log.hpp"
#include "LogLogic.hpp"
using log::Log;
using log::LogLogic;

Log::Log(LogLogic *logic) :
logic(logic) {
}

Log& Log::operator<<(const string &str) {
    *logic<<(str);
    return *this;
}

void Log::setLogic(LogLogic *logic) {
    this->logic = logic;
}
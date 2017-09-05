//
//  Log.hpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#ifndef Log_hpp
#define Log_hpp

#include <iostream>
#include <string>

using std::string;

namespace log {
    
    class LogLogic;
    class Log {
    public:
        Log() = delete;
        Log(LogLogic *logic);
        Log& operator<<(const string &str);
        void setLogic(LogLogic *logic);
    private:
        LogLogic *logic;
    };
    

}

#endif /* Log_hpp */

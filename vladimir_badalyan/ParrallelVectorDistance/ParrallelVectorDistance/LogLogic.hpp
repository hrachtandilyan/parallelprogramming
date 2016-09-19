//
//  LogLogic.hpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#ifndef LogLogic_hpp
#define LogLogic_hpp

#include <string>
using std::string;

namespace log {
    
    class LogLogic {
    public:
        LogLogic();
        virtual ~LogLogic() = 0;
        virtual LogLogic& operator<<(const string &str) = 0;
    };
    
}

#endif /* LogLogic_hpp */

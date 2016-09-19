//
//  TLogLogic.hpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#ifndef TLogLogic_hpp
#define TLogLogic_hpp

#include <iostream>
using std::ostream;

#include "LogLogic.hpp"

namespace log {
    
    class TLogLogic : virtual public LogLogic {
    public:
        TLogLogic();
        virtual ~TLogLogic();
        TLogLogic& operator<<(const string& str);
        
    private:
        ostream& stream;
    };
    
}

#endif /* TLogLogic_hpp */

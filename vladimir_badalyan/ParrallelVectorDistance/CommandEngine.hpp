//
//  CommandEngine.hpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#ifndef CommandEngine_hpp
#define CommandEngine_hpp

#include <map>
using std::map;

#include "Commands.hpp"

namespace command {
    
    class CommandEngine {
    public:
        void runLoop();
        void run(string& commandName);
    private:
        map<string, Command> commandsMap;
    };
    
}
#endif /* CommandEngine_hpp */

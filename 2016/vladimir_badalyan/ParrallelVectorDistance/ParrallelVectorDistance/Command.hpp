//
//  Command.hpp
//  ParrallelVectorDistance
//
//  Created by Vladimir Badalyan on 9/19/16.
//  Copyright © 2016 Vladimir Badalyan. All rights reserved.
//

#ifndef Command_hpp
#define Command_hpp

#include <string>
using std::string;

namespace command {
    
    class Command {
    public:
        Command();
        virtual ~Command() = 0;
        void Execute();
        string &getHelpText();
    
    private:
        string helpText;
    };
    
}

#endif /* Command_hpp */

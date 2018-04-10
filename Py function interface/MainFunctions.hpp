//
//  MainFunctions.hpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/9.
//

#ifndef MainFunctions_hpp
#define MainFunctions_hpp

#include <string>

namespace python_func {
    
    class UserProcess {
    public:
        UserProcess(std::string addr);
        virtual ~UserProcess();
        
    };
    
    
}

#endif /* MainFunctions_hpp */

//
//  global.hpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/13.
//

#ifndef global_hpp
#define global_hpp

#include <Python/Python.h>
#include <string>
#include "MainFunctions.hpp"
#include "waitingwindow.h"
#include <functional>

extern python_func::Database *database;

void initDatabase(const std::string &addr, const std::string &user, const std::string &psw, const std::string &dbName);



#endif /* global_hpp */

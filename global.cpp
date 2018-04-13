//
//  global.cpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/13.
//

#include "global.hpp"


python_func::Database *database = nullptr;

void initDatabase(const std::string &addr, const std::string &user, const std::string &psw, const std::string &dbName) {
    database = new python_func::Database(addr, user, psw, dbName);
}

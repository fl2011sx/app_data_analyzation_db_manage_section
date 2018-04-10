//
//  MainFunctions.cpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/9.
//

#include "MainFunctions.hpp"

#include <Python/Python.h>


using python_func::UserProcess;

UserProcess::UserProcess(std::string addr) {
    Py_Initialize();
    
}

UserProcess::~UserProcess() {
    Py_Finalize();
}



//
//  MainFunctions.hpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/9.
//

#ifndef MainFunctions_hpp
#define MainFunctions_hpp

#include <string>
#include <Python/Python.h>
#include <vector>

#define Data_ana_sec_path ("../data_analyze_section")

namespace python_func {
    void initPython();
    void endPython();
    void py_print(PyObject *obj);
    std::string py_to_str(PyObject *obj);
    
    class Database {
    private:
        PyObject *py_Database;
    public:
        Database(const std::string &addr, const std::string &user, const std::string &psw, const std::string &dbName);
        PyObject *query(const std::string &cmd);
        PyObject *getTableColumnsName(const std::string &tableName);
        ~Database();
    };
    
    class UserProcess {
    private:
        PyObject *py_UserProcess;
    public:
        UserProcess(PyObject *db);
        ~UserProcess();
        PyObject *showUsers();
        PyObject *newUsers(int howNew = 604800);
        PyObject *activityUsers(int howNew = 604800);
        PyObject *fillUpUsers(bool isOperatingDatabase = false);
        PyObject *distributionUserPro(const std::string &pro, bool cal_values = false, std::vector<int> *groups = nullptr);
        PyObject *relevancyUserPro(std::vector<std::string> &pros);
        PyObject *valFiltrate(const std::string &dp_var, std::vector<std::string> &id_vars);
        void bashRegistUserByXls(const std::string xlsRoot, const std::string &note = "", bool userRealTime = true);
    };
    
    
}

#endif /* MainFunctions_hpp */

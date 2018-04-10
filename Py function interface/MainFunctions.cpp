//
//  MainFunctions.cpp
//  tpapp_server_manage
//
//  Created by 胡博豪 on 2018/4/9.
//

#include "MainFunctions.hpp"
#include <algorithm>

void python_func::initPython() {
    Py_Initialize();
}

void python_func::endPython() {
    Py_Finalize();
}

void python_func::py_print(PyObject *obj) {
    PyObject *module = PyImport_Import(PyString_FromString("Interface_to_c"));
    PyObject *func = PyObject_GetAttrString(module, "py_print");
    PyObject *arg = PyTuple_New(1);
    PyTuple_SetItem(arg, 0, obj);
    PyObject_CallObject(func, arg);
}

std::string python_func::py_to_str(PyObject *obj) {
    PyObject *module = PyImport_Import(PyString_FromString("Interface_to_c"));
    PyObject *func = PyObject_GetAttrString(module, "py_to_str");
    PyObject *arg = PyTuple_New(1);
    PyTuple_SetItem(arg, 0, obj);
    PyObject *ret = PyObject_CallObject(func, arg);
    std::string ret_str = PyString_AsString(ret);
    return ret_str;
}

using python_func::Database;

Database::Database(const std::string &addr, const std::string &user, const std::string &psw, const std::string &dbName) {
    PyObject *module = PyImport_Import(PyString_FromString("Database"));
    PyObject *dic = PyModule_GetDict(module);
    PyObject *class_Database = PyDict_GetItemString(dic, "Database");
    PyObject *arg = PyTuple_New(4);
    PyTuple_SetItem(arg, 0, PyString_FromString(addr.c_str()));
    PyTuple_SetItem(arg, 1, PyString_FromString(user.c_str()));
    PyTuple_SetItem(arg, 2, PyString_FromString(psw.c_str()));
    PyTuple_SetItem(arg, 3, PyString_FromString(dbName.c_str()));
    py_Database = PyInstance_New(class_Database, arg, nullptr);
}

PyObject *Database::query(const std::string &cmd) {
    PyObject *ret = PyObject_CallMethod(py_Database, "query", "s", cmd.c_str());
    return ret;
}

PyObject *Database::getTableColumnsName(const std::string &tableName) {
    PyObject *ret = PyObject_CallMethod(py_Database, "getTableColumnsName", "s", tableName.c_str());
    return ret;
}

Database::~Database() {
}


using python_func::UserProcess;

UserProcess::UserProcess(PyObject *db) {
    PyObject *module = PyImport_Import(PyString_FromString("MainFunctions"));
    PyObject *dic = PyModule_GetDict(module);
    PyObject *class_UserProcess = PyDict_GetItemString(dic, "UserProcess");
    PyObject *arg = PyTuple_New(1);
    PyTuple_SetItem(arg, 0, db);
    py_UserProcess = PyInstance_New(class_UserProcess, arg, nullptr);
}

PyObject *UserProcess::showUsers() {
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "showUsers", nullptr);
    return ret;
}

PyObject *UserProcess::newUsers(int howNew) {
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "new_users", "i", howNew);
    return ret;
}

PyObject *UserProcess::activityUsers(int howNew) {
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "activity_users", "i", howNew);
    return ret;
}

PyObject *UserProcess::fillUpUsers(bool isOperatingDatabase) {
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "fill_up_time_users", "i", isOperatingDatabase);
    return ret;
}
PyObject *UserProcess::distributionUserPro(const std::string &pro, bool cal_values, std::vector<int> *groups) {
    PyObject *ret;
    if (!groups) {
        ret = PyObject_CallMethod(py_UserProcess, "distribution_user_pro", "si", pro.c_str(), cal_values);
    } else {
        PyObject *list_groups = PyList_New(groups -> size());
        for (std::vector<int>::iterator iter = groups -> begin(); iter != groups -> end(); iter++) {
            PyList_Append(list_groups, PyInt_FromLong(*iter));
        }
        ret = PyObject_CallMethod(py_UserProcess, "distribution_user_pro", "siO", pro.c_str(), cal_values, list_groups);
    }
    return ret;
}
PyObject *UserProcess::relevancyUserPro(std::vector<std::string> &pros) {
    PyObject *list_pros = PyList_New(pros.size());
    for (std::vector<std::string>::iterator iter = pros.begin(); iter != pros.end(); iter++) {
        PyList_Append(list_pros, PyString_FromString(iter -> c_str()));
    }
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "relevancy_user_pro", "O", list_pros);
    return ret;
}
PyObject *UserProcess::valFiltrate(const std::string &dp_var, std::vector<std::string> &id_vars) {
    PyObject *list_id_vars = PyList_New(id_vars.size());
    for (std::vector<std::string>::iterator iter = id_vars.begin(); iter != id_vars.end(); iter++) {
        PyList_Append(list_id_vars, PyString_FromString(iter -> c_str()));
    }
    PyObject *ret = PyObject_CallMethod(py_UserProcess, "val_filtrate", "sO", dp_var.c_str(), list_id_vars);
    return ret;
    
}
void UserProcess::bashRegistUserByXls(const std::string xlsRoot, const std::string &note, bool userRealTime) {
    PyObject_CallMethod(py_UserProcess, "bash_regist_user_by_xls", "ssi", xlsRoot.c_str(), note.c_str(), userRealTime);
}




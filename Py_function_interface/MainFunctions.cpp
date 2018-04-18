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

std::vector<std::string> python_func::py_list_to_vector(PyObject *list) {
    long size = PyList_Size(list);
    std::vector<std::string> vec;
    for (long i = 0; i < size; i++) {
        PyObject *obj = PyList_GetItem(list, i);
        vec.push_back(std::string(PyString_AsString(obj)));
    }
    return vec;
}

std::vector<std::vector<std::string>> python_func::py_matrix_to_vec2(PyObject *list) {
    long size = PyList_Size(list);
    std::vector<std::vector<std::string>> vec;
    for (long i = 0; i < size; i++) {
        std::vector<std::string> vec_in;
        auto item = PyList_GetItem(list, i);
        long size_in = PyList_Size(item);
        for (long j = 0; j < size_in; j++) {
            vec_in.push_back(std::string(PyString_AsString(PyList_GetItem(item, j))));
        }
        vec.push_back(vec_in);
    }
    return vec;
}

PyObject *python_func::py_DataFrame_to_matrix(PyObject *data) {
    PyObject *module = PyImport_Import(PyString_FromString("Interface_to_c"));
    PyObject *func = PyObject_GetAttrString(module, "py_DataFrame_to_matrix");
    PyObject *arg = PyTuple_New(1);
    PyTuple_SetItem(arg, 0, data);
    PyObject *ret = PyObject_CallObject(func, arg);
    return ret;
}

PyObject *python_func::py_get_DataFrame_columns(PyObject *data) {
    PyObject *module = PyImport_Import(PyString_FromString("Interface_to_c"));
    PyObject *func = PyObject_GetAttrString(module, "py_get_DataFrame_columns");
    PyObject *arg = PyTuple_New(1);
    PyTuple_SetItem(arg, 0, data);
    PyObject *ret = PyObject_CallObject(func, arg);
    return ret;
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

PyObject *Database::asPyObject() const {
    return py_Database;
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

PyObject *UserProcess::distributionUserPro(const std::string &pro, bool cal_values, std::vector<double> *groups) {
    PyObject *ret;
    if (!groups) {
        ret = PyObject_CallMethod(py_UserProcess, "distribution_user_pro", "si", pro.c_str(), cal_values);
    } else {
        PyObject *list_groups = PyList_New(0);
        for (std::vector<double>::iterator iter = groups -> begin(); iter != groups -> end(); iter++) {
            PyList_Append(list_groups, PyFloat_FromDouble(*iter));
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

UserProcess::~UserProcess() {
}

PyObject *UserProcess::showProperties() {
    PyObject_CallMethod(py_UserProcess, "showProperties", nullptr);
}

void python_func::drawBarChart(std::vector<double> &data, const std::string &save_root, const std::string &x_title, const std::string &title, const double width, const double gap, const std::string &color, const bool grid, const bool show) {
    PyObject *list = PyList_New(0);
    for (std::vector<double>::iterator iter = data.begin(); iter != data.end(); iter++) {
        PyList_Append(list, PyFloat_FromDouble(*iter));
    }
    py_print(list);
    drawBarChart(list, save_root, x_title, title, width, gap, color, grid, show);
}

void python_func::drawBarChart(PyObject *data, const std::string &save_root, const std::string &x_title, const std::string &title, const double width, const double gap, const std::string &color, const bool grid, const bool show) {
    PyObject *module = PyImport_Import(PyString_FromString("MainFunctions"));
    PyObject *func = PyObject_GetAttrString(module, "draw_bar_chart");
    PyObject *arg = PyTuple_New(9);
    PyTuple_SetItem(arg, 0, data);
    PyTuple_SetItem(arg, 1, x_title == "" ? Py_None :  PyString_FromString(x_title.c_str()));
    PyTuple_SetItem(arg, 2, PyString_FromString(title.c_str()));
    PyTuple_SetItem(arg, 3, PyFloat_FromDouble(width));
    PyTuple_SetItem(arg, 4, PyFloat_FromDouble(gap));
    PyTuple_SetItem(arg, 5, PyString_FromString(color.c_str()));
    PyTuple_SetItem(arg, 6, PyBool_FromLong(grid));
    PyTuple_SetItem(arg, 7, save_root == ""? Py_None : PyString_FromString(save_root.c_str()));
    PyTuple_SetItem(arg, 8, PyBool_FromLong(show));
    PyObject_CallObject(func, arg);
}


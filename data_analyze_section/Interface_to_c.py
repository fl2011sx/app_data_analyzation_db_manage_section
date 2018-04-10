# coding: utf-8
from Database import Database
from MainFunctions import UserProcess

##提供对C/C++的接口支持
def py_print(con):
    print(type(con))
    print(con)

def py_to_str(obj):
    return str(obj)

def py_DataFrame_to_matrix(data):
    mat = data.as_matrix().tolist()
    mat_str = [map(str, el) for el in mat]
    return mat_str

def py_get_DataFrame_columns(data):
    col = data.columns.tolist();
    return col

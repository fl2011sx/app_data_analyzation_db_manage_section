#-------------------------------------------------
#
# Project created by QtCreator 2018-04-09T18:46:54
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tpapp_server_manage
TEMPLATE = app

LIBS += /System/Library/Frameworks/Python.framework/Versions/2.7/lib/ -lpython2.7
INCLUDEPATH += -I /usr/include/Python

SOURCES += main.cpp\
        mainwindow.cpp\
        Py_function_interface/MainFunctions.cpp

HEADERS  += mainwindow.h\
            Py_function_interface/MainFunctions.hpp

FORMS    += mainwindow.ui
QT += widgets

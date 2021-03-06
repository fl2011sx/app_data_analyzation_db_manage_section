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
        Py_function_interface/*.cpp\
        usermanagewindow.cpp\
        global.cpp \
    welcomewindow.cpp \
    loginwindow.cpp \
    statisticswindow.cpp \
    waitingwindow.cpp \
    waitingthread.cpp \
    groupsetwindow.cpp \
    dependencywindow.cpp \
    forcastwindow.cpp \
    addpropertywindow.cpp\
    BPNeuralNet.cpp \
    singleforcast.cpp \
    singleforecastinputwindow.cpp \
    datapreprocesswindow.cpp \
    dataforcast.cpp

HEADERS  += mainwindow.h\
            Py_function_interface/*.hpp\
            usermanagewindow.h\
            global.hpp \
    welcomewindow.h \
    loginwindow.h \
    statisticswindow.h \
    waitingwindow.h \
    waitingthread.h \
    groupsetwindow.h \
    dependencywindow.h \
    forcastwindow.h \
    addpropertywindow.h \
    afteractiondelegate.h\
    BPNeuralNet.hpp \
    singleforcast.h \
    singleforecastinputwindow.h \
    datapreprocesswindow.h \
    dataforcast.hpp

FORMS    += *.ui \
    welcomewindow.ui \
    loginwindow.ui \
    statisticswindow.ui \
    waitingwindow.ui \
    groupsetwindow.ui \
    dependencywindow.ui \
    forcastwindow.ui \
    addpropertywindow.ui \
    singleforcast.ui \
    singleforecastinputwindow.ui \
    datapreprocesswindow.ui

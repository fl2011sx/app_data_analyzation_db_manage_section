#include <QApplication>
#include "Py_function_interface/MainFunctions.hpp"
#include "global.hpp"
#include "welcomewindow.h"

int main(int argc, char *argv[]) {
    python_func::initPython();
    PyRun_SimpleString("import sys");
    std::string imp_data_ana = std::string("sys.path.append(\"") + Data_ana_sec_path + "\")";
    PyRun_SimpleString((std::string("if not ") + imp_data_ana + " in sys.path:\n " + imp_data_ana).c_str());
    QApplication a(argc, argv);
    WelcomeWindow w;
    w.show();
    int ret = a.exec();
    python_func::endPython();
    return ret;
}

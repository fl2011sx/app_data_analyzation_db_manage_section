#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <Python/Python.h>
#include "Py_function_interface/MainFunctions.hpp"
#include "usermanagewindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow) {
    ui->setupUi(this);
    connect(ui -> showUserBtn, SIGNAL(clicked()), this, SLOT(showUser()));
    connect(ui -> userManageBtn, SIGNAL(clicked()), this, SLOT(showUserManageWindow()));
    connect(ui -> debugTest, SIGNAL(clicked()), this, SLOT(debugTest()));
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::debugTest() {
    double arr[] = {2, 5.8, 4, 7.5};
    std::vector<double> ve(arr, arr + 3);
    python_func::drawBarChart(ve, "/Users/hubohao/Desktop/test.png");
}


void MainWindow::showUserManageWindow() {
    auto userManageWindow = new UserManageWindow;
    userManageWindow -> show();
}

void MainWindow::showUser() {
    if (!database) {return;}
    python_func::UserProcess up(database -> asPyObject());

    auto data = up.showUsers();
    auto str = python_func::py_to_str(data);
    printf("%s\n", str.c_str());
    auto matrix = python_func::py_DataFrame_to_matrix(data);
    printf("%s\n", python_func::py_to_str(matrix).c_str());
    auto vec = python_func::py_matrix_to_vec2(matrix);
    for (auto line : vec) {
        for (auto item : line) {
            printf("%s\t", item.c_str());
        }
        printf("\n");
    }
    ui -> displayView -> setRowCount((int)vec.size());
    ui -> displayView -> setColumnCount((int)vec.at(0).size());
    auto col = python_func::py_get_DataFrame_columns(data);
    auto columns = python_func::py_list_to_vector(col);
    for (unsigned long i = 0; i < columns.size(); i++) {
        std::string str = columns.at(i);
        auto item = new QTableWidgetItem;
        item -> setText(str.c_str());
        ui -> displayView -> setHorizontalHeaderItem((int)i, item);
    }
    for (unsigned long i = 0; i < vec.size(); i++) {
        for (unsigned long j = 0; j < vec.at(0).size(); j++) {
            auto item = new QTableWidgetItem;
            item -> setText(vec.at(i).at(j).c_str());
            ui -> displayView -> setItem((int)i, (int)j, item);
        }
    }
}

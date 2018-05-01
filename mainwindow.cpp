#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <Python/Python.h>
#include "Py_function_interface/MainFunctions.hpp"
#include "usermanagewindow.h"
#include "statisticswindow.h"
#include "dependencywindow.h"
#include "forcastwindow.h"
#include "BPNeuralNet.hpp"
#include "dataforcast.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui -> displayView -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    
    connect(ui -> showUserBtn, SIGNAL(clicked()), this, SLOT(showUser()));
    connect(ui -> userManageBtn, SIGNAL(clicked()), this, SLOT(showUserManageWindow()));
    connect(ui -> debugTest, SIGNAL(clicked()), this, SLOT(debugTest()));
    connect(ui -> statisticsBtn, SIGNAL(clicked()), this, SLOT(showStatisticsWindow()));
    connect(ui -> dependencyBtn, &QPushButton::clicked, this, &MainWindow::showDependencyWindow);
    connect(ui -> forecastBtn, &QPushButton::clicked, this, &MainWindow::showForcastWindow);
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::debugTest() {
    double tmp[] = {1.8, 19.6, -3.8, -1, 7.9};
    std::vector<double> vt(tmp, tmp + 5);
    dataProcess::DisperseDataForcast df(vt);
    auto test = df.getData_double();
    for (auto ele : test) {
        qDebug() << ele;
    }
    auto set = df.getArgSet();
    dataProcess::DisperseDataForcast df2(test, set);
    auto test2 = df2.getData_double();
    for (auto ele : test2) {
        qDebug() << ele;
    }
}

void MainWindow::showForcastWindow() {
    auto fw = new forcastWindow();
    fw -> show();
}

void MainWindow::showDependencyWindow() {
    auto dw = new dependencyWindow;
    dw -> show();
}

void MainWindow::showUserManageWindow() {
    auto userManageWindow = new UserManageWindow;
    userManageWindow -> show();
}

void MainWindow::showStatisticsWindow() {
    auto statisticsWindow = new StatisticsWindow;
    statisticsWindow -> show();
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

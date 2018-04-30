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
    double input[] = {0.05, 0.10, -0.4};
    double ouput[] = {0.01, 0.99, 0.77};
    double w1[2][2] = {{0.15, 0.25}, {0.20, 0.30}};
    NeuralNet::Matrix w(2, 2, w1);
    NeuralNet::Matrix wh[] = {w};
    double w2[2][2] = {{0.40, 0.50}, {0.45, 0.55}};
    NeuralNet::Matrix wo(2, 2, w2);
    double b1[] = {0.35};
    
//    NeuralNet::BPNeuralNet bp(2, input, 2, ouput, 1, wh, b1, &wo, 0.60);
    NeuralNet::BPNeuralNet bp(3, input, 3, ouput, 2);
    bp.train(100000);
    for (unsigned i = 0; i < bp.outputCount; i++) {
        qDebug() << NeuralNet::sigmoid(bp.outputNode[i]);
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

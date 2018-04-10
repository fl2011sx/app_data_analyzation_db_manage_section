#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>
#include <Python/Python.h>
#include "MainFunctions.hpp"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QPushButton *debugTest = ui -> debugTest;
    connect(debugTest, SIGNAL(clicked()), this, SLOT(test1()));
}

MainWindow::~MainWindow()
{
    delete ui;
}




void MainWindow::test1() {
    python_func::Database db("127.0.0.1", "root", "FLZdown1km$mysql!", "tpapp");
    auto data = db.getTableColumnsName("users");
    auto str = python_func::py_to_str(data);
    printf("%s\n", str.c_str());
}

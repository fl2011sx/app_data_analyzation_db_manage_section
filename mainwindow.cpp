#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPushButton>
#include <QDebug>

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
    qDebug("hahahahah\n");
}

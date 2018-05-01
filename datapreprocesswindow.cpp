#include "datapreprocesswindow.h"
#include "ui_datapreprocesswindow.h"

DataPreprocessWindow::DataPreprocessWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DataPreprocessWindow)
{
    ui->setupUi(this);
}

DataPreprocessWindow::~DataPreprocessWindow()
{
    delete ui;
}

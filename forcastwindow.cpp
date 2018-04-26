#include "forcastwindow.h"
#include "ui_forcastwindow.h"

forcastWindow::forcastWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forcastWindow)
{
    ui->setupUi(this);
}

forcastWindow::~forcastWindow()
{
    delete ui;
}

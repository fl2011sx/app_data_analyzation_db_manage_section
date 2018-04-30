#include "forcastwindow.h"
#include "ui_forcastwindow.h"
#include "singleforcast.h"

forcastWindow::forcastWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::forcastWindow)
{
    ui->setupUi(this);
    
    setWindowTitle("数值预测");
    
    connect(ui -> singleForcastBtn, &QPushButton::clicked, this, &forcastWindow::showSingleForcast);
}

void forcastWindow::showSingleForcast() {
    auto sfw = new SingleForcast();
    sfw -> show();
}

forcastWindow::~forcastWindow()
{
    delete ui;
}

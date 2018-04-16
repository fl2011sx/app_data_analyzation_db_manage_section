#include "waitingwindow.h"
#include "ui_waitingwindow.h"

WaitingWindow::WaitingWindow(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::WaitingWindow)
{
    ui->setupUi(this);
    QFont font;
    font.setPointSize(36);
    ui -> label -> setFont(font);
}

WaitingWindow::~WaitingWindow()
{
    delete ui;
}

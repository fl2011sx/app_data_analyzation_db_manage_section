#include "welcomewindow.h"
#include "ui_welcomewindow.h"


WelcomeWindow::WelcomeWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::WelcomeWindow),
    loginWindow(new LoginWindow)
{
    ui->setupUi(this);
    connect(ui -> openSystemBtn, SIGNAL(clicked()), this, SLOT(openSystem()));
}

void WelcomeWindow::openSystem() {
    close();
    loginWindow -> show();
}

WelcomeWindow::~WelcomeWindow()
{
    delete loginWindow;
    delete ui;
}

#include "usermanagewindow.h"
#include "ui_usermanagewindow.h"

UserManageWindow::UserManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManageWindow)
{
    ui->setupUi(this);
    
}

UserManageWindow::~UserManageWindow()
{
    delete ui;
}

void UserManageWindow::refresh() {
    
}

void UserManageWindow::addUserProperty() {
    
}

#include "usermanagewindow.h"
#include "ui_usermanagewindow.h"
#include <algorithm>

UserManageWindow::UserManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManageWindow)
{
    ui->setupUi(this);
    connect(ui -> refreshListBtn, SIGNAL(clicked()), this, SLOT(refresh()));
}

UserManageWindow::~UserManageWindow()
{
    delete ui;
}

void UserManageWindow::refresh() {
    auto up = python_func::UserProcess(database -> asPyObject());
    auto list = python_func::py_list_to_vector(up.showProperties());
    for (auto ele : list) {
        puts(ele.c_str());
    }
}

void UserManageWindow::addUserProperty() {
    
}

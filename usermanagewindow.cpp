#include "usermanagewindow.h"
#include "ui_usermanagewindow.h"
#include <algorithm>
#include <QTableWidgetItem>
#include "addpropertywindow.h"

UserManageWindow::UserManageWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::UserManageWindow)
{
    ui->setupUi(this);
    refresh();
    connect(ui -> refreshListBtn, &QPushButton::clicked, this, &UserManageWindow::refresh);
    connect(ui -> addProBtn, &QPushButton::clicked, this, &UserManageWindow::addUserProperty);
}

UserManageWindow::~UserManageWindow()
{
    delete ui;
}

void UserManageWindow::afterAction() {
    refresh();
}

void UserManageWindow::refresh() {
    auto up = python_func::UserProcess(database -> asPyObject());
    auto pros_tmp = up.showProperties(true);
    auto pros = python_func::py_matrix_to_vec2(python_func::py_DataFrame_to_matrix(pros_tmp));
    auto columns = python_func::py_list_to_vector(python_func::py_get_DataFrame_columns(pros_tmp));
    ui -> proTable -> setColumnCount(columns.size());
    ui -> proTable -> setRowCount(pros.size());
    for (unsigned i = 0; i < columns.size(); i++) {
        auto item = new QTableWidgetItem(columns.at(i).c_str());
        ui -> proTable -> setHorizontalHeaderItem(i, item);
        ui -> proTable -> setColumnWidth(i, ui -> proTable -> width() / columns.size());
    }
    for (unsigned i = 0; i < pros.size(); i++) {
        for (unsigned j = 0; j < columns.size(); j++) {
            auto item = new QTableWidgetItem(pros.at(i).at(j).c_str());
            ui -> proTable -> setItem(i, j, item);
        }
    }
}

void UserManageWindow::addUserProperty() {
    auto addUserPropertyWindow = new AddPropertyWindow(this);
    addUserPropertyWindow -> show();
}

#include "addpropertywindow.h"
#include "ui_addpropertywindow.h"

AddPropertyWindow::AddPropertyWindow(AfterActionDelegate *delegate, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AddPropertyWindow),
    up(python_func::UserProcess(database -> asPyObject())),
    delegate(delegate)
{
    ui->setupUi(this);
    auto pro_types = python_func::py_list_to_vector(up.showPropertyTypes());
    for (auto pt : pro_types) {
        ui -> proTypeBox -> addItem(pt.c_str());
    }
    ui -> proTypeBox -> setCurrentText("other");
    connect(ui -> confirmBtn, &QPushButton::clicked, this, &AddPropertyWindow::confirm);
}

void AddPropertyWindow::confirm() {
    auto type = ui -> proTypeBox -> currentText().toStdString();
    auto pro = ui -> proNameFiled -> text().toStdString();
    up.addProperty(pro, type);
    close();
    if (delegate) {
        delegate -> afterAction();
    }
}

AddPropertyWindow::~AddPropertyWindow()
{
    delete ui;
}
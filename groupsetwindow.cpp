#include "groupsetwindow.h"
#include "ui_groupsetwindow.h"
#include <QDebug>

GroupSetWindow::GroupSetWindow(GroupSetWindowDelegate *delegate, const std::string &pro, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GroupSetWindow),
    delegate(delegate),
    pro(pro)
{
    ui->setupUi(this);
    connect(ui -> addBtn, &QPushButton::clicked, this, &GroupSetWindow::addItem);
    connect(ui -> deleteBtn, &QPushButton::clicked, this, &GroupSetWindow::deleteItem);
    connect(ui -> emptyBtn, &QPushButton::clicked, this, &GroupSetWindow::empty);
    connect(ui -> confirmBtn, &QPushButton::clicked, this, &GroupSetWindow::confirm);
    
    ui -> groupTable -> setColumnCount(1);
    ui -> groupTable -> setColumnWidth(0, ui -> groupTable -> width());
    ui -> groupTable -> setSelectionBehavior(QAbstractItemView::SelectRows);
}

void GroupSetWindow::addItem() {
    int count = ui -> groupTable -> rowCount();
    ui -> groupTable -> insertRow(count);
}

void GroupSetWindow::deleteItem() {
    auto row = ui -> groupTable -> currentRow();
    ui -> groupTable -> removeRow(row);
}

void GroupSetWindow::empty() {
    for (int i = 0; i < ui -> groupTable -> rowCount(); i++) {
        ui -> groupTable -> removeRow(i);
    }
}

void GroupSetWindow::confirm() {
    std::vector<double> data;
    for (int i = 0; i < ui -> groupTable -> rowCount(); i++) {
        auto item = ui -> groupTable -> item(i, 0);
        data.push_back(item -> text().toDouble());
    }
    if (delegate) {
        qDebug() << pro.c_str();
        delegate -> afterGetData(pro, data);
    }
    close();
}

GroupSetWindow::~GroupSetWindow()
{
    delete ui;
}

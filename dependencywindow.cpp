#include "dependencywindow.h"
#include "ui_dependencywindow.h"
#include "global.hpp"
#include <QTableWidgetItem>
#include <QDebug>

dependencyWindow::dependencyWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::dependencyWindow),
    up(new python_func::UserProcess(database -> asPyObject()))
{
    ui->setupUi(this);
    
    setWindowTitle("相关性分析");
    ui -> debugTestBtn -> setHidden(true);
    
    auto pros = python_func::py_list_to_vector(up -> showProperties());
    ui -> proListTable -> setRowCount(pros.size());
    ui -> proListTable -> setColumnCount(1);
    ui -> proListTable -> setColumnWidth(0, ui -> proListTable -> width());
    for (unsigned i = 0; i < pros.size(); i++) {
        auto item = new QTableWidgetItem(pros.at(i).c_str());
        item -> setCheckState(Qt::Unchecked);
        ui -> proListTable -> setItem(i, 0, item);
    }
    connect(ui -> allProRadio, &QRadioButton::clicked, this, &dependencyWindow::allProSelected);
    connect(ui -> partProRadio, &QRadioButton::clicked, this, &dependencyWindow::partProSelect);
    connect(ui -> createBtn, &QPushButton::clicked, this, &dependencyWindow::create);
    
    connect(ui -> debugTestBtn, &QPushButton::clicked, this, &dependencyWindow::debugTest);
}

void dependencyWindow::create() {
    std::vector<std::string> pros;
    if (ui -> allProRadio -> isChecked()) {
        pros = python_func::py_list_to_vector(up -> showProperties());
    } else if (ui -> partProRadio -> isChecked()) {
        for (int i = 0; i < ui -> proListTable -> rowCount(); i++) {
            auto item = ui -> proListTable -> item(i, 0);
            if (item -> checkState() == Qt::Checked) {
                pros.push_back(item -> text().toStdString());
            }
        }
    }

    auto matrix = up -> relevancyUserPro(pros);
    python_func::py_print(matrix);
    auto row_name = python_func::py_list_to_vector(python_func::py_get_DataFrame_rows(matrix));
    auto column_name = python_func::py_list_to_vector(python_func::py_get_DataFrame_columns(matrix));
    auto mat = python_func::py_matrix_to_vec2(python_func::py_DataFrame_to_matrix(matrix));
    ui -> resultTable -> setRowCount(row_name.size());
    ui -> resultTable -> setColumnCount(column_name.size());
    for (unsigned i = 0; i < row_name.size(); i++) {
        auto v_head = new QTableWidgetItem(row_name.at(i).c_str());
        ui -> resultTable -> setVerticalHeaderItem(i, v_head);
        for (unsigned j = 0; j < column_name.size(); j++) {
            if (i == 0) {
                auto h_head = new QTableWidgetItem(column_name.at(j).c_str());
                ui -> resultTable -> setHorizontalHeaderItem(j, h_head);
            }
            auto item = new QTableWidgetItem(mat.at(i).at(j).c_str());
            ui -> resultTable -> setItem(i, j, item);
        }
    }
}

void dependencyWindow::allProSelected() {
    ui -> proListTable -> setEnabled(false);
}

void dependencyWindow::partProSelect() {
    ui -> proListTable -> setEnabled(true);
}

void dependencyWindow::debugTest() {

}

dependencyWindow::~dependencyWindow()
{
    delete ui;
    delete up;
}

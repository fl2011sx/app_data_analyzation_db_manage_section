#include "singleforcast.h"
#include "ui_singleforcast.h"
#include "singleforecastinputwindow.h"

SingleForcast::SingleForcast(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleForcast),
    up(python_func::UserProcess(database -> asPyObject()))
{
    ui->setupUi(this);
    
    setWindowTitle("单值预测");
    
    ui -> inputTable -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui -> inputTable -> setSelectionBehavior(QAbstractItemView::SelectRows);
    
    ui -> outputTable -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    ui -> outputTable -> setSelectionBehavior(QAbstractItemView::SelectRows);
    
    auto pros = python_func::py_list_to_vector(up.showProperties());
    
    ui -> inputTable -> setRowCount(pros.size());
    ui -> inputTable -> setColumnCount(1);
    ui -> inputTable -> setColumnWidth(0, ui -> inputTable -> width());
    
    ui -> outputTable -> setRowCount(pros.size());
    ui -> outputTable -> setColumnCount(1);
    ui -> outputTable -> setColumnWidth(0, ui -> outputTable -> width());
    
    for (unsigned i = 0; i < pros.size(); i++) {
        auto item = new QTableWidgetItem(pros.at(i).c_str());
        item -> setCheckState(Qt::Unchecked);
        auto item2 = new QTableWidgetItem(pros.at(i).c_str());
        item2 -> setCheckState(Qt::Unchecked);
        ui -> inputTable -> setItem(i, 0, item);
        ui -> outputTable -> setItem(i, 0, item2);
    }
    connect(ui -> inputTable, &QTableWidget::cellChanged, this, &SingleForcast::inputTableChecked);
    connect(ui -> outputTable, &QTableWidget::cellChanged, this, &SingleForcast::outputTableChecked);
    connect(ui -> confirmBtn, &QPushButton::clicked, this, &SingleForcast::confirm);
    connect(ui -> emptyBtn, &QPushButton::clicked, this, &SingleForcast::empty);
}

void SingleForcast::inputTableChecked(int row, int col) {
    auto item = ui -> inputTable -> item(row, col);
    QString content = item -> text();
    auto sel_item = ui -> outputTable -> findItems(content, Qt::MatchExactly);
    if (item -> checkState() == Qt::Checked) {
        sel_item.at(0) -> setCheckState(Qt::Unchecked);
    }
}

void SingleForcast::outputTableChecked(int row, int col) {
    auto item = ui -> outputTable -> item(row, col);
    QString content = item -> text();
    auto sel_item = ui -> inputTable -> findItems(content, Qt::MatchExactly);
    if (item -> checkState() == Qt::Checked) {
        sel_item.at(0) -> setCheckState(Qt::Unchecked);
    }
}

void SingleForcast::confirm() {
    std::vector<std::string> input;
    std::vector<std::string> output;
    for (unsigned i = 0; i < python_func::py_list_to_vector(up.showProperties()).size(); i++) {
        if (ui -> inputTable -> item(i, 0) -> checkState() == Qt::Checked) {
            input.push_back(ui -> inputTable -> item(i, 0) -> text().toStdString());
        }
        if (ui -> outputTable -> item(i, 0) -> checkState() == Qt::Checked) {
            output.push_back(ui -> outputTable -> item(i, 0) -> text().toStdString());
        }
    }
    auto iw = new SingleForecastInputWindow(input, output);
    iw -> show();
}

void SingleForcast::empty() {
    for (unsigned i = 0; i < python_func::py_list_to_vector(up.showProperties()).size(); i++) {
        ui -> inputTable -> item(i, 0) -> setCheckState(Qt::Unchecked);
        ui -> outputTable -> item(i, 0) -> setCheckState(Qt::Unchecked);
    }
}

SingleForcast::~SingleForcast()
{
    delete ui;
}

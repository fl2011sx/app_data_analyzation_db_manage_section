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
    
    auto pros = up.showProperties(true);
    python_func::py_print(pros);
    auto rows = python_func::py_get_DataFrame_rows(pros);
    auto cols = python_func::py_list_to_vector(python_func::py_get_DataFrame_columns(pros));
    auto size = PyList_Size(rows);
    auto col_size = cols.size();
    
    ui -> inputTable -> setRowCount(size);
    ui -> inputTable -> setColumnCount(col_size);
    
    ui -> outputTable -> setRowCount(size);
    ui -> outputTable -> setColumnCount(col_size);
    
    for (int i = 0; i < size; i++) {
        for (unsigned j = 0; j < col_size; j++) {
            auto str = PyString_AsString(python_func::py_DataFrame_item(pros, PyInt_FromLong(i), PyString_FromString(cols.at(j).c_str())));
            auto item = new QTableWidgetItem(str);
            auto item2 = new QTableWidgetItem(str);
            
            if (j == 0) {
                if (cols.at(j) != "innate") {
                    item -> setCheckState(Qt::Unchecked);
                    item2 -> setCheckState(Qt::Unchecked);
                }
            }
            
            ui -> inputTable -> setItem(i, j, item);
            ui -> outputTable -> setItem(i, j, item2);
            
            if (i == 0) {
                auto header = new QTableWidgetItem(cols.at(j).c_str());
                ui -> inputTable -> setHorizontalHeaderItem(j, header);
                ui -> inputTable -> setColumnWidth(j, ui -> inputTable -> width() / col_size);
                auto header2 = new QTableWidgetItem(cols.at(j).c_str());
                ui -> outputTable -> setHorizontalHeaderItem(j, header2);
                ui -> outputTable -> setColumnWidth(j, ui -> inputTable -> width() / col_size);
            }
        }
    }
    connect(ui -> inputTable, &QTableWidget::cellChanged, this, &SingleForcast::inputTableChecked);
    connect(ui -> outputTable, &QTableWidget::cellChanged, this, &SingleForcast::outputTableChecked);
    connect(ui -> confirmBtn, &QPushButton::clicked, this, &SingleForcast::confirm);
    connect(ui -> emptyBtn, &QPushButton::clicked, this, &SingleForcast::empty);
    
    ui -> confirmBtn -> setEnabled(false);
}

void SingleForcast::inputTableChecked(int row, int col) {
    auto item = ui -> inputTable -> item(row, col);
    QString content = item -> text();
    auto sel_item = ui -> outputTable -> findItems(content, Qt::MatchExactly);
    if (item -> checkState() == Qt::Checked) {
        sel_item.at(0) -> setCheckState(Qt::Unchecked);
    }
    if (couldConfirm()) {
        ui -> confirmBtn -> setEnabled(true);
    } else {
        ui -> confirmBtn -> setEnabled(false);
    }
}

void SingleForcast::outputTableChecked(int row, int col) {
    auto item = ui -> outputTable -> item(row, col);
    QString content = item -> text();
    auto sel_item = ui -> inputTable -> findItems(content, Qt::MatchExactly);
    if (item -> checkState() == Qt::Checked) {
        sel_item.at(0) -> setCheckState(Qt::Unchecked);
    }
    
    if (couldConfirm()) {
        ui -> confirmBtn -> setEnabled(true);
    } else {
        ui -> confirmBtn -> setEnabled(false);
    }
}

bool SingleForcast::couldConfirm() {
    bool result = false;
    for (int i = 0; i < ui -> inputTable -> rowCount(); i++) {
        auto item = ui -> inputTable -> item(i, 0);
        if (item -> checkState() == Qt::Checked) {
            result = true;
        }
    }
    if (!result) {return false;}
    for (int i = 0; i < ui -> outputTable -> rowCount(); i++) {
        auto item = ui -> outputTable -> item(i, 0);
        if (item -> checkState() == Qt::Checked) {
            return true;
        }
    }
    return false;
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

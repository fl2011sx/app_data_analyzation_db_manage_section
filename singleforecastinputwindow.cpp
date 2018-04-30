#include "singleforecastinputwindow.h"
#include "ui_singleforecastinputwindow.h"

SingleForecastInputWindow::SingleForecastInputWindow(const std::vector<std::string> &inputPros, const std::vector<std::string> &outputPros, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SingleForecastInputWindow),
    inputPros(inputPros),
    outputPros(outputPros)
{
    ui->setupUi(this);
    
    setWindowTitle("数据输入");
    
    connect(ui -> startBtn, &QPushButton::clicked, this, &SingleForecastInputWindow::start);
    
    ui -> inputTable -> setColumnCount(1);
    ui -> inputTable -> setRowCount(inputPros.size());
    ui -> inputTable -> setColumnWidth(0, ui -> inputTable -> width());
    for (unsigned i = 0; i < inputPros.size(); i++) {
        auto item = new QTableWidgetItem(inputPros.at(i).c_str());
        ui -> inputTable -> setVerticalHeaderItem(i, item);
    }
}

void SingleForecastInputWindow::start() {
    
}

SingleForecastInputWindow::~SingleForecastInputWindow()
{
    delete ui;
}

#include "singleforecastinputwindow.h"
#include "ui_singleforecastinputwindow.h"
#include "BPNeuralNet.hpp"
#include "MainFunctions.hpp"

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
    python_func::UserProcess up(database -> asPyObject());
    std::vector<std::string> pros;
    pros.insert(pros.end(), inputPros.begin(), inputPros.end());
    pros.insert(pros.end(), outputPros.begin(), outputPros.end());
    auto data = up.showUsersByPros(pros);
    auto rows = python_func::py_get_DataFrame_rows(data);
    auto size = PyList_Size(rows);
    
    NeuralNet::BPNeuralNet bp(inputPros.size(), outputPros.size());
//    std::vector<double> input, output;
//    for (unsigned i = 0; i < size; i++) {
//        for (std::vector<std::string>::const_iterator iter = inputPros.begin(); iter != inputPros.end(); iter++) {
//            input.push_back(PyFloat_AsDouble(python_func::py_DataFrame_item(data, PyInt_FromSize_t(i), PyString_FromString(iter -> c_str()))));
//            printf("%lf\t", input.at(i));
//        }
//        printf(" -> ");
//        for (std::vector<std::string>::const_iterator iter = outputPros.begin(); iter != outputPros.end(); iter++) {
//            output.push_back(PyFloat_AsDouble(python_func::py_DataFrame_item(data, PyInt_FromSize_t(i), PyString_FromString(iter -> c_str()))));
//            printf("%lf\t", output.at(i));
//        }
//        printf("\n");
//    }
    
}

SingleForecastInputWindow::~SingleForecastInputWindow()
{
    delete ui;
}

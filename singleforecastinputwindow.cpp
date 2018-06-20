#include "singleforecastinputwindow.h"
#include "ui_singleforecastinputwindow.h"
#include "BPNeuralNet.hpp"
#include "MainFunctions.hpp"
#include "dataforcast.hpp"

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
    python_func::py_print(data);
    auto rows = python_func::py_get_DataFrame_rows(data);
    auto size = PyList_Size(rows);
    
    NeuralNet::BPNeuralNet bp(inputPros.size(), outputPros.size());
    std::vector<double> *inputs = new std::vector<double>[inputPros.size()];
    std::vector<double> *outputs = new std::vector<double>[outputPros.size()];
    for (unsigned i = 0; i < size; i++) {
        unsigned ti = 0;
        for (std::vector<std::string>::const_iterator iter = inputPros.begin(); iter != inputPros.end(); iter++, ti++) {
            double res_dat = PyFloat_AsDouble(python_func::py_DataFrame_item(data, PyInt_FromSize_t(i), PyString_FromString(iter -> c_str())));
            inputs[ti].push_back(res_dat);
            
//            printf("%lf\t", res_dat);
        }
//        printf(" -> ");
        ti = 0;
        for (std::vector<std::string>::const_iterator iter = outputPros.begin(); iter != outputPros.end(); iter++, ti++) {
            double res_dat = PyFloat_AsDouble(python_func::py_DataFrame_item(data, PyInt_FromSize_t(i), PyString_FromString(iter -> c_str())));
            outputs[ti].push_back(res_dat);
//            printf("%lf\t", res_dat);
        }
//        printf("\n-----------------\n");
    }
    auto *input_sets = new dataProcess::ConinuousDataForcastArgSet[inputPros.size()];
    auto *output_sets = new dataProcess::ConinuousDataForcastArgSet[outputPros.size()];
    for (unsigned i = 0; i < inputPros.size(); i++) {
        input_sets[i] = dataProcess::ConinuousDataForcast::processData(inputs[i]);
    }
    for (unsigned i = 0; i < outputPros.size(); i++) {
        output_sets[i] = dataProcess::ConinuousDataForcast::processData(outputs[i]);
    }
    for (int i = 0; i < size; i++) {
        bp.addIOData(inputs[i], outputs[i]);
    }
    bp.train(1000000);
    
    ui -> outputTable -> setRowCount(outputPros.size());
    ui -> outputTable -> setColumnCount(1);
    int i = 0;
    for (std::vector<std::string>::const_iterator iter = outputPros.begin(); iter != outputPros.end(); iter++, i++) {
        auto item_h = new QTableWidgetItem(iter -> c_str());
        ui -> outputTable -> setVerticalHeaderItem(i, item_h);
    }
    
    std::vector<double> fore_input;
    for (unsigned i = 0; i < inputPros.size(); i++) {
        fore_input.push_back(ui -> inputTable -> item(i, 0) -> text().toDouble());
    }
    for (unsigned i = 0; i < fore_input.size(); i++) {
        fore_input.at(i) = dataProcess::ConinuousDataForcast::pre_processData(fore_input.at(i), input_sets[i]);
    }
    std::vector<double> fore_output = bp.forecastData(fore_input);
    for (unsigned i = 0; i < fore_output.size(); i++) {
        fore_output.at(i) = dataProcess::ConinuousDataForcast::aft_processData(fore_output.at(i), output_sets[i]);
        
        auto item = new QTableWidgetItem(std::to_string(fore_output.at(i)).c_str());
        ui -> outputTable -> setItem(i, 0, item);
    }
    delete [] inputs;
    delete [] outputs;
    delete [] input_sets;
    delete [] output_sets;
}

SingleForecastInputWindow::~SingleForecastInputWindow()
{
    delete ui;
}

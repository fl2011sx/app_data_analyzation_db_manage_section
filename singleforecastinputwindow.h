#ifndef SINGLEFORECASTINPUTWINDOW_H
#define SINGLEFORECASTINPUTWINDOW_H

#include <QWidget>
#include <vector>
#include "global.hpp"
#include "MainFunctions.hpp"
#include "dataforcast.hpp"

namespace Ui {
class SingleForecastInputWindow;
}

class SingleForecastInputWindow : public QWidget
{
    Q_OBJECT

public:
    explicit SingleForecastInputWindow(const std::vector<std::string> &inputPros, const std::vector<std::string> &outputPros, QWidget *parent = 0);
    ~SingleForecastInputWindow();

private:
    Ui::SingleForecastInputWindow *ui;
    std::vector<std::string> inputPros;
    std::vector<std::string> outputPros;
//    dataProcess::ConinuousDataForcastArgSet *input_sets, output_sets;
    
private slots:
    void start();
};

#endif // SINGLEFORECASTINPUTWINDOW_H

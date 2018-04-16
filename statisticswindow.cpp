#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "MainFunctions.hpp"
#include <vector>
#include "waitingwindow.h"
#include "waitingthread.h"

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
    
    connect(ui -> pushButton, SIGNAL(clicked()), this, SLOT(debugTest()));
}

void StatisticsWindow::run() {
    double test[] = {2.8, 3.6, 4.7, 8.8, 11};
    std::vector<double> ve(test, test + 5);
    python_func::drawBarChart(ve, "showGraph.png");
}

void StatisticsWindow::after_running() {
    QImage img;
    img.load("showGraph.png");
    auto img_scale = img.scaled(ui -> image -> width(), ui -> image -> height(), Qt::KeepAspectRatio);
    ui -> image -> setPixmap(QPixmap::fromImage(img_scale));
}

void StatisticsWindow::debugTest() {
//    auto ww = new WaitingWindow;
//    ww -> show();
    run();
    after_running();
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

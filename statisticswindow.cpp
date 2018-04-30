#include "statisticswindow.h"
#include "ui_statisticswindow.h"
#include "MainFunctions.hpp"
#include <vector>
#include "waitingwindow.h"
#include "waitingthread.h"
#include <QDebug>

StatisticsWindow::StatisticsWindow(QWidget *parent) :
    QWidget(parent),
ui(new Ui::StatisticsWindow)
{
    ui->setupUi(this);
    
    setWindowTitle("分布统计");
    
    ui -> aeraBtn -> setEnabled(false);
    ui -> singlePointBtn -> setEnabled(false);
    
    python_func::UserProcess up(database -> asPyObject());
    auto pros = python_func::py_list_to_vector(up.showProperties());
    ui -> proList -> setRowCount(pros.size());
    ui -> proList -> setColumnCount(1);
    ui -> proList -> setColumnWidth(0, ui -> proList -> width());
    ui -> proList -> setEditTriggers(QAbstractItemView::NoEditTriggers);
    for (unsigned i = 0; i < pros.size(); i++) {
        auto item = new QTableWidgetItem(pros.at(i).c_str());
        ui -> proList -> setItem(i, 0, item);
    }
    connect(ui -> proList, SIGNAL(itemPressed(QTableWidgetItem *)), this, SLOT(proListItemSelected(QTableWidgetItem *)));
    connect(ui -> proList, SIGNAL(itemSelectionChanged()), this, SLOT(proListItemChanged()));
    
    connect(ui -> singlePointBtn, SIGNAL(clicked()), this, SLOT(singleStatistic()));
    connect(ui -> aeraBtn, SIGNAL(clicked()), this, SLOT(aeraStatistic()));
    
    connect(ui -> pushButton, SIGNAL(clicked()), this, SLOT(debugTest()));
}

void StatisticsWindow::singleStatistic() {
    auto select_pro = ui -> proList -> selectedItems().at(0) -> text().toStdString();
    python_func::UserProcess up(database -> asPyObject());
    auto result = up.distributionUserPro(select_pro, true);
    python_func::drawBarChart(result, "singleSta.png");
    QImage img;
    img.load("singleSta.png");
    auto img_scale = img.scaled(ui -> image -> width(), ui -> image -> height(), Qt::KeepAspectRatio);
    ui -> image -> setPixmap(QPixmap::fromImage(img_scale));
}

void StatisticsWindow::aeraStatistic() {
    auto groupSetWindow = new GroupSetWindow(this, ui -> proList -> selectedItems().at(0) -> text().toStdString());
    groupSetWindow -> show();
}

void StatisticsWindow::afterGetData(const std::string &pro, std::vector<double> group) {
    for (auto ele : group) {
        qDebug() << ele;
    }
    python_func::UserProcess up(database -> asPyObject());
    auto res = up.distributionUserPro(pro, false, &group);
//    python_func::py_print(res);
    python_func::drawBarChart(res, "showGraph.png");
    after_running();
}

void StatisticsWindow::proListItemSelected(QTableWidgetItem *) {
    if (ui -> proList -> selectedItems().size() > 1) {return;}
    ui -> aeraBtn -> setEnabled(true);
    ui -> singlePointBtn -> setEnabled(true);
}

void StatisticsWindow::proListItemChanged() {
    if (ui -> proList -> selectedItems().size() == 0 || ui -> proList -> selectedItems().size() > 1) {
        ui -> aeraBtn -> setEnabled(false);
        ui -> singlePointBtn -> setEnabled(false);
    }
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
    run();
    
    after_running();
}

StatisticsWindow::~StatisticsWindow()
{
    delete ui;
}

#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include "global.hpp"
#include <QTableWidgetItem>

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget
{
    Q_OBJECT

public:
    explicit StatisticsWindow(QWidget *parent = 0);
    ~StatisticsWindow();
    void run();
    
public slots:
    void after_running();

private:
    Ui::StatisticsWindow *ui;
    
private slots:
    void debugTest();
    void proListItemSelected(QTableWidgetItem *item);
    void proListItemChanged();
    void singleStatistic();
    void aeraStatistic();
};

#endif // STATISTICSWINDOW_H

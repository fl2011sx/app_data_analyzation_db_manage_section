#ifndef STATISTICSWINDOW_H
#define STATISTICSWINDOW_H

#include <QWidget>
#include "global.hpp"
#include "waitingthread.h"

namespace Ui {
class StatisticsWindow;
}

class StatisticsWindow : public QWidget, public WaitingThreadDelegate
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
};

#endif // STATISTICSWINDOW_H

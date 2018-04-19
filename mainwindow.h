#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QWidget>
#include "global.hpp"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    Ui::MainWindow *ui;
    
signals:
    void test(int);
private slots:
    void showUser();
    void showUserManageWindow();
    void showStatisticsWindow();
    void showDependencyWindow();
    
    void debugTest();
};

#endif // MAINWINDOW_H

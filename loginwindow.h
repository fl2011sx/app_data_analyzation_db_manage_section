#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QWidget>
#include "global.hpp"
#include "mainwindow.h"

namespace Ui {
class LoginWindow;
}

class LoginWindow : public QWidget
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = 0);
    ~LoginWindow();

private:
    Ui::LoginWindow *ui;
    MainWindow *mainWindow;
    
private slots:
    void connectDatabase();
};

#endif // LOGINWINDOW_H

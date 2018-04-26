#ifndef USERMANAGEWINDOW_H
#define USERMANAGEWINDOW_H

#include <QWidget>
#include "global.hpp"
#include "MainFunctions.hpp"
#include "afteractiondelegate.h"

namespace Ui {
class UserManageWindow;
}

class UserManageWindow : public QWidget, public AfterActionDelegate
{
    Q_OBJECT

public:
    explicit UserManageWindow(QWidget *parent = 0);
    ~UserManageWindow();
    void afterAction();

private:
    Ui::UserManageWindow *ui;
    
private slots:
    void refresh();
    void addUserProperty();
};

#endif // USERMANAGEWINDOW_H

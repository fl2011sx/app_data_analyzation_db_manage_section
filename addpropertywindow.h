#ifndef ADDPROPERTYWINDOW_H
#define ADDPROPERTYWINDOW_H

#include <QWidget>
#include "global.hpp"
#include "MainFunctions.hpp"
#include "afteractiondelegate.h"

namespace Ui {
class AddPropertyWindow;
}

class AddPropertyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit AddPropertyWindow(AfterActionDelegate *delegate = nullptr, QWidget *parent = 0);
    ~AddPropertyWindow();

private:
    Ui::AddPropertyWindow *ui;
    python_func::UserProcess up;
    AfterActionDelegate *delegate;
    
private slots:
    void confirm();
};

#endif // ADDPROPERTYWINDOW_H

#ifndef DEPENDENCYWINDOW_H
#define DEPENDENCYWINDOW_H

#include <QWidget>
#include "MainFunctions.hpp"

namespace Ui {
class dependencyWindow;
}

class dependencyWindow : public QWidget
{
    Q_OBJECT

public:
    explicit dependencyWindow(QWidget *parent = 0);
    ~dependencyWindow();

private:
    Ui::dependencyWindow *ui;
    python_func::UserProcess *up;
    
private slots:
    void debugTest();
    void allProSelected();
    void partProSelect();
    void create();
};

#endif // DEPENDENCYWINDOW_H

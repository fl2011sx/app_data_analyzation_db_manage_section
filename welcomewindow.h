#ifndef WELCOMEWINDOW_H
#define WELCOMEWINDOW_H

#include <QWidget>
#include "loginwindow.h"

namespace Ui {
class WelcomeWindow;
}

class WelcomeWindow : public QWidget
{
    Q_OBJECT

public:
    explicit WelcomeWindow(QWidget *parent = 0);
    ~WelcomeWindow();

private:
    Ui::WelcomeWindow *ui;
    LoginWindow *loginWindow;
    
private slots:
    void openSystem();
};

#endif // WELCOMEWINDOW_H

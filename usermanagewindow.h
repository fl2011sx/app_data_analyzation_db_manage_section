#ifndef USERMANAGEWINDOW_H
#define USERMANAGEWINDOW_H

#include <QWidget>

namespace Ui {
class UserManageWindow;
}

class UserManageWindow : public QWidget
{
    Q_OBJECT

public:
    explicit UserManageWindow(QWidget *parent = 0);
    ~UserManageWindow();

private:
    Ui::UserManageWindow *ui;
    
private slots:
    void refresh();
    void addUserProperty();
};

#endif // USERMANAGEWINDOW_H

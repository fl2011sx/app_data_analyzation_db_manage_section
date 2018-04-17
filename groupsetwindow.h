#ifndef GROUPSETWINDOW_H
#define GROUPSETWINDOW_H

#include <QWidget>
#include <vector>

class GroupSetWindowDelegate {
public:
    virtual void afterGetData(std::vector<double> &group) = 0;
};

namespace Ui {
class GroupSetWindow;
}

class GroupSetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GroupSetWindow(GroupSetWindowDelegate *delegate, QWidget *parent = 0);
    ~GroupSetWindow();

private:
    Ui::GroupSetWindow *ui;
    GroupSetWindowDelegate *delegate;
    
public slots:
    void addItem();
    void deleteItem();
    void empty();
    void confirm();
};

#endif // GROUPSETWINDOW_H

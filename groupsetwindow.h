#ifndef GROUPSETWINDOW_H
#define GROUPSETWINDOW_H

#include <QWidget>
#include <vector>
#include <string>

class GroupSetWindowDelegate {
public:
    virtual void afterGetData(const std::string &pro, std::vector<double> group) = 0;
};

namespace Ui {
class GroupSetWindow;
}

class GroupSetWindow : public QWidget
{
    Q_OBJECT

public:
    explicit GroupSetWindow(GroupSetWindowDelegate *delegate, const std::string &pro, QWidget *parent = 0);
    ~GroupSetWindow();

private:
    Ui::GroupSetWindow *ui;
    GroupSetWindowDelegate *delegate;
    std::string pro;
    
public slots:
    void addItem();
    void deleteItem();
    void empty();
    void confirm();
};

#endif // GROUPSETWINDOW_H

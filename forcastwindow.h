#ifndef FORCASTWINDOW_H
#define FORCASTWINDOW_H

#include <QWidget>

namespace Ui {
class forcastWindow;
}

class forcastWindow : public QWidget
{
    Q_OBJECT

public:
    explicit forcastWindow(QWidget *parent = 0);
    ~forcastWindow();

private:
    Ui::forcastWindow *ui;
    
private slots:
    void showSingleForcast();
};

#endif // FORCASTWINDOW_H

#ifndef SINGLEFORCAST_H
#define SINGLEFORCAST_H

#include <QWidget>
#include "global.hpp"
#include "MainFunctions.hpp"

namespace Ui {
class SingleForcast;
}

class SingleForcast : public QWidget
{
    Q_OBJECT

public:
    explicit SingleForcast(QWidget *parent = 0);
    ~SingleForcast();

private:
    Ui::SingleForcast *ui;
    python_func::UserProcess up;
    bool couldConfirm();
    
private slots:
    void inputTableChecked(int row, int col);
    void outputTableChecked(int row, int col);
    void confirm();
    void empty();
};

#endif // SINGLEFORCAST_H

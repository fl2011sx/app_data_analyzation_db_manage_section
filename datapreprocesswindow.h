#ifndef DATAPREPROCESSWINDOW_H
#define DATAPREPROCESSWINDOW_H

#include <QWidget>

namespace Ui {
class DataPreprocessWindow;
}

class DataPreprocessWindow : public QWidget
{
    Q_OBJECT

public:
    explicit DataPreprocessWindow(QWidget *parent = 0);
    ~DataPreprocessWindow();

private:
    Ui::DataPreprocessWindow *ui;
};

#endif // DATAPREPROCESSWINDOW_H

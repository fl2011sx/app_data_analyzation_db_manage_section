/********************************************************************************
** Form generated from reading UI file 'singleforecastinputwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEFORECASTINPUTWINDOW_H
#define UI_SINGLEFORECASTINPUTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleForecastInputWindow
{
public:
    QTableWidget *inputTable;
    QPushButton *startBtn;
    QTableWidget *outputTable;

    void setupUi(QWidget *SingleForecastInputWindow)
    {
        if (SingleForecastInputWindow->objectName().isEmpty())
            SingleForecastInputWindow->setObjectName(QStringLiteral("SingleForecastInputWindow"));
        SingleForecastInputWindow->resize(476, 367);
        inputTable = new QTableWidget(SingleForecastInputWindow);
        inputTable->setObjectName(QStringLiteral("inputTable"));
        inputTable->setGeometry(QRect(10, 10, 256, 341));
        inputTable->horizontalHeader()->setVisible(false);
        startBtn = new QPushButton(SingleForecastInputWindow);
        startBtn->setObjectName(QStringLiteral("startBtn"));
        startBtn->setGeometry(QRect(360, 330, 113, 32));
        outputTable = new QTableWidget(SingleForecastInputWindow);
        outputTable->setObjectName(QStringLiteral("outputTable"));
        outputTable->setGeometry(QRect(280, 10, 191, 311));
        outputTable->horizontalHeader()->setVisible(false);
        outputTable->verticalHeader()->setVisible(false);

        retranslateUi(SingleForecastInputWindow);

        QMetaObject::connectSlotsByName(SingleForecastInputWindow);
    } // setupUi

    void retranslateUi(QWidget *SingleForecastInputWindow)
    {
        SingleForecastInputWindow->setWindowTitle(QApplication::translate("SingleForecastInputWindow", "Form", 0));
        startBtn->setText(QApplication::translate("SingleForecastInputWindow", "\345\274\200\345\247\213\351\242\204\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class SingleForecastInputWindow: public Ui_SingleForecastInputWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEFORECASTINPUTWINDOW_H

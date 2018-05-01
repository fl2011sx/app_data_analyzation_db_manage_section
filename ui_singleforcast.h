/********************************************************************************
** Form generated from reading UI file 'singleforcast.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SINGLEFORCAST_H
#define UI_SINGLEFORCAST_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SingleForcast
{
public:
    QTableWidget *outputTable;
    QTableWidget *inputTable;
    QLabel *label;
    QLabel *label_2;
    QPushButton *confirmBtn;
    QPushButton *emptyBtn;

    void setupUi(QWidget *SingleForcast)
    {
        if (SingleForcast->objectName().isEmpty())
            SingleForcast->setObjectName(QStringLiteral("SingleForcast"));
        SingleForcast->resize(480, 480);
        outputTable = new QTableWidget(SingleForcast);
        outputTable->setObjectName(QStringLiteral("outputTable"));
        outputTable->setGeometry(QRect(10, 40, 351, 201));
        outputTable->horizontalHeader()->setVisible(true);
        outputTable->verticalHeader()->setVisible(true);
        inputTable = new QTableWidget(SingleForcast);
        inputTable->setObjectName(QStringLiteral("inputTable"));
        inputTable->setGeometry(QRect(10, 270, 351, 201));
        inputTable->horizontalHeader()->setVisible(true);
        inputTable->verticalHeader()->setVisible(true);
        label = new QLabel(SingleForcast);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 20, 101, 16));
        label_2 = new QLabel(SingleForcast);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 250, 101, 16));
        confirmBtn = new QPushButton(SingleForcast);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(360, 440, 113, 32));
        emptyBtn = new QPushButton(SingleForcast);
        emptyBtn->setObjectName(QStringLiteral("emptyBtn"));
        emptyBtn->setGeometry(QRect(360, 40, 113, 32));

        retranslateUi(SingleForcast);

        QMetaObject::connectSlotsByName(SingleForcast);
    } // setupUi

    void retranslateUi(QWidget *SingleForcast)
    {
        SingleForcast->setWindowTitle(QApplication::translate("SingleForcast", "Form", 0));
        label->setText(QApplication::translate("SingleForcast", "\351\234\200\350\246\201\351\242\204\346\265\213\347\232\204\345\261\236\346\200\247", 0));
        label_2->setText(QApplication::translate("SingleForcast", "\351\242\204\346\265\213\344\276\235\346\215\256\347\232\204\345\261\236\346\200\247", 0));
        confirmBtn->setText(QApplication::translate("SingleForcast", "\347\241\256\345\256\232", 0));
        emptyBtn->setText(QApplication::translate("SingleForcast", "\346\270\205\347\251\272", 0));
    } // retranslateUi

};

namespace Ui {
    class SingleForcast: public Ui_SingleForcast {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SINGLEFORCAST_H

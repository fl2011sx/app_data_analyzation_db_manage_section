/********************************************************************************
** Form generated from reading UI file 'forcastwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORCASTWINDOW_H
#define UI_FORCASTWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_forcastWindow
{
public:
    QPushButton *refreshBtn;
    QTableWidget *proTable;
    QPushButton *singleForcastBtn;
    QPushButton *colonyBtn;
    QPushButton *debugTest;

    void setupUi(QWidget *forcastWindow)
    {
        if (forcastWindow->objectName().isEmpty())
            forcastWindow->setObjectName(QStringLiteral("forcastWindow"));
        forcastWindow->resize(454, 343);
        refreshBtn = new QPushButton(forcastWindow);
        refreshBtn->setObjectName(QStringLiteral("refreshBtn"));
        refreshBtn->setGeometry(QRect(10, 10, 113, 32));
        proTable = new QTableWidget(forcastWindow);
        proTable->setObjectName(QStringLiteral("proTable"));
        proTable->setGeometry(QRect(140, 0, 321, 351));
        singleForcastBtn = new QPushButton(forcastWindow);
        singleForcastBtn->setObjectName(QStringLiteral("singleForcastBtn"));
        singleForcastBtn->setGeometry(QRect(10, 90, 113, 32));
        colonyBtn = new QPushButton(forcastWindow);
        colonyBtn->setObjectName(QStringLiteral("colonyBtn"));
        colonyBtn->setGeometry(QRect(10, 120, 113, 32));
        debugTest = new QPushButton(forcastWindow);
        debugTest->setObjectName(QStringLiteral("debugTest"));
        debugTest->setGeometry(QRect(10, 300, 113, 32));

        retranslateUi(forcastWindow);

        QMetaObject::connectSlotsByName(forcastWindow);
    } // setupUi

    void retranslateUi(QWidget *forcastWindow)
    {
        forcastWindow->setWindowTitle(QApplication::translate("forcastWindow", "Form", 0));
        refreshBtn->setText(QApplication::translate("forcastWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", 0));
        singleForcastBtn->setText(QApplication::translate("forcastWindow", "\345\215\225\345\200\274\351\242\204\346\265\213", 0));
        colonyBtn->setText(QApplication::translate("forcastWindow", "\351\233\206\347\276\244\345\210\206\346\236\220", 0));
        debugTest->setText(QApplication::translate("forcastWindow", "debugTest", 0));
    } // retranslateUi

};

namespace Ui {
    class forcastWindow: public Ui_forcastWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORCASTWINDOW_H

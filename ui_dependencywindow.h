/********************************************************************************
** Form generated from reading UI file 'dependencywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DEPENDENCYWINDOW_H
#define UI_DEPENDENCYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QRadioButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_dependencyWindow
{
public:
    QPushButton *debugTestBtn;
    QPushButton *createBtn;
    QRadioButton *allProRadio;
    QRadioButton *partProRadio;
    QTableWidget *proListTable;
    QTableWidget *resultTable;

    void setupUi(QWidget *dependencyWindow)
    {
        if (dependencyWindow->objectName().isEmpty())
            dependencyWindow->setObjectName(QStringLiteral("dependencyWindow"));
        dependencyWindow->resize(544, 423);
        debugTestBtn = new QPushButton(dependencyWindow);
        debugTestBtn->setObjectName(QStringLiteral("debugTestBtn"));
        debugTestBtn->setGeometry(QRect(20, 380, 113, 32));
        createBtn = new QPushButton(dependencyWindow);
        createBtn->setObjectName(QStringLiteral("createBtn"));
        createBtn->setGeometry(QRect(20, 300, 113, 32));
        allProRadio = new QRadioButton(dependencyWindow);
        allProRadio->setObjectName(QStringLiteral("allProRadio"));
        allProRadio->setGeometry(QRect(20, 30, 100, 20));
        allProRadio->setChecked(true);
        partProRadio = new QRadioButton(dependencyWindow);
        partProRadio->setObjectName(QStringLiteral("partProRadio"));
        partProRadio->setGeometry(QRect(20, 60, 100, 20));
        proListTable = new QTableWidget(dependencyWindow);
        proListTable->setObjectName(QStringLiteral("proListTable"));
        proListTable->setEnabled(false);
        proListTable->setGeometry(QRect(10, 90, 131, 192));
        proListTable->horizontalHeader()->setVisible(false);
        proListTable->verticalHeader()->setVisible(false);
        resultTable = new QTableWidget(dependencyWindow);
        resultTable->setObjectName(QStringLiteral("resultTable"));
        resultTable->setGeometry(QRect(160, 20, 371, 391));

        retranslateUi(dependencyWindow);

        QMetaObject::connectSlotsByName(dependencyWindow);
    } // setupUi

    void retranslateUi(QWidget *dependencyWindow)
    {
        dependencyWindow->setWindowTitle(QApplication::translate("dependencyWindow", "Form", 0));
        debugTestBtn->setText(QApplication::translate("dependencyWindow", "debugTest", 0));
        createBtn->setText(QApplication::translate("dependencyWindow", "\347\224\237\346\210\220\347\233\270\345\205\263\346\200\247\347\237\251\351\230\265", 0));
        allProRadio->setText(QApplication::translate("dependencyWindow", "\345\210\206\346\236\220\346\211\200\346\234\211\345\261\236\346\200\247", 0));
        partProRadio->setText(QApplication::translate("dependencyWindow", "\345\210\206\346\236\220\351\203\250\345\210\206\346\225\260\346\215\256", 0));
    } // retranslateUi

};

namespace Ui {
    class dependencyWindow: public Ui_dependencyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DEPENDENCYWINDOW_H

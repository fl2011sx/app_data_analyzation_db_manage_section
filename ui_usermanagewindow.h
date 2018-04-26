/********************************************************************************
** Form generated from reading UI file 'usermanagewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_USERMANAGEWINDOW_H
#define UI_USERMANAGEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManageWindow
{
public:
    QPushButton *refreshListBtn;
    QPushButton *addProBtn;
    QTableWidget *proTable;

    void setupUi(QWidget *UserManageWindow)
    {
        if (UserManageWindow->objectName().isEmpty())
            UserManageWindow->setObjectName(QStringLiteral("UserManageWindow"));
        UserManageWindow->resize(492, 382);
        refreshListBtn = new QPushButton(UserManageWindow);
        refreshListBtn->setObjectName(QStringLiteral("refreshListBtn"));
        refreshListBtn->setGeometry(QRect(10, 50, 113, 32));
        addProBtn = new QPushButton(UserManageWindow);
        addProBtn->setObjectName(QStringLiteral("addProBtn"));
        addProBtn->setGeometry(QRect(10, 90, 113, 32));
        proTable = new QTableWidget(UserManageWindow);
        proTable->setObjectName(QStringLiteral("proTable"));
        proTable->setGeometry(QRect(150, 0, 351, 391));

        retranslateUi(UserManageWindow);

        QMetaObject::connectSlotsByName(UserManageWindow);
    } // setupUi

    void retranslateUi(QWidget *UserManageWindow)
    {
        UserManageWindow->setWindowTitle(QApplication::translate("UserManageWindow", "Form", 0));
        refreshListBtn->setText(QApplication::translate("UserManageWindow", "\345\210\267\346\226\260\345\210\227\350\241\250", 0));
        addProBtn->setText(QApplication::translate("UserManageWindow", "\346\267\273\345\212\240\345\261\236\346\200\247", 0));
    } // retranslateUi

};

namespace Ui {
    class UserManageWindow: public Ui_UserManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEWINDOW_H

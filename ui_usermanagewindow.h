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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_UserManageWindow
{
public:

    void setupUi(QWidget *UserManageWindow)
    {
        if (UserManageWindow->objectName().isEmpty())
            UserManageWindow->setObjectName(QStringLiteral("UserManageWindow"));
        UserManageWindow->resize(400, 300);

        retranslateUi(UserManageWindow);

        QMetaObject::connectSlotsByName(UserManageWindow);
    } // setupUi

    void retranslateUi(QWidget *UserManageWindow)
    {
        UserManageWindow->setWindowTitle(QApplication::translate("UserManageWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class UserManageWindow: public Ui_UserManageWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_USERMANAGEWINDOW_H

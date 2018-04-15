/********************************************************************************
** Form generated from reading UI file 'loginwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOGINWINDOW_H
#define UI_LOGINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_LoginWindow
{
public:
    QPushButton *connectBtn;
    QLineEdit *pswFiled;
    QLineEdit *usernameFile;
    QLabel *label;
    QLabel *label_2;
    QLineEdit *addressFiled;
    QLabel *label_3;

    void setupUi(QWidget *LoginWindow)
    {
        if (LoginWindow->objectName().isEmpty())
            LoginWindow->setObjectName(QStringLiteral("LoginWindow"));
        LoginWindow->resize(400, 300);
        connectBtn = new QPushButton(LoginWindow);
        connectBtn->setObjectName(QStringLiteral("connectBtn"));
        connectBtn->setGeometry(QRect(140, 190, 113, 32));
        pswFiled = new QLineEdit(LoginWindow);
        pswFiled->setObjectName(QStringLiteral("pswFiled"));
        pswFiled->setGeometry(QRect(130, 120, 113, 21));
        usernameFile = new QLineEdit(LoginWindow);
        usernameFile->setObjectName(QStringLiteral("usernameFile"));
        usernameFile->setGeometry(QRect(130, 80, 113, 21));
        label = new QLabel(LoginWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 80, 60, 16));
        label_2 = new QLabel(LoginWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 120, 60, 16));
        addressFiled = new QLineEdit(LoginWindow);
        addressFiled->setObjectName(QStringLiteral("addressFiled"));
        addressFiled->setGeometry(QRect(130, 40, 113, 21));
        label_3 = new QLabel(LoginWindow);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(50, 40, 71, 16));

        retranslateUi(LoginWindow);

        QMetaObject::connectSlotsByName(LoginWindow);
    } // setupUi

    void retranslateUi(QWidget *LoginWindow)
    {
        LoginWindow->setWindowTitle(QApplication::translate("LoginWindow", "Form", 0));
        connectBtn->setText(QApplication::translate("LoginWindow", "\350\277\236\346\216\245", 0));
        pswFiled->setText(QString());
        usernameFile->setText(QApplication::translate("LoginWindow", "root", 0));
        label->setText(QApplication::translate("LoginWindow", "\347\231\273\345\275\225\350\272\253\344\273\275", 0));
        label_2->setText(QApplication::translate("LoginWindow", "\345\257\206\347\240\201", 0));
        addressFiled->setText(QApplication::translate("LoginWindow", "127.0.0.1", 0));
        label_3->setText(QApplication::translate("LoginWindow", "\346\225\260\346\215\256\345\272\223\345\234\260\345\235\200", 0));
    } // retranslateUi

};

namespace Ui {
    class LoginWindow: public Ui_LoginWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOGINWINDOW_H

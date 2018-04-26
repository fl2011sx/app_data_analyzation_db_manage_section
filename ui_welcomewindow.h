/********************************************************************************
** Form generated from reading UI file 'welcomewindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WELCOMEWINDOW_H
#define UI_WELCOMEWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_WelcomeWindow
{
public:
    QPushButton *openSystemBtn;
    QPushButton *setupBtn;

    void setupUi(QWidget *WelcomeWindow)
    {
        if (WelcomeWindow->objectName().isEmpty())
            WelcomeWindow->setObjectName(QStringLiteral("WelcomeWindow"));
        WelcomeWindow->resize(400, 300);
        openSystemBtn = new QPushButton(WelcomeWindow);
        openSystemBtn->setObjectName(QStringLiteral("openSystemBtn"));
        openSystemBtn->setGeometry(QRect(130, 170, 113, 32));
        setupBtn = new QPushButton(WelcomeWindow);
        setupBtn->setObjectName(QStringLiteral("setupBtn"));
        setupBtn->setGeometry(QRect(280, 260, 113, 32));

        retranslateUi(WelcomeWindow);

        QMetaObject::connectSlotsByName(WelcomeWindow);
    } // setupUi

    void retranslateUi(QWidget *WelcomeWindow)
    {
        WelcomeWindow->setWindowTitle(QApplication::translate("WelcomeWindow", "Form", 0));
        openSystemBtn->setText(QApplication::translate("WelcomeWindow", "\345\274\200\345\220\257\347\263\273\347\273\237", 0));
        setupBtn->setText(QApplication::translate("WelcomeWindow", "\351\203\250\347\275\262\347\263\273\347\273\237", 0));
    } // retranslateUi

};

namespace Ui {
    class WelcomeWindow: public Ui_WelcomeWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WELCOMEWINDOW_H

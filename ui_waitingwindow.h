/********************************************************************************
** Form generated from reading UI file 'waitingwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WAITINGWINDOW_H
#define UI_WAITINGWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>

QT_BEGIN_NAMESPACE

class Ui_WaitingWindow
{
public:
    QLabel *label;

    void setupUi(QDialog *WaitingWindow)
    {
        if (WaitingWindow->objectName().isEmpty())
            WaitingWindow->setObjectName(QStringLiteral("WaitingWindow"));
        WaitingWindow->resize(490, 321);
        label = new QLabel(WaitingWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(40, 90, 411, 141));
        label->setTextFormat(Qt::AutoText);
        label->setIndent(-1);

        retranslateUi(WaitingWindow);

        QMetaObject::connectSlotsByName(WaitingWindow);
    } // setupUi

    void retranslateUi(QDialog *WaitingWindow)
    {
        WaitingWindow->setWindowTitle(QApplication::translate("WaitingWindow", "Dialog", 0));
        label->setText(QApplication::translate("WaitingWindow", "\346\255\243\345\234\250\345\244\204\347\220\206\357\274\214\350\257\267\347\250\215\345\220\216\342\200\246\342\200\246", 0));
    } // retranslateUi

};

namespace Ui {
    class WaitingWindow: public Ui_WaitingWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WAITINGWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'statisticswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_STATISTICSWINDOW_H
#define UI_STATISTICSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_StatisticsWindow
{
public:
    QPushButton *pushButton;
    QLabel *image;

    void setupUi(QWidget *StatisticsWindow)
    {
        if (StatisticsWindow->objectName().isEmpty())
            StatisticsWindow->setObjectName(QStringLiteral("StatisticsWindow"));
        StatisticsWindow->resize(809, 647);
        pushButton = new QPushButton(StatisticsWindow);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(10, 150, 113, 32));
        image = new QLabel(StatisticsWindow);
        image->setObjectName(QStringLiteral("image"));
        image->setGeometry(QRect(170, 10, 631, 631));

        retranslateUi(StatisticsWindow);

        QMetaObject::connectSlotsByName(StatisticsWindow);
    } // setupUi

    void retranslateUi(QWidget *StatisticsWindow)
    {
        StatisticsWindow->setWindowTitle(QApplication::translate("StatisticsWindow", "Form", 0));
        pushButton->setText(QApplication::translate("StatisticsWindow", "DebugTest", 0));
        image->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class StatisticsWindow: public Ui_StatisticsWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_STATISTICSWINDOW_H

/********************************************************************************
** Form generated from reading UI file 'addpropertywindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ADDPROPERTYWINDOW_H
#define UI_ADDPROPERTYWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_AddPropertyWindow
{
public:
    QLineEdit *proNameFiled;
    QLabel *label;
    QComboBox *proTypeBox;
    QLabel *label_2;
    QPushButton *confirmBtn;

    void setupUi(QWidget *AddPropertyWindow)
    {
        if (AddPropertyWindow->objectName().isEmpty())
            AddPropertyWindow->setObjectName(QStringLiteral("AddPropertyWindow"));
        AddPropertyWindow->resize(400, 300);
        proNameFiled = new QLineEdit(AddPropertyWindow);
        proNameFiled->setObjectName(QStringLiteral("proNameFiled"));
        proNameFiled->setGeometry(QRect(110, 70, 171, 21));
        label = new QLabel(AddPropertyWindow);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(50, 70, 60, 16));
        proTypeBox = new QComboBox(AddPropertyWindow);
        proTypeBox->setObjectName(QStringLiteral("proTypeBox"));
        proTypeBox->setGeometry(QRect(110, 110, 171, 26));
        label_2 = new QLabel(AddPropertyWindow);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(50, 110, 60, 16));
        confirmBtn = new QPushButton(AddPropertyWindow);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(140, 230, 113, 32));

        retranslateUi(AddPropertyWindow);

        QMetaObject::connectSlotsByName(AddPropertyWindow);
    } // setupUi

    void retranslateUi(QWidget *AddPropertyWindow)
    {
        AddPropertyWindow->setWindowTitle(QApplication::translate("AddPropertyWindow", "Form", 0));
        label->setText(QApplication::translate("AddPropertyWindow", "\345\261\236\346\200\247\345\220\215", 0));
        label_2->setText(QApplication::translate("AddPropertyWindow", "\345\261\236\346\200\247\347\261\273\345\236\213", 0));
        confirmBtn->setText(QApplication::translate("AddPropertyWindow", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class AddPropertyWindow: public Ui_AddPropertyWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ADDPROPERTYWINDOW_H

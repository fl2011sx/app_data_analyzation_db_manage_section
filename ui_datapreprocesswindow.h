/********************************************************************************
** Form generated from reading UI file 'datapreprocesswindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DATAPREPROCESSWINDOW_H
#define UI_DATAPREPROCESSWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DataPreprocessWindow
{
public:

    void setupUi(QWidget *DataPreprocessWindow)
    {
        if (DataPreprocessWindow->objectName().isEmpty())
            DataPreprocessWindow->setObjectName(QStringLiteral("DataPreprocessWindow"));
        DataPreprocessWindow->resize(400, 300);

        retranslateUi(DataPreprocessWindow);

        QMetaObject::connectSlotsByName(DataPreprocessWindow);
    } // setupUi

    void retranslateUi(QWidget *DataPreprocessWindow)
    {
        DataPreprocessWindow->setWindowTitle(QApplication::translate("DataPreprocessWindow", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class DataPreprocessWindow: public Ui_DataPreprocessWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DATAPREPROCESSWINDOW_H

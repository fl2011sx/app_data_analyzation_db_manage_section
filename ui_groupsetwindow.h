/********************************************************************************
** Form generated from reading UI file 'groupsetwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GROUPSETWINDOW_H
#define UI_GROUPSETWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_GroupSetWindow
{
public:
    QPushButton *addBtn;
    QPushButton *deleteBtn;
    QPushButton *emptyBtn;
    QPushButton *confirmBtn;
    QTableWidget *groupTable;

    void setupUi(QWidget *GroupSetWindow)
    {
        if (GroupSetWindow->objectName().isEmpty())
            GroupSetWindow->setObjectName(QStringLiteral("GroupSetWindow"));
        GroupSetWindow->resize(537, 379);
        addBtn = new QPushButton(GroupSetWindow);
        addBtn->setObjectName(QStringLiteral("addBtn"));
        addBtn->setGeometry(QRect(420, 60, 113, 32));
        deleteBtn = new QPushButton(GroupSetWindow);
        deleteBtn->setObjectName(QStringLiteral("deleteBtn"));
        deleteBtn->setGeometry(QRect(420, 80, 113, 32));
        emptyBtn = new QPushButton(GroupSetWindow);
        emptyBtn->setObjectName(QStringLiteral("emptyBtn"));
        emptyBtn->setGeometry(QRect(420, 140, 113, 32));
        confirmBtn = new QPushButton(GroupSetWindow);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));
        confirmBtn->setGeometry(QRect(420, 340, 113, 32));
        groupTable = new QTableWidget(GroupSetWindow);
        groupTable->setObjectName(QStringLiteral("groupTable"));
        groupTable->setGeometry(QRect(0, 0, 421, 381));
        groupTable->horizontalHeader()->setVisible(false);

        retranslateUi(GroupSetWindow);

        QMetaObject::connectSlotsByName(GroupSetWindow);
    } // setupUi

    void retranslateUi(QWidget *GroupSetWindow)
    {
        GroupSetWindow->setWindowTitle(QApplication::translate("GroupSetWindow", "Form", 0));
        addBtn->setText(QApplication::translate("GroupSetWindow", "\346\267\273\345\212\240", 0));
        deleteBtn->setText(QApplication::translate("GroupSetWindow", "\345\210\240\351\231\244", 0));
        emptyBtn->setText(QApplication::translate("GroupSetWindow", "\346\270\205\347\251\272", 0));
        confirmBtn->setText(QApplication::translate("GroupSetWindow", "\347\241\256\345\256\232", 0));
    } // retranslateUi

};

namespace Ui {
    class GroupSetWindow: public Ui_GroupSetWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GROUPSETWINDOW_H

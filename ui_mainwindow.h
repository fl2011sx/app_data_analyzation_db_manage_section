/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QPushButton *debugTest;
    QPushButton *showUserBtn;
    QTableWidget *displayView;
    QPushButton *userManageBtn;
    QPushButton *statisticsBtn;
    QPushButton *dependencyBtn;
    QPushButton *forecastBtn;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(756, 493);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        debugTest = new QPushButton(centralWidget);
        debugTest->setObjectName(QStringLiteral("debugTest"));
        debugTest->setGeometry(QRect(10, 200, 113, 32));
        showUserBtn = new QPushButton(centralWidget);
        showUserBtn->setObjectName(QStringLiteral("showUserBtn"));
        showUserBtn->setGeometry(QRect(10, 130, 113, 32));
        displayView = new QTableWidget(centralWidget);
        displayView->setObjectName(QStringLiteral("displayView"));
        displayView->setGeometry(QRect(160, 10, 531, 411));
        displayView->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
        displayView->horizontalHeader()->setHighlightSections(true);
        displayView->verticalHeader()->setVisible(false);
        userManageBtn = new QPushButton(centralWidget);
        userManageBtn->setObjectName(QStringLiteral("userManageBtn"));
        userManageBtn->setGeometry(QRect(10, 250, 113, 32));
        statisticsBtn = new QPushButton(centralWidget);
        statisticsBtn->setObjectName(QStringLiteral("statisticsBtn"));
        statisticsBtn->setGeometry(QRect(10, 300, 113, 32));
        dependencyBtn = new QPushButton(centralWidget);
        dependencyBtn->setObjectName(QStringLiteral("dependencyBtn"));
        dependencyBtn->setGeometry(QRect(10, 340, 113, 32));
        forecastBtn = new QPushButton(centralWidget);
        forecastBtn->setObjectName(QStringLiteral("forecastBtn"));
        forecastBtn->setGeometry(QRect(10, 380, 113, 32));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 756, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        debugTest->setText(QApplication::translate("MainWindow", "DebugTest", 0));
        showUserBtn->setText(QApplication::translate("MainWindow", "\346\230\276\347\244\272\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        userManageBtn->setText(QApplication::translate("MainWindow", "\347\256\241\347\220\206\347\224\250\346\210\267\344\277\241\346\201\257", 0));
        statisticsBtn->setText(QApplication::translate("MainWindow", "\345\210\206\345\270\203\347\273\237\350\256\241", 0));
        dependencyBtn->setText(QApplication::translate("MainWindow", "\347\233\270\345\205\263\346\200\247\345\210\206\346\236\220", 0));
        forecastBtn->setText(QApplication::translate("MainWindow", "\346\225\260\345\200\274\351\242\204\346\265\213", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H

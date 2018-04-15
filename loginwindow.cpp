#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <string>
#include <QDebug>

LoginWindow::LoginWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::LoginWindow),
    mainWindow(new MainWindow)
{
    ui->setupUi(this);
    connect(ui -> connectBtn, SIGNAL(clicked()), this, SLOT(connectDatabase()));
    ui -> pswFiled -> setEchoMode(QLineEdit::EchoMode::Password);
}

void LoginWindow::connectDatabase() {
    QString username = ui -> usernameFile -> text();
    QString psw = ui -> pswFiled -> text();
    QString addr = ui -> addressFiled -> text();
    initDatabase(addr.toStdString(), username.toStdString(), psw.toStdString(), "tpapp");
    if (database) {
        mainWindow -> show();
        close();
    }
}

LoginWindow::~LoginWindow()
{
    delete mainWindow;
    delete ui;
}

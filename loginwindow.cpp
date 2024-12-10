#include "loginwindow.h"
#include "ui_loginwindow.h"
#include <QMessageBox>
#include <QDebug>
#include <QPixmap>

LoginWindow::LoginWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::LoginWindow)
{
    ui->setupUi(this);
    QPixmap pix("C:/QTPicture/red.png");
    int w = ui->label_pic->width();
    int h = ui->label_pic->height();
    ui->label_pic->setPixmap(pix.scaled(w,h,Qt::KeepAspectRatio));
}

LoginWindow::~LoginWindow()
{
    delete ui;
}

void LoginWindow::on_logBtn_clicked()
{
    QString username = ui->userBtn->text();
    QString password = ui->passBtn->text();

    if(username == "admin" and password == "admin") {
        mainmenu = new MainMenu();
        mainmenu->show();
        hide();
    }
    else {
        QMessageBox::warning(this, "Login", "Username and password is incorrect");
    }
}


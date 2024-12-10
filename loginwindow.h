#ifndef LOGINWINDOW_H
#define LOGINWINDOW_H

#include <QMainWindow>
#include "mainmenu.h"
namespace Ui {
class LoginWindow;
}

class LoginWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit LoginWindow(QWidget *parent = nullptr);
    ~LoginWindow();

private slots:
    void on_logBtn_clicked();

private:
    Ui::LoginWindow *ui;
    MainMenu *mainmenu;
};

#endif // LOGINWINDOW_H

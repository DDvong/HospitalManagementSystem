#ifndef MAINMENU_H
#define MAINMENU_H

#include <QWidget>

//forward declarations
class AppointmentForm;
class PatientForm;
class ReportForm;
class LoginWindow;
class DepartmentForm;
class ReferralForm;

namespace Ui {
class MainMenu;
}

class MainMenu : public QWidget
{
    Q_OBJECT

public:
    explicit MainMenu(QWidget *parent = nullptr);
    ~MainMenu();

private slots:
    void on_pushButton_clicked();

    void on_appointmentButton_clicked();

    void on_reportButton_clicked();

    void on_signOutButton_clicked();

    void on_departmentButton_clicked();

    void on_referralButton_clicked();

private:
    Ui::MainMenu *ui;
    PatientForm *patientWindow;
    AppointmentForm *appointmentWindow;
    ReportForm *reportWindow;
    DepartmentForm *departmentWindow;
    ReferralForm *referralWindow;
};

#endif // MAINMENU_H

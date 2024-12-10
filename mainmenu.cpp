#include "mainmenu.h"
#include "ui_mainmenu.h"
#include "PatientForm.h"
#include "AppointmentForm.h"
#include "ReportForm.h"
#include "loginwindow.h"
#include "departmentform.h"
#include "referralform.h"
#include <QPixmap>


MainMenu::MainMenu(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::MainMenu)
{
    ui->setupUi(this);

    QPixmap patientPix("C:/QTPicture/Patient.png");
    int patientW = ui->patientPic->width();
    int patientH = ui->patientPic->height();
    ui->patientPic->setPixmap(patientPix.scaled(patientW,patientW,Qt::KeepAspectRatio));

    QPixmap appointmentPix("C:/QTPicture/Appointment.png");
    int appointmentW = ui->appointmentPic->width();
    int appointmentH = ui->appointmentPic->height();
    ui->appointmentPic->setPixmap(appointmentPix.scaled(appointmentW,appointmentH,Qt::KeepAspectRatio));

    QPixmap reportPix("C:/QTPicture/MedicalReport.png");
    int reportW = ui->reportPic->width();
    int reportH = ui->reportPic->height();
    ui->reportPic->setPixmap(reportPix.scaled(reportW,reportH,Qt::KeepAspectRatio));

    QPixmap departmentPix("C:/QTPicture/Hospital.png");
    int departmentW = ui->departmentPic->width();
    int departmentH = ui->departmentPic->height();
    ui->departmentPic->setPixmap(departmentPix.scaled(departmentW,departmentH,Qt::KeepAspectRatio));

    QPixmap referralPix("C:/QTPicture/Doctor.png");
    int referralW = ui->referralPic->width();
    int referralH = ui->referralPic->height();
    ui->referralPic->setPixmap(referralPix.scaled(referralW,referralH,Qt::KeepAspectRatio));

    QPixmap signOutPix("C:/QTPicture/SignOut.png");
    int signOutW = ui->label_2->width();
    int signOutH = ui->label_2->height();
    ui->label_2->setPixmap(signOutPix.scaled(signOutW,signOutH,Qt::KeepAspectRatio));
}

MainMenu::~MainMenu()
{
    delete ui;
}


void MainMenu::on_pushButton_clicked()
{
    patientWindow = new PatientForm();
    patientWindow->show();
    hide();
}


void MainMenu::on_appointmentButton_clicked()
{
    if (!patientWindow) {
        patientWindow = new PatientForm();
    }
    appointmentWindow = new AppointmentForm();
    appointmentWindow->setPatientTable(&patientWindow->getPatientTable());
    appointmentWindow->show();
    hide();
}


void MainMenu::on_reportButton_clicked()
{
    if (!patientWindow) {
        patientWindow = new PatientForm();
    }
    ReportForm *reports = new ReportForm();
    reports->setPatientTable(&patientWindow->getPatientTable());
    reports->show();
    hide();
}


void MainMenu::on_signOutButton_clicked()
{
    LoginWindow *loginWindow = new LoginWindow(this);
    loginWindow->show();
    hide();
}


void MainMenu::on_departmentButton_clicked()
{
    departmentWindow = new DepartmentForm();
    departmentWindow->show();
    hide();
}


void MainMenu::on_referralButton_clicked()
{
    referralWindow = new ReferralForm();
    referralWindow->show();
    hide();
}


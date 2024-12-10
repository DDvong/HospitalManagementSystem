#include "appointmentform.h"
#include "ui_appointmentform.h"
#include <QDebug>

DailyQueue AppointmentForm::appointmentQueue;

AppointmentForm::AppointmentForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::AppointmentForm)
{
    ui->setupUi(this);
}

AppointmentForm::~AppointmentForm()
{
    delete ui;
}

void AppointmentForm::setPatientTable(PatientHashTable* table) {
    patientTable = table;
}

void AppointmentForm::on_bookButton_clicked()
{
    int patientId = ui->patientIdEdit->text().toInt();
    QString date = ui->dateEdit->date().toString("MM/dd/yyyy");
    QString time = ui->timeEdit->time().toString("hh:mm A");
    QString reason = ui->reasonEdit->text();

    if(patientTable && patientTable->findPatient(patientId) != nullptr) {
        appointmentQueue.enqueue(date, time, patientId, reason);
        ui->notesEdit->setText("Appointments:\n"
                               "Date: " + date + "\n"
                               "Time: " + time + "\n"
                               "Patient ID: " + QString::number(patientId) + "\n"
                               "Reason: " + reason);
        ui->patientIdEdit->clear();
        ui->reasonEdit->clear();
    }

}

void AppointmentForm::on_appBackButton_clicked()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}


void AppointmentForm::on_viewQueue_clicked()
{
    ui->notesEdit->setText(appointmentQueue.viewQueue());

}

void AppointmentForm::on_completeButton_clicked()
{
    if(!appointmentQueue.isEmpty()) {
        Appointment app = appointmentQueue.dequeue();
        ui->notesEdit->setText("Completed Appointment:\n"
                               "Date: " + app.date + "\n"
                               "Time: " + app.time + "\n"
                               "Patient ID: " + QString::number(app.patientId) + "\n"
                               "Reason: " + app.reason);
    } else {
        ui->notesEdit->setText("No appointment.");
    }
}


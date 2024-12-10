#include "reportform.h"
#include "ui_reportform.h"
#include <QDebug>

MedicalReports ReportForm::medicalReports;

ReportForm::ReportForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReportForm)
{
    ui->setupUi(this);
}

ReportForm::~ReportForm()
{
    delete ui;
}

void ReportForm::setPatientTable(PatientHashTable* table) {
    patientTable = table;
}

void ReportForm::on_addReportButton_clicked()
{
    int patientId = ui->patientDEdit->text().toInt();
    QString date = ui->reportDateEdit->date().toString("MM/dd/yyyy");
    QString symptoms = ui->symptomsEdit->text();
    QString diagnosis = ui->diagnosisEdit->text();
    QString treatment = ui->treatmentEdit->text();

    if(patientTable && patientTable->findPatient(patientId)) {
        medicalReports.addReport(patientId, date, symptoms, diagnosis, treatment);

        ui->symptomsEdit->clear();
        ui->diagnosisEdit->clear();
        ui->treatmentEdit->clear();
    } else {
        ui->notesEdit->setText("Patient ID not found");
    }
}


void ReportForm::on_viewReportsButton_clicked()
{
    QString allReports = medicalReports.getReports();
    ui->notesEdit->setText(allReports);

}


void ReportForm::on_reportBackButton_clicked()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}


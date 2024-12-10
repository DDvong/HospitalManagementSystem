#include "PatientForm.h"
#include "./ui_PatientForm.h"
#include <QString>
#include "mainmenu.h"
#include <QDebug>

using namespace std;

PatientHashTable PatientForm::patientTable;

PatientForm::PatientForm(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatientForm)
{
    ui->setupUi(this);

    connect(ui->addButton, &QPushButton::clicked, this, &PatientForm::on_addButton_clicked);
    connect(ui->findButton, &QPushButton::clicked, this, &PatientForm::on_findButton_clicked);
}

PatientForm::~PatientForm()
{
    delete ui;
}


void PatientForm::on_addButton_clicked()
{
    Patient newPatient;
    newPatient.name = ui->nameEdit->text();
    newPatient.id = ui->idEdit->text().toInt();
    newPatient.age = ui->ageEdit->text().toInt();
    newPatient.gender = ui->genderEdit->text();
    newPatient.phone = ui->phoneEdit->text();
    newPatient.condition = ui->conditionEdit->text();

    patientTable.addPatient(newPatient);

    ui->resultDisplay->setText("Added Patient:\n"
                               "Name: " + newPatient.name + "\n"
                               "ID: " + QString::number(newPatient.id) + "\n"
                               "Age: " + QString::number(newPatient.age) + "\n"
                               "Gender: " + newPatient.gender + "\n"
                               "Phone: " + newPatient.phone + "\n"
                               "Condition: " + newPatient.condition);
}


void PatientForm::on_findButton_clicked()
{
    int searchId = ui->idEdit->text().toInt();
    Patient* found = patientTable.findPatient(searchId);

    if (found != nullptr) {
        ui->resultDisplay->setText("Found patient: " + found->name + "\n"
                                   "ID: " + QString::number(found->id) + "\n"
                                   "Age: " + QString::number(found->age) + "\n"
                                   "Gender: " + found->gender + "\n"
                                   "Phone: " + found->phone + "\n"
                                   "Condition: " + found->condition);
    } else {
        ui->resultDisplay->setText("Patient not found with ID: " +
                                   QString::number(searchId));
    }
}

void PatientForm::on_backFormButton_clicked()
{
    MainMenu *menu = new MainMenu();
    menu ->show();
    this->close();
}


void PatientForm::on_clearButton_clicked()
{
    ui->nameEdit->clear();
    ui->idEdit->clear();
    ui->ageEdit->clear();
    ui->genderEdit->clear();
    ui->phoneEdit->clear();
    ui->conditionEdit->clear();
    ui->resultDisplay->clear();
}


void PatientForm::on_deleteButton_clicked()
{
    int id = ui->idEdit->text().toInt();
    if(patientTable.findPatient(id) != nullptr) {
        patientTable.deletePatient(id);
        ui->resultDisplay->setText("Patient with ID: " + QString::number(id) + " has been deleted");
        // Clear the form after deletion
        on_clearButton_clicked();
    } else {
        ui->resultDisplay->setText("Patient with ID: " + QString::number(id) + " not found");
    }
}


void PatientForm::on_viewButton_clicked()
{
    QString display = "All Patients:\n\n";

    unordered_map<int, Patient>& patients = patientTable.patientList;
    for(int id = 1; id <= patientTable.countPatients(); id++) {
        if(Patient* patient = patientTable.findPatient(id)) {
            display += "Name: " + patient->name + "\n";
            display += "ID: " + QString::number(patient->id) + "\n";
            display += "Age: " + QString::number(patient->age) + "\n";
            display += "Gender: " + patient->gender + "\n";
            display += "Phone: " + patient->phone + "\n";
            display += "Condition: " + patient->condition + "\n";
            display += "------------------------\n";
        }
    }
    ui->resultDisplay->setText(display);
}


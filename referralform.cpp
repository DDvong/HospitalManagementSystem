#include "referralform.h"
#include "ui_referralform.h"
#include "mainmenu.h"

ReferralGraph ReferralForm::referralGraph;

ReferralForm::ReferralForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::ReferralForm)
{
    ui->setupUi(this);
}

ReferralForm::~ReferralForm()
{
    delete ui;
}

void ReferralForm::on_addDoctorButton_clicked()
{
    QString name = ui->doctorNameEdit->text();
    QString specialty = ui->specialtyEdit->text();

    if(!name.isEmpty() && !specialty.isEmpty()) {
        referralGraph.addDoctor(name, specialty);
        ui->referralDisplay->setText("Doctor added: " + name + " (" + specialty + ")");
        ui->doctorNameEdit->clear();
        ui->specialtyEdit->clear();
    }
}


void ReferralForm::on_pushButton_clicked()
{
    QString fromDoctor = ui->fromDoctorEdit->text();
    QString toDoctor = ui->toDoctorEdit->text();

    if(!fromDoctor.isEmpty() && !toDoctor.isEmpty()) {
        referralGraph.addReferral(fromDoctor, toDoctor);
        ui->referralDisplay->setText("Referral added: " + fromDoctor + " -> " + toDoctor);
        ui->fromDoctorEdit->clear();
        ui->toDoctorEdit->clear();
    }

}


void ReferralForm::on_viewButton_clicked()
{
     ui->referralDisplay->setText(referralGraph.displayReferrals());
}


void ReferralForm::on_referralBackButton_clicked()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}

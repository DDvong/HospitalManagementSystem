#include "departmentform.h"
#include "ui_departmentform.h"
#include "mainmenu.h"

DepartmentTree DepartmentForm::departmentTree;

DepartmentForm::DepartmentForm(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::DepartmentForm)
{
    ui->setupUi(this);
}

DepartmentForm::~DepartmentForm()
{
    delete ui;
}

void DepartmentForm::on_addDeptButton_clicked()
{
    QString deptName = ui->departmentEdit->text();
    if(!deptName.isEmpty()) {
        departmentTree.insert(deptName);
        ui->deptDisplay->setText("Department added: " + deptName + "\n\n" + departmentTree.display());
        ui->departmentEdit->clear();
    }
}


void DepartmentForm::on_viewDeptButton_clicked()
{
    ui->deptDisplay->setText(departmentTree.display());
}


void DepartmentForm::on_deptBackButton_clicked()
{
    MainMenu *menu = new MainMenu();
    menu->show();
    this->close();
}


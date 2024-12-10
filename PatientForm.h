#ifndef PATIENTFORM_H
#define PATIENTFORM_H

#include <QMainWindow>
#include "DataStructures.h"

class MainMenu;

QT_BEGIN_NAMESPACE
namespace Ui {
class PatientForm;
}
QT_END_NAMESPACE

class PatientForm : public QMainWindow
{
    Q_OBJECT

public:
    PatientForm(QWidget *parent = nullptr);
    ~PatientForm();

    PatientHashTable& getPatientTable() {
        return patientTable;
    }

private slots:
    void on_backFormButton_clicked();

    void on_addButton_clicked();

    void on_findButton_clicked();

    void on_clearButton_clicked();

    void on_deleteButton_clicked();

    void on_viewButton_clicked();

private:
    Ui::PatientForm *ui;
    static PatientHashTable patientTable;
};
#endif // PATIENTFORM_H

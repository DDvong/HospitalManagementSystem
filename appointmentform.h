#ifndef APPOINTMENTFORM_H
#define APPOINTMENTFORM_H

#include <QWidget>
#include "DataStructures.h"
#include "mainmenu.h"

namespace Ui {
class AppointmentForm;
}

class AppointmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit AppointmentForm(QWidget *parent = nullptr);
    ~AppointmentForm();
    void setPatientTable(PatientHashTable* table);

private slots:
    void on_bookButton_clicked();

    void on_appBackButton_clicked();

    void on_viewQueue_clicked();

    void on_completeButton_clicked();

private:
    Ui::AppointmentForm *ui;
    static DailyQueue appointmentQueue;
    PatientHashTable* patientTable;
};

#endif // APPOINTMENTFORM_H

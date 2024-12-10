#ifndef REPORTFORM_H
#define REPORTFORM_H

#include "DataStructures.h"
#include <QWidget>
#include "mainmenu.h"

namespace Ui {
class ReportForm;
}

class ReportForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReportForm(QWidget *parent = nullptr);
    ~ReportForm();
    void setPatientTable(PatientHashTable* table); //handles if patientTable is nullptr

private slots:
    void on_addReportButton_clicked();

    void on_viewReportsButton_clicked();

    void on_reportBackButton_clicked();

private:
    Ui::ReportForm *ui;
    static MedicalReports medicalReports;
    PatientHashTable* patientTable;
};

#endif // REPORTFORM_H

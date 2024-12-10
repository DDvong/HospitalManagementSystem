#ifndef DEPARTMENTFORM_H
#define DEPARTMENTFORM_H

#include <QWidget>
#include "DataStructures.h"

namespace Ui {
class DepartmentForm;
}

class DepartmentForm : public QWidget
{
    Q_OBJECT

public:
    explicit DepartmentForm(QWidget *parent = nullptr);
    ~DepartmentForm();

private slots:
    void on_addDeptButton_clicked();

    void on_viewDeptButton_clicked();

    void on_deptBackButton_clicked();

private:
    Ui::DepartmentForm *ui;
    static DepartmentTree departmentTree;
};

#endif // DEPARTMENTFORM_H

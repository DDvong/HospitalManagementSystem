#ifndef REFERRALFORM_H
#define REFERRALFORM_H

#include <QWidget>
#include "DataStructures.h"

namespace Ui {
class ReferralForm;
}

class ReferralForm : public QWidget
{
    Q_OBJECT

public:
    explicit ReferralForm(QWidget *parent = nullptr);
    ~ReferralForm();

private slots:
    void on_addDoctorButton_clicked();

    void on_pushButton_clicked();

    void on_viewButton_clicked();

    void on_referralBackButton_clicked();

private:
    Ui::ReferralForm *ui;
    static ReferralGraph referralGraph;
};

#endif // REFERRALFORM_H

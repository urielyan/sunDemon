#ifndef VISCOSITYCCALIBRATION_H
#define VISCOSITYCCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ViscosityCcalibration;
}

class ViscosityCcalibration : public Widget
{
    Q_OBJECT

public:
    explicit ViscosityCcalibration(QWidget *parent = 0);
    ~ViscosityCcalibration();

private:
    Ui::ViscosityCcalibration *ui;
};

#endif // VISCOSITYCCALIBRATION_H

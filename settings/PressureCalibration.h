#ifndef PRESSURECALIBRATION_H
#define PRESSURECALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class PressureCalibration;
}

class PressureCalibration : public Widget
{
    Q_OBJECT

public:
    explicit PressureCalibration(QWidget *parent = 0);
    ~PressureCalibration();

private:
    Ui::PressureCalibration *ui;
};

#endif // PRESSURECALIBRATION_H

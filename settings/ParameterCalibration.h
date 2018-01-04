#ifndef PARAMETERCALIBRATION_H
#define PARAMETERCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ParameterCalibration;
}

class ParameterCalibration : public Widget
{
    Q_OBJECT

public:
    explicit ParameterCalibration(QWidget *parent = 0);
    ~ParameterCalibration();

private:
    Ui::ParameterCalibration *ui;
};

#endif // PARAMETERCALIBRATION_H

#ifndef TEMPERATURECALIBRATION_H
#define TEMPERATURECALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class TemperatureCalibration;
}

class TemperatureCalibration : public Widget
{
    Q_OBJECT

public:
    explicit TemperatureCalibration(QWidget *parent = 0);
    ~TemperatureCalibration();

private:
    Ui::TemperatureCalibration *ui;
};

#endif // TEMPERATURECALIBRATION_H

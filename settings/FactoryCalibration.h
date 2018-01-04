#ifndef FACTORYCALIBRATION_H
#define FACTORYCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class FactoryCalibration;
}

class FactoryCalibration : public Widget
{
    Q_OBJECT

public:
    explicit FactoryCalibration(QWidget *parent = 0);
    ~FactoryCalibration();

private slots:
    void on_temperature_clicked();

    void on_pressure_clicked();

    void on_manualControl_clicked();

    void on_autoTest_clicked();

    void on_pollute_clicked();

    void on_viscosity_clicked();

    void on_FeContent_clicked();

    void on_moisture_clicked();

    void on_parameter_clicked();

private:
    Ui::FactoryCalibration *ui;
};

#endif // FACTORYCALIBRATION_H

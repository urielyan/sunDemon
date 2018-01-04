#ifndef MOISTURECALIBRATION_H
#define MOISTURECALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class MoistureCalibration;
}

class MoistureCalibration : public Widget
{
    Q_OBJECT

public:
    explicit MoistureCalibration(QWidget *parent = 0);
    ~MoistureCalibration();

private:
    Ui::MoistureCalibration *ui;
};

#endif // MOISTURECALIBRATION_H

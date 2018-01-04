#ifndef AUTOTESTCALIBRATION_H
#define AUTOTESTCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class AutoTestCalibration;
}

class AutoTestCalibration : public Widget
{
    Q_OBJECT

public:
    explicit AutoTestCalibration(QWidget *parent = 0);
    ~AutoTestCalibration();

private:
    Ui::AutoTestCalibration *ui;
};

#endif // AUTOTESTCALIBRATION_H

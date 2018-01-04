#ifndef ANUALCONTROLCALIBRATION_H
#define ANUALCONTROLCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ManualControlCalibration;
}

class ManualControlCalibration : public Widget
{
    Q_OBJECT

public:
    explicit ManualControlCalibration(QWidget *parent = 0);
    ~ManualControlCalibration();

private:
    Ui::ManualControlCalibration *ui;
};

#endif // ANUALCONTROLCALIBRATION_H

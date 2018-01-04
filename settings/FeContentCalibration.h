#ifndef FECONTENTCALIBRATION_H
#define FECONTENTCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class FeContentCalibration;
}

class FeContentCalibration : public Widget
{
    Q_OBJECT

public:
    explicit FeContentCalibration(QWidget *parent = 0);
    ~FeContentCalibration();

private:
    Ui::FeContentCalibration *ui;
};

#endif // FECONTENTCALIBRATION_H

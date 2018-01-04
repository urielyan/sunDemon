#ifndef USERCALIBRATION_H
#define USERCALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class UserCalibration;
}

class UserCalibration : public Widget
{
    Q_OBJECT

public:
    explicit UserCalibration(QWidget *parent = 0);
    ~UserCalibration();

private:
    Ui::UserCalibration *ui;
};

#endif // USERCALIBRATION_H

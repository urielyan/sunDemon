#ifndef POLLUTECALIBRATION_H
#define POLLUTECALIBRATION_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class PolluteCalibration;
}

class PolluteCalibration : public Widget
{
    Q_OBJECT

public:
    explicit PolluteCalibration(QWidget *parent = 0);
    ~PolluteCalibration();

private:
    Ui::PolluteCalibration *ui;
};

#endif // POLLUTECALIBRATION_H

#ifndef CALIBRATIONMAINWIN_H
#define CALIBRATIONMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CalibrationMainWin;
}

class CalibrationMainWin : public Widget
{
    Q_OBJECT

public:
    explicit CalibrationMainWin(QWidget *parent = 0);
    ~CalibrationMainWin();

private slots:
    void on_userCalibration_clicked();

    void on_factoryCalibration_clicked();

private:
    Ui::CalibrationMainWin *ui;
};

#endif // CALIBRATIONMAINWIN_H

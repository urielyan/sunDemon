#ifndef CALIBRATEMEASUREMENTMAINWIN_H
#define CALIBRATEMEASUREMENTMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CalibrateMeasurementMainWin;
}

class CalibrateMeasurementMainWin : public Widget
{
    Q_OBJECT

public:
    explicit CalibrateMeasurementMainWin(QWidget *parent = 0);
    ~CalibrateMeasurementMainWin();

private slots:
    void on_calibrateMeasurement_clicked();

    void on_viewCalibratedData_clicked();

    void on_inputSContent_clicked();

private:
    Ui::CalibrateMeasurementMainWin *ui;
};

#endif // CALIBRATEMEASUREMENTMAINWIN_H

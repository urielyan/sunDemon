#ifndef CALIBRATEMEASUREMENTING_H
#define CALIBRATEMEASUREMENTING_H

#include <MeasurementingWidget.h>
#include <QWidget>
#include <Widget.h>

namespace Ui {
class CalibrateMeasurementing;
}

class CalibrateMeasurementing : public MeasurementingWidget
{
    Q_OBJECT

public:
    explicit CalibrateMeasurementing(QWidget *parent = 0);
    ~CalibrateMeasurementing();

    bool init();

protected:
    void timerEvent(QTimerEvent *event);

private slots:
    void on_restart_clicked();

    void on_stop_clicked();

private:
    Ui::CalibrateMeasurementing *ui;
};

#endif // CALIBRATEMEASUREMENTING_H

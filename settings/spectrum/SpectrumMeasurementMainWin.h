#ifndef SPECTRUMMEASUREMENT_H
#define SPECTRUMMEASUREMENT_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class SpectrumMeasurementMainWin;
}

class SpectrumMeasurementMainWin : public Widget
{
    Q_OBJECT

public:
    explicit SpectrumMeasurementMainWin(QWidget *parent = 0);
    ~SpectrumMeasurementMainWin();

private slots:
    void on_moveToReference_clicked();

    void on_moveToTest_clicked();

private:
    Ui::SpectrumMeasurementMainWin *ui;
};

#endif // SPECTRUMMEASUREMENT_H

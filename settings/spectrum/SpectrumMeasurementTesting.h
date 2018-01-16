#ifndef SPECTRUMMEASUREMENTTESTING_H
#define SPECTRUMMEASUREMENTTESTING_H

#include <MeasurementingWidget.h>
#include <QWidget>
#include <Widget.h>

namespace Ui {
class SpectrumMeasurementTesting;
}

class SpectrumMeasurementTesting : public MeasurementingWidget
{
    Q_OBJECT

public:
    explicit SpectrumMeasurementTesting(QWidget *parent = 0);
    ~SpectrumMeasurementTesting();
    virtual bool init() Q_DECL_OVERRIDE;

private:
    Ui::SpectrumMeasurementTesting *ui;
};

#endif // SPECTRUMMEASUREMENTTESTING_H

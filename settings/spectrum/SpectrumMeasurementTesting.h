#ifndef SPECTRUMMEASUREMENTTESTING_H
#define SPECTRUMMEASUREMENTTESTING_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class SpectrumMeasurementTesting;
}

class SpectrumMeasurementTesting : public Widget
{
    Q_OBJECT

public:
    explicit SpectrumMeasurementTesting(QWidget *parent = 0);
    ~SpectrumMeasurementTesting();
    virtual bool init() Q_DECL_OVERRIDE;

private:
    Ui::SpectrumMeasurementTesting *ui;

    int m_count;
    int m_seconds;
    int m_timerID;
    bool m_isLoop;
};

#endif // SPECTRUMMEASUREMENTTESTING_H

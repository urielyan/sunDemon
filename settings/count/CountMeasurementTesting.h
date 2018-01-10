#ifndef COUNTMEASUREMENTTESTING_H
#define COUNTMEASUREMENTTESTING_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CountMeasurementTesting;
}

class CountMeasurementTesting : public Widget
{
    Q_OBJECT

public:
    explicit CountMeasurementTesting(QWidget *parent = 0);
    ~CountMeasurementTesting();

    bool init() Q_DECL_OVERRIDE;

    bool isLoop() const;
    void setIsLoop(bool isLoop);

protected:
    void timerEvent(QTimerEvent *event);
private:
    Ui::CountMeasurementTesting *ui;

    int m_count;
    int m_seconds;
    int m_timerID;
    bool m_isLoop;
};

#endif // COUNTMEASUREMENTTESTING_H

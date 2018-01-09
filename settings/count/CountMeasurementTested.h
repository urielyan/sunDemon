#ifndef COUNTMEASUREMENTTESTED_H
#define COUNTMEASUREMENTTESTED_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CountMeasurementTested;
}

class CountMeasurementTested : public Widget
{
    Q_OBJECT

public:
    explicit CountMeasurementTested(QWidget *parent = 0);
    ~CountMeasurementTested();

private:
    Ui::CountMeasurementTested *ui;
};

#endif // COUNTMEASUREMENTTESTED_H

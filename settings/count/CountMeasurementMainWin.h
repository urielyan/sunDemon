#ifndef COUNTMEASUREMENTMAINWIN_H
#define COUNTMEASUREMENTMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CountMeasurementMainWin;
}

class CountMeasurementMainWin : public Widget
{
    Q_OBJECT

public:
    explicit CountMeasurementMainWin(QWidget *parent = 0);
    ~CountMeasurementMainWin();

private slots:
    void on_moveToReference_clicked();

    void on_moveToTest_clicked();

private:
    Ui::CountMeasurementMainWin *ui;
};

#endif // COUNTMEASUREMENTMAINWIN_H

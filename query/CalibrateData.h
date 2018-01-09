#ifndef CALIBRATEDATA_H
#define CALIBRATEDATA_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CalibrateData;
}

class CalibrateData : public Widget
{
    Q_OBJECT

public:
    explicit CalibrateData(QWidget *parent = 0);
    ~CalibrateData();

private:
    Ui::CalibrateData *ui;
};

#endif // CALIBRATEDATA_H

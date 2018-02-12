#ifndef CALIBRATERESULTDETAILS_H
#define CALIBRATERESULTDETAILS_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CalibrateResultDetails;
}

class CalibrateResultDetails : public Widget
{
    Q_OBJECT

public:
    explicit CalibrateResultDetails(QWidget *parent = 0);
    ~CalibrateResultDetails();

    void setKBR(QString kbr);
    void setDateTime(QString dateTime);
    void setData(QByteArray array);

private:
    Ui::CalibrateResultDetails *ui;
};

#endif // CALIBRATERESULTDETAILS_H

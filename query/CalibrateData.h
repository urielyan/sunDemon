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
    virtual bool init();

private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::CalibrateData *ui;
};

#endif // CALIBRATEDATA_H

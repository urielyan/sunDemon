#ifndef VIEWCALIBRATEDATA_H
#define VIEWCALIBRATEDATA_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ViewCalibrateData;
}

class ViewCalibrateData : public Widget
{
    Q_OBJECT

public:
    explicit ViewCalibrateData(QWidget *parent = 0);
    ~ViewCalibrateData();
    virtual bool init();

private slots:
    void on_deleteCalibrateData_clicked();

private:
    Ui::ViewCalibrateData *ui;
};

#endif // VIEWCALIBRATEDATA_H

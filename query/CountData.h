#ifndef COUNTDATA_H
#define COUNTDATA_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CountData;
}

class CountData : public Widget
{
    Q_OBJECT

public:
    explicit CountData(QWidget *parent = 0);
    ~CountData();

private:
    Ui::CountData *ui;
};

#endif // COUNTDATA_H

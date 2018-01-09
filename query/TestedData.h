#ifndef TESTEDDATA_H
#define TESTEDDATA_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class TestedData;
}

class TestedData : public Widget
{
    Q_OBJECT

public:
    explicit TestedData(QWidget *parent = 0);
    ~TestedData();

private:
    Ui::TestedData *ui;
};

#endif // TESTEDDATA_H

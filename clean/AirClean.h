#ifndef AIRCLEAN_H
#define AIRCLEAN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class AirClean;
}

class AirClean : public Widget
{
    Q_OBJECT

public:
    explicit AirClean(QWidget *parent = 0);
    ~AirClean();

private:
    Ui::AirClean *ui;
};

#endif // AIRCLEAN_H

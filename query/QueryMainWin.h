#ifndef QUERYMAINWIN_H
#define QUERYMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class QueryMainWin;
}

class QueryMainWin : public Widget
{
    Q_OBJECT

public:
    explicit QueryMainWin(QWidget *parent = 0);
    ~QueryMainWin();

private:
    Ui::QueryMainWin *ui;
};

#endif // QUERYMAINWIN_H

#ifndef SELFCHECKERRWIN_H
#define SELFCHECKERRWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class SelfCheckErrWin;
}

class SelfCheckErrWin : public Widget
{
    Q_OBJECT

public:
    explicit SelfCheckErrWin(QWidget *parent = 0);
    ~SelfCheckErrWin();

private slots:
    void on_selffChecckButton_clicked();

private:
    Ui::SelfCheckErrWin *ui;
};

#endif // SELFCHECKERRWIN_H

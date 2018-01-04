#ifndef CLEANMAINWIN_H
#define CLEANMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class CleanMainWin;
}

class CleanMainWin : public Widget
{
    Q_OBJECT

public:
    explicit CleanMainWin(QWidget *parent = 0);
    ~CleanMainWin();

private slots:
    void on_airClean_clicked();

    void on_reagentClean_clicked();

private:
    Ui::CleanMainWin *ui;
};

#endif // CLEANMAINWIN_H

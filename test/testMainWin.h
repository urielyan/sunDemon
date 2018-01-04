#ifndef TESTMAINWIN_H
#define TESTMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class testMainWin;
}

class TestMainWin : public Widget
{
    Q_OBJECT

public:
    explicit TestMainWin(QWidget *parent = 0);
    ~TestMainWin();

    bool init() Q_DECL_OVERRIDE;
private slots:
    void on_sure_clicked();

private:
    Ui::testMainWin *ui;
};

#endif // TESTMAINWIN_H

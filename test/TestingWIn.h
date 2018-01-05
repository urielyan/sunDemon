#ifndef TESTINGWIN_H
#define TESTINGWIN_H

#include "TestInfo.h"

#include <QWidget>
#include <Widget.h>

namespace Ui {
class TestingWIn;
}

class TestingWIn : public Widget
{
    Q_OBJECT

public:
    explicit TestingWIn(QWidget *parent = 0);
    ~TestingWIn();

    TestInfo &info();
    void setInfo(TestInfo &info);

protected slots:
    void timerEvent(QTimerEvent *event);

private slots:

private:
    Ui::TestingWIn *ui;

    TestInfo m_info;
    int m_timerID;

private:
    void updateTableWidget();
};

#endif // TESTINGWIN_H

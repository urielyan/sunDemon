#ifndef TESTINGWIN_H
#define TESTINGWIN_H

#include "TestInfo.h"

#include <QWidget>
#include <Widget.h>
#include <masterthread.h>

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
    void startTest();
    void showResponse(const QString &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:
    Ui::TestingWIn *ui;

    TestInfo m_info;
    int m_timerID;
    MasterThread thread;

private:
    void updateTableWidget();
};

#endif // TESTINGWIN_H

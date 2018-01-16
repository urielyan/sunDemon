#ifndef TESTINGWIN_H
#define TESTINGWIN_H

#include "TestInfo.h"

#include <MeasurementingWidget.h>
#include <QWidget>
#include <Widget.h>
#include <masterthread.h>

namespace Ui {
class TestingWIn;
}

class TestingWIn : public MeasurementingWidget
{
    Q_OBJECT

public:
    explicit TestingWIn(QWidget *parent = 0);
    ~TestingWIn();
    bool init() Q_DECL_OVERRIDE;

    TestInfo &info();
    void setInfo(TestInfo &info);

protected slots:
    void timerEvent(QTimerEvent *event);

private slots:
    void startTest();
    void showResponse(const QByteArray &s);
    void processError(const QString &s);
    void processTimeout(const QString &s);

private:
    Ui::TestingWIn *ui;

    TestInfo m_info;
    int m_dataID;
    MasterThread thread;

private:
    void updateTableWidget();
};

#endif // TESTINGWIN_H

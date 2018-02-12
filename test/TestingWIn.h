#ifndef TESTINGWIN_H
#define TESTINGWIN_H

#include "TestInfo.h"

#include <MeasurementingWidget.h>
#include <QWidget>
#include <Widget.h>

namespace Ui {
class TestingWIn;
}

class TestingWIn : public MeasurementingWidget
{
    Q_OBJECT

public:
    explicit TestingWIn(QWidget *parent = 0);
    ~TestingWIn() Q_DECL_OVERRIDE;
    bool init() Q_DECL_OVERRIDE;

    TestInfo &info();
    void setInfo(TestInfo &info);

protected slots:
    void timerEvent(QTimerEvent *event);

private slots:
    void startTest();
    void showResponse(const QByteArray &s) Q_DECL_OVERRIDE;
    void processError(const QString &s) Q_DECL_OVERRIDE;
    void processTimeout(const QString &s) Q_DECL_OVERRIDE;

private:
    Ui::TestingWIn *ui;

    TestInfo m_info;
    int m_dataID;

private:
    void updateTableWidget();
    bool saveData();
};

#endif // TESTINGWIN_H

#include "MeasurementingWidget.h"

#include <QDebug>
MeasurementingWidget::MeasurementingWidget(QWidget *parent)
    : Widget(parent)
    , m_timerID(-1)
    , m_remainingTimeColumn(-1)
    , m_count(0)
    , m_seconds(0)
    , m_interval(10)
{
    connect(&thread, &MasterThread::response,
            this, &MeasurementingWidget::showResponse);
    connect(&thread, &MasterThread::error,
            this, &MeasurementingWidget::processError);
    connect(&thread, &MasterThread::timeout,
            this, &MeasurementingWidget::processTimeout);
}

MeasurementingWidget::~MeasurementingWidget()
{
    qDebug() << __FUNCTION__;
    disconnect(&thread, &MasterThread::response,
               this, &MeasurementingWidget::showResponse);
    disconnect(&thread, &MasterThread::error,
               this, &MeasurementingWidget::processError);
    disconnect(&thread, &MasterThread::timeout,
               this, &MeasurementingWidget::processTimeout);
}

void MeasurementingWidget::showResponse(const QByteArray &s)
{
    //TODO
}

void MeasurementingWidget::processError(const QString &s)
{
    //TODO

}

void MeasurementingWidget::processTimeout(const QString &s)
{
    //TODO
}

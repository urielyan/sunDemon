#include "MeasurementingWidget.h"

#include <QTableWidget>
MeasurementingWidget::MeasurementingWidget(QWidget *parent)
    : Widget(parent)
    , m_timerID(-1)
    , m_remainingTimeColumn(-1)
    , m_count(0)
    , m_seconds(0)
    , m_interval(10)
{

}

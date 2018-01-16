#ifndef MEASUREMENTINGWIDGET_H
#define MEASUREMENTINGWIDGET_H

#include <QWidget>
#include <Widget.h>

class QTableWidge;
class MeasurementingWidget : public Widget
{
    Q_OBJECT
public:
    explicit MeasurementingWidget(QWidget *parent = 0);

signals:

public slots:

protected:
    int m_timerID;//startTimer之后的Timer ID
    int m_remainingTimeColumn;//TableWidget中剩余时间列
    int m_count;//共多少组数据
    int m_seconds;//多久更新一次数据
    int m_interval;//计时器间隔，单位：毫秒。
};

#endif // MEASUREMENTINGWIDGET_H

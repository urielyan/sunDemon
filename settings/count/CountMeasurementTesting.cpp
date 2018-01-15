#include "CountMeasurementTesting.h"
#include "ui_CountMeasurementTesting.h"


#include <QTimerEvent>
#include <QDebug>

#include "CountMeasurementTested.h"
CountMeasurementTesting::CountMeasurementTesting(QWidget *parent) :
    MeasurementingWidget(parent),
    ui(new Ui::CountMeasurementTesting)

  , m_isLoop(false)
{
    ui->setupUi(this);
    m_title = tr("正在计数测量");

    m_count = 11;
    m_seconds = 60;
    m_remainingTimeColumn = 1;
}

CountMeasurementTesting::~CountMeasurementTesting()
{
    delete ui;
}

bool CountMeasurementTesting::init()
{
    //TODO: 初始化位置Label
    ui->tableWidget->setRowCount(m_count);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(
                0, new QTableWidgetItem(tr("计数数据")));
    ui->tableWidget->setHorizontalHeaderItem(
                1, new QTableWidgetItem(tr("剩余时间")));
    for (int i = 0; i < m_count; ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());

        QString remainTimeString = QString::number((i+1) * m_seconds);
        QTableWidgetItem * item = new QTableWidgetItem(remainTimeString);
        ui->tableWidget->setItem(i, m_remainingTimeColumn, item);
    }
    m_timerID = startTimer(m_interval);

    return true;
}

void CountMeasurementTesting::timerEvent(QTimerEvent *event)
{
    if (event->timerId() == m_timerID)
    {
        for (int i = 0; i < m_count; ++i)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, m_remainingTimeColumn);
            if (item)
            {
                int remainTime = item->text().toInt();
                remainTime--;
                if(remainTime <= 0)
                {
                    item->setText(QString::number(0));

                    if(i == m_count - 1)
                    {
                        killTimer(m_timerID);
                        qDebug() << m_isLoop;
                        if (m_isLoop)
                        {
                            init();
                            return;
                        }
                        CountMeasurementTested *tested = new CountMeasurementTested();
                        emit moveToNextWidget(tested);
                    }
                    continue;
                }
                item->setText(QString::number(remainTime));
            }
        }
    }

}

bool CountMeasurementTesting::isLoop() const
{
    return m_isLoop;
}

void CountMeasurementTesting::setIsLoop(bool isLoop)
{
    m_isLoop = isLoop;
}

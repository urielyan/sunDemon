#include "CalibrateMeasurementing.h"
#include "ui_CalibrateMeasurementing.h"

CalibrateMeasurementing::CalibrateMeasurementing(QWidget *parent) :
    MeasurementingWidget(parent),
    ui(new Ui::CalibrateMeasurementing)
{
    ui->setupUi(this);
    m_title = tr("正在标定测量");

    m_count = 2;
    m_seconds = 180;
    m_remainingTimeColumn = 2;
}

CalibrateMeasurementing::~CalibrateMeasurementing()
{
    delete ui;
}

bool CalibrateMeasurementing::init()
{
    for (int i = 0; i < m_count; ++i)
    {
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem());

        QString remainTimeString = QString::number((i+1) * m_seconds);
        QTableWidgetItem * item = new QTableWidgetItem(remainTimeString);
        ui->tableWidget->setItem(i, m_remainingTimeColumn, item);
    }

    m_timerID = startTimer(m_interval);
    return true;
}

void CalibrateMeasurementing::timerEvent(QTimerEvent *event)
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
                    //TODO: 得到数据
                    if(i == m_count - 1)
                    {
                        killTimer(m_timerID);
                    }
                    continue;
                }
                item->setText(QString::number(remainTime));
            }
        }
    }

}

void CalibrateMeasurementing::on_restart_clicked()
{
    killTimer(m_timerID);
    init();
}

void CalibrateMeasurementing::on_stop_clicked()
{
    killTimer(m_timerID);
}

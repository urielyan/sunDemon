#include "TestingWIn.h"
#include "ui_TestingWIn.h"

#include <QTimer>
#include <QDebug>

TestingWIn::TestingWIn(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestingWIn)
{
    ui->setupUi(this);
}

TestingWIn::~TestingWIn()
{
    qDebug() << __FUNCTION__;
    delete ui;
}

TestInfo &TestingWIn::info()
{
    return m_info;
}

void TestingWIn::setInfo(TestInfo &info)
{
    m_info = info;
    updateTableWidget();
}

void TestingWIn::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer ID:" << event->timerId();

    if (event->timerId() == m_timerID)
    {
        for (int i = 0; i < m_info.m_repeatTime; ++i)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, 4);
            if (item)
            {
                int remainTime = item->text().toInt();
                remainTime--;
                item->setText(QString::number(remainTime));
            }
        }
    }
}

void TestingWIn::updateTableWidget()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        ui->tableWidget->removeRow(i);
    }

    ui->tableWidget->setRowCount(m_info.m_repeatTime);

    for (int i = 0; i < m_info.m_repeatTime; ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem());

        QString remainTimeString = QString::number((i+1) * m_info.m_testTime);
        QTableWidgetItem * item = new QTableWidgetItem(remainTimeString);
        ui->tableWidget->setItem(i, 4, item);
    }

    m_timerID = startTimer(1000);
}

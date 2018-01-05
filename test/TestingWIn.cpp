#include "TestingWIn.h"
#include "ui_TestingWIn.h"

#include <QTimer>
#include <QDebug>

#include "global.h"

TestingWIn::TestingWIn(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestingWIn)
{
    ui->setupUi(this);

    connect(&thread, &MasterThread::response, this, &TestingWIn::showResponse);
    connect(&thread, &MasterThread::error, this, &TestingWIn::processError);
    connect(&thread, &MasterThread::timeout, this, &TestingWIn::processTimeout);
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
    startTest();
}

void TestingWIn::timerEvent(QTimerEvent *event)
{
    qDebug() << "Timer ID:" << event->timerId();

    if (event->timerId() == m_timerID)
    {
        for (int i = 0; i < m_info.getRepeatTime(); ++i)
        {
            QTableWidgetItem *item = ui->tableWidget->item(i, 4);
            if (item)
            {
                int remainTime = item->text().toInt();
                remainTime--;
                if(remainTime <= 0)
                {
                    item->setText(QString::number(0));
                    continue;
                }
                item->setText(QString::number(remainTime));
            }
        }
    }
}

void TestingWIn::startTest()
{
    QByteArray request;
    request.resize(5);
    request[0] = 0xFE;
    request[1] = 0x03;
    request[2] = info().m_testTime + 0x31;
    request[3] = info().m_repeatTime + 0x31;
    request[4] = 0xFF;

    thread.transaction(GlobalData::instance()->m_comPath,
                       1000 * 60,
                       request);
}

void TestingWIn::showResponse(const QString &s)
{
    qDebug() << __FUNCTION__ << s;
}

void TestingWIn::processError(const QString &s)
{
    qDebug() << __FUNCTION__ << s;
}

void TestingWIn::processTimeout(const QString &s)
{
    qDebug() << __FUNCTION__ << s;

}

void TestingWIn::updateTableWidget()
{
    for (int i = 0; i < ui->tableWidget->rowCount(); ++i)
    {
        ui->tableWidget->removeRow(i);
    }

    ui->tableWidget->setRowCount(m_info.getRepeatTime());

    for (int i = 0; i < m_info.getRepeatTime(); ++i)
    {
        ui->tableWidget->setItem(i, 0, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 1, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 2, new QTableWidgetItem());
        ui->tableWidget->setItem(i, 3, new QTableWidgetItem());

        QString remainTimeString = QString::number((i+1) * m_info.getTestTime());
        qDebug() << remainTimeString << ui->tableWidget->rowCount();
        QTableWidgetItem * item = new QTableWidgetItem(remainTimeString);
        ui->tableWidget->setItem(i, 4, item);
    }

    m_timerID = startTimer(100);
}

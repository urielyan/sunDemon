#include "TestingWIn.h"
#include "ui_TestingWIn.h"

#include <QTimer>
#include <QDebug>

#include "global.h"
#include "Tested.h"

TestingWIn::TestingWIn(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestingWIn)
  , m_dataID(0)
{
    ui->setupUi(this);
    m_title = tr("正在测试");

    connect(&thread, &MasterThread::response, this, &TestingWIn::showResponse);
    connect(&thread, &MasterThread::error, this, &TestingWIn::processError);
    connect(&thread, &MasterThread::timeout, this, &TestingWIn::processTimeout);
}

TestingWIn::~TestingWIn()
{
    qDebug() << __FUNCTION__;
    disconnect(&thread, &MasterThread::response, this, &TestingWIn::showResponse);
    disconnect(&thread, &MasterThread::error, this, &TestingWIn::processError);
    disconnect(&thread, &MasterThread::timeout, this, &TestingWIn::processTimeout);
    //killTimer(m_timerID);
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
    //qDebug() << "Timer ID:" << event->timerId();

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

                    if(i == m_info.getRepeatTime() - 1)
                    {
                        killTimer(m_timerID);
                        Tested *tested = new Tested();
                        emit moveToNextWidget(tested);
                    }
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

void TestingWIn::showResponse(const QByteArray &s)
{
    qDebug() << __FUNCTION__ << s;
#ifdef DEBUG
    QByteArray data;
    data[0] = (char)0xfe;
    data[1] = (char)0x03;
    data[2] = (char)0x31 + (char)0x01;
    data[3] = (char)0x32 + (char)0x02;

    data[4] = (char)0xff;
    s = data;
#else
#endif

    if (s[1] != (char)0x03)
    {
        return;
    }

    int countData = s.mid(2, 2).toInt();//取第二位后的两位为数据
    QTableWidgetItem *item = ui->tableWidget->item(m_dataID, 2);
    m_dataID++;
    if(item)
    {
        item->setText(QString::number(countData));
    }
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

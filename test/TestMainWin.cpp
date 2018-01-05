#include "TestMainWin.h"
#include "ui_testMainWin.h"

#include "includes.h"

#include <QThread>

#include "TestInfo.h"
#include "TestingWIn.h"

TestMainWin::TestMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::testMainWin)
{
    ui->setupUi(this);
    m_title = tr("测试");
}

TestMainWin::~TestMainWin()
{
    delete ui;
}

bool TestMainWin::init()
{
    MAIN_WINDOW->setMessage(tr("检查各种参数是否正确"));
    QThread::sleep(1);
    MAIN_WINDOW->setMessage("");

    return true;
}

void TestMainWin::on_sure_clicked()
{
    TestInfo info;
    info.m_number = ui->number->text();
    info.m_queue = ui->comboBo_queue_2->currentIndex();
    info.m_testTime = ui->comboBox_time->currentText().toInt();
    info.m_repeatTime = ui->comboBox_count->currentText().toInt();
    info.m_standard = ui->comboBox_standard->currentIndex();

    TestingWIn *testingWin = new TestingWIn;
    testingWin->setInfo(info);
    emit moveToNextWidget(testingWin);
}

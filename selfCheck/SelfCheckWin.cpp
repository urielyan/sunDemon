#include "SelfCheckWin.h"
#include "ui_SelfCheckWin.h"

#include "includes.h"

#include <QThread>
#include <QTimer>

#include "SelfCheckErrWin.h"
SelfCheckWin::SelfCheckWin(QWidget *parent)
    : Widget(parent)
    , ui(new Ui::SelfCheckWin)
    , m_isPass(false)
{
    ui->setupUi(this);
    m_title = tr("自检");
    m_isFirstWidget = true;
    QTimer::singleShot(100, this, &SelfCheckWin::init);
}

SelfCheckWin::~SelfCheckWin()
{
    delete ui;
}

bool SelfCheckWin::init()
{
    MAIN_WINDOW->setMessage(tr("正在自检"));
    QThread::sleep(1);//TODO:
    MAIN_WINDOW->setMessage("");

    m_isPass = true;
    if (m_isPass)
    {
        MAIN_WINDOW->setMessage("自检通过");
        QThread::sleep(1);
        MAIN_WINDOW->returnToMainWidget();
    }else
    {
        MAIN_WINDOW->setMessage("自检未通过");
        QThread::sleep(1);
        emit moveToNextWidget(new SelfCheckErrWin);
    }
    MAIN_WINDOW->setMessage("");
    return true;
}

bool SelfCheckWin::isPass() const
{
    return m_isPass;
}

void SelfCheckWin::setIsPass(bool isPass)
{
    m_isPass = isPass;
}

void SelfCheckWin::on_selfButton_clicked()
{
    init();
}

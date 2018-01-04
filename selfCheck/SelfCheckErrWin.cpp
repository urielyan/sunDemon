#include "SelfCheckErrWin.h"
#include "ui_SelfCheckErrWin.h"

#include "includes.h"
SelfCheckErrWin::SelfCheckErrWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::SelfCheckErrWin)
{
    ui->setupUi(this);
    m_title = tr("自检");
    m_isFirstWidget = true;
}

SelfCheckErrWin::~SelfCheckErrWin()
{
    delete ui;
}

void SelfCheckErrWin::on_selffChecckButton_clicked()
{
    MAIN_WINDOW->moveToPreWidget();
}

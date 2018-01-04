#include "CleanMainWin.h"
#include "ui_CleanMainWin.h"

#include "AirClean.h"
#include "ReagentClean.h"
CleanMainWin::CleanMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CleanMainWin)
{
    ui->setupUi(this);
    m_title = tr("清洗");
}

CleanMainWin::~CleanMainWin()
{
    delete ui;
}

void CleanMainWin::on_airClean_clicked()
{
    AirClean * w = new AirClean(this);
    emit moveToNextWidget(w);
}

void CleanMainWin::on_reagentClean_clicked()
{
    ReagentClean * w = new ReagentClean(this);
    emit moveToNextWidget(w);
}

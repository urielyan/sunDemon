#include "includes.h"

#include "QueryMainWin.h"
#include "ui_QueryMainWin.h"

#include <QSqlTableModel>

#include "DataBase.h"
#include "CountData.h"
#include "CalibrateData.h"
#include "TestedData.h"

QueryMainWin::QueryMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::QueryMainWin)
{
    ui->setupUi(this);
    m_title = tr("结果查询");
}

QueryMainWin::~QueryMainWin()
{
    delete ui;
}

void QueryMainWin::on_count_clicked()
{
    emit moveToNextWidget(new CountData);
}

void QueryMainWin::on_calibrate_clicked()
{
    emit moveToNextWidget(new CalibrateData);
}

void QueryMainWin::on_sample_clicked()
{
    emit moveToNextWidget(new TestedData);
}

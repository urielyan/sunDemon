#include "CountData.h"
#include "ui_CountData.h"

CountData::CountData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CountData)
{
    ui->setupUi(this);
    m_title = tr("计数数据查询");
}

CountData::~CountData()
{
    delete ui;
}

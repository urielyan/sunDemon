#include "TestedData.h"
#include "ui_TestedData.h"

TestedData::TestedData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestedData)
{
    ui->setupUi(this);
    m_title = tr("含量测量结果查询");
}

TestedData::~TestedData()
{
    delete ui;
}

#include "CalibrateData.h"
#include "ui_CalibrateData.h"

CalibrateData::CalibrateData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrateData)
{
    ui->setupUi(this);
    m_title = tr("标定结果查询");
}

CalibrateData::~CalibrateData()
{
    delete ui;
}

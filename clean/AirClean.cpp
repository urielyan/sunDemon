#include "AirClean.h"
#include "ui_AirClean.h"

AirClean::AirClean(QWidget *parent) :
    Widget(parent),
    ui(new Ui::AirClean)
{
    ui->setupUi(this);
    m_title = tr("空气清洗");
}

AirClean::~AirClean()
{
    delete ui;
}

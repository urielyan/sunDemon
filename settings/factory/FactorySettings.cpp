#include "FactorySettings.h"
#include "ui_FactorySettings.h"

FactorySettings::FactorySettings(QWidget *parent) :
    Widget(parent),
    ui(new Ui::FactorySettings)
{
    ui->setupUi(this);
    m_title = tr("工厂设置");
}

FactorySettings::~FactorySettings()
{
    delete ui;
}

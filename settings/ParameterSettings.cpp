#include "ParameterSettings.h"
#include "ui_ParameterSettings.h"

#include "SetupDatetime.h"
ParameterSettings::ParameterSettings(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ParameterSettings)
{
    ui->setupUi(this);
    m_title = tr("参数设置");
}

ParameterSettings::~ParameterSettings()
{
    delete ui;
}

void ParameterSettings::on_pushButton_clicked()
{
    emit moveToNextWidget(new SetupDatetime);
}

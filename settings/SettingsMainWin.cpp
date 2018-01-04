#include "SettingsMainWin.h"
#include "ui_SettingsMainWin.h"

#include "ParameterSettings.h"
#include "CalibrationMainWin.h"
SettingsMainWin::SettingsMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::SettingsMainWin)
{
    ui->setupUi(this);
    m_title = tr("设置");
}

SettingsMainWin::~SettingsMainWin()
{
    delete ui;
}

void SettingsMainWin::on_parameterSettings_clicked()
{
    emit moveToNextWidget(new ParameterSettings);
}

void SettingsMainWin::on_calibration_clicked()
{
    emit moveToNextWidget(new CalibrationMainWin);
}

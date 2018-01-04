#include "CalibrationMainWin.h"
#include "ui_CalibrationMainWin.h"

#include "UserCalibration.h"
#include "FactoryCalibration.h"
CalibrationMainWin::CalibrationMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrationMainWin)
{
    ui->setupUi(this);
    m_title = tr("校准");
}

CalibrationMainWin::~CalibrationMainWin()
{
    delete ui;
}

void CalibrationMainWin::on_userCalibration_clicked()
{
    emit moveToNextWidget(new UserCalibration);
}

void CalibrationMainWin::on_factoryCalibration_clicked()
{
    emit moveToNextWidget(new FactoryCalibration);
}

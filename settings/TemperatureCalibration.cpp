#include "TemperatureCalibration.h"
#include "ui_TemperatureCalibration.h"

TemperatureCalibration::TemperatureCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TemperatureCalibration)
{
    ui->setupUi(this);
}

TemperatureCalibration::~TemperatureCalibration()
{
    delete ui;
}

#include "ParameterCalibration.h"
#include "ui_ParameterCalibration.h"

ParameterCalibration::ParameterCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ParameterCalibration)
{
    ui->setupUi(this);
}

ParameterCalibration::~ParameterCalibration()
{
    delete ui;
}

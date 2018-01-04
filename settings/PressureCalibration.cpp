#include "PressureCalibration.h"
#include "ui_PressureCalibration.h"

PressureCalibration::PressureCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::PressureCalibration)
{
    ui->setupUi(this);
}

PressureCalibration::~PressureCalibration()
{
    delete ui;
}

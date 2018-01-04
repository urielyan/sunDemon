#include "MoistureCalibration.h"
#include "ui_MoistureCalibration.h"

MoistureCalibration::MoistureCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::MoistureCalibration)
{
    ui->setupUi(this);
}

MoistureCalibration::~MoistureCalibration()
{
    delete ui;
}

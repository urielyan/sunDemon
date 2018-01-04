#include "ManualControlCalibration.h"
#include "ui_ManualControlCalibration.h"

ManualControlCalibration::ManualControlCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ManualControlCalibration)
{
    ui->setupUi(this);
}

ManualControlCalibration::~ManualControlCalibration()
{
    delete ui;
}

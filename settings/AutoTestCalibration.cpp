#include "AutoTestCalibration.h"
#include "ui_AutoTestCalibration.h"

AutoTestCalibration::AutoTestCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::AutoTestCalibration)
{
    ui->setupUi(this);
}

AutoTestCalibration::~AutoTestCalibration()
{
    delete ui;
}

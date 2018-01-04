#include "FeContentCalibration.h"
#include "ui_FeContentCalibration.h"

FeContentCalibration::FeContentCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::FeContentCalibration)
{
    ui->setupUi(this);
}

FeContentCalibration::~FeContentCalibration()
{
    delete ui;
}

#include "PolluteCalibration.h"
#include "ui_PolluteCalibration.h"

PolluteCalibration::PolluteCalibration(QWidget *parent) :
   Widget(parent),
    ui(new Ui::PolluteCalibration)
{
    ui->setupUi(this);
}

PolluteCalibration::~PolluteCalibration()
{
    delete ui;
}

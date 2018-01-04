#include "ViscosityCcalibration.h"
#include "ui_ViscosityCcalibration.h"

ViscosityCcalibration::ViscosityCcalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ViscosityCcalibration)
{
    ui->setupUi(this);
}

ViscosityCcalibration::~ViscosityCcalibration()
{
    delete ui;
}

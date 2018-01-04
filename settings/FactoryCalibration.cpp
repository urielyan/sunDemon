#include "FactoryCalibration.h"
#include "ui_FactoryCalibration.h"

#include "TemperatureCalibration.h"
#include "PressureCalibration.h"
#include "ManualControlCalibration.h"
#include "AutoTestCalibration.h"
#include "PolluteCalibration.h"
#include "ViscosityCcalibration.h"
#include "FeContentCalibration.h"
#include "MoistureCalibration.h"
#include "ParameterCalibration.h"

FactoryCalibration::FactoryCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::FactoryCalibration)
{
    ui->setupUi(this);
    m_title = tr("工厂校准");
}

FactoryCalibration::~FactoryCalibration()
{
    delete ui;
}

void FactoryCalibration::on_temperature_clicked()
{
    emit moveToNextWidget(new TemperatureCalibration);
}

void FactoryCalibration::on_pressure_clicked()
{
    emit moveToNextWidget(new PressureCalibration);
}

void FactoryCalibration::on_manualControl_clicked()
{
    emit moveToNextWidget(new ManualControlCalibration);
}

void FactoryCalibration::on_autoTest_clicked()
{
    emit moveToNextWidget(new AutoTestCalibration);
}

void FactoryCalibration::on_pollute_clicked()
{
    emit moveToNextWidget(new PolluteCalibration);
}

void FactoryCalibration::on_viscosity_clicked()
{
    emit moveToNextWidget(new ViscosityCcalibration);

}

void FactoryCalibration::on_FeContent_clicked()
{
    emit moveToNextWidget(new FeContentCalibration);
}

void FactoryCalibration::on_moisture_clicked()
{
    emit moveToNextWidget(new MoistureCalibration);
}

void FactoryCalibration::on_parameter_clicked()
{
    emit moveToNextWidget(new ParameterCalibration);
}

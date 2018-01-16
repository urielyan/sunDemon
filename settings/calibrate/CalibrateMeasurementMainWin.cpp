#include "CalibrateMeasurementMainWin.h"
#include "ui_CalibrateMeasurementMainWin.h"

#include "CalibrateMeasurementing.h"
#include "ViewCalibrateData.h"
#include "InputSPercentage.h"
CalibrateMeasurementMainWin::CalibrateMeasurementMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrateMeasurementMainWin)
{
    ui->setupUi(this);
    m_title = tr("标定");
}

CalibrateMeasurementMainWin::~CalibrateMeasurementMainWin()
{
    delete ui;
}

void CalibrateMeasurementMainWin::on_calibrateMeasurement_clicked()
{
    CalibrateMeasurementing *c = new CalibrateMeasurementing;
    emit moveToNextWidget(c);
}

void CalibrateMeasurementMainWin::on_viewCalibratedData_clicked()
{
    ViewCalibrateData *c = new ViewCalibrateData;
    emit moveToNextWidget(c);
}

void CalibrateMeasurementMainWin::on_inputSContent_clicked()
{
    InputSPercentage *c = new InputSPercentage;
    emit moveToNextWidget(c);
}

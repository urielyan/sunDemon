#include "CalibrationMainWin.h"
#include "ui_CalibrationMainWin.h"

#include "CountMeasurementMainWin.h"
#include "SpectrumMeasurementMainWin.h"
#include "CalibrateMeasurementMainWin.h"

CalibrationMainWin::CalibrationMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrationMainWin)
{
    ui->setupUi(this);
    m_title = tr("校准");
}

CalibrationMainWin::~CalibrationMainWin()
{
    delete ui;
}

void CalibrationMainWin::on_countTest_clicked()
{
    emit moveToNextWidget(new CountMeasurementMainWin);
}

void CalibrationMainWin::on_spectrumTest_clicked()
{
    emit moveToNextWidget(new SpectrumMeasurementMainWin);
}

void CalibrationMainWin::on_calibrationTest_clicked()
{
    emit moveToNextWidget(new CalibrateMeasurementMainWin);
}

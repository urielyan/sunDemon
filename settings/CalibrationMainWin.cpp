#include "CalibrationMainWin.h"
#include "ui_CalibrationMainWin.h"

#include "CountMeasurementMainWin.h"
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

}

#include "CalibrateMeasurementMainWin.h"
#include "ui_CalibrateMeasurementMainWin.h"

CalibrateMeasurementMainWin::CalibrateMeasurementMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrateMeasurementMainWin)
{
    ui->setupUi(this);
    m_title = tr("校准");
}

CalibrateMeasurementMainWin::~CalibrateMeasurementMainWin()
{
    delete ui;
}

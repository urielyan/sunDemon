#include "SpectrumMeasurementMainWin.h"
#include "ui_SpectrumMeasurementMainWin.h"

SpectrumMeasurementMainWin::SpectrumMeasurementMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::SpectrumMeasurementMainWin)
{
    ui->setupUi(this);

    m_title = tr("能谱测量");
}

SpectrumMeasurementMainWin::~SpectrumMeasurementMainWin()
{
    delete ui;
}

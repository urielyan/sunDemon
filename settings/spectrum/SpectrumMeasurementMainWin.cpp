#include "SpectrumMeasurementMainWin.h"
#include "ui_SpectrumMeasurementMainWin.h"

#include "SpectrumMeasurementTesting.h"
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

void SpectrumMeasurementMainWin::on_moveToReference_clicked()
{
    //TODO: 移动滑板位置。
    SpectrumMeasurementTesting *c = new SpectrumMeasurementTesting;
    emit moveToNextWidget(c);
}

void SpectrumMeasurementMainWin::on_moveToTest_clicked()
{
    //TODO: 移动滑板位置。
    SpectrumMeasurementTesting *c = new SpectrumMeasurementTesting;
    emit moveToNextWidget(c);
}

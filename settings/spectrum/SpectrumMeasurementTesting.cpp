#include "SpectrumMeasurementTesting.h"
#include "ui_SpectrumMeasurementTesting.h"

SpectrumMeasurementTesting::SpectrumMeasurementTesting(QWidget *parent) :
    Widget(parent),
    ui(new Ui::SpectrumMeasurementTesting)
{
    ui->setupUi(this);
    m_title = tr("正在能谱测量");
}

SpectrumMeasurementTesting::~SpectrumMeasurementTesting()
{
    delete ui;
}

bool SpectrumMeasurementTesting::init()
{

}

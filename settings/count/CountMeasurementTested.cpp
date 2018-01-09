#include "CountMeasurementTested.h"
#include "ui_CountMeasurementTested.h"

CountMeasurementTested::CountMeasurementTested(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CountMeasurementTested)
{
    ui->setupUi(this);
    m_title = tr("计数测量结果");
}

CountMeasurementTested::~CountMeasurementTested()
{
    delete ui;
}

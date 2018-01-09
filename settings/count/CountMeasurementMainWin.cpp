#include "CountMeasurementMainWin.h"
#include "ui_CountMeasurementMainWin.h"

CountMeasurementMainWin::CountMeasurementMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CountMeasurementMainWin)
{
    ui->setupUi(this);
    m_title = tr("计数测量");
}

CountMeasurementMainWin::~CountMeasurementMainWin()
{
    delete ui;
}

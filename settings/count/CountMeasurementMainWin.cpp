#include "CountMeasurementMainWin.h"
#include "ui_CountMeasurementMainWin.h"

#include "CountMeasurementTesting.h"
CountMeasurementMainWin::CountMeasurementMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CountMeasurementMainWin)
{
    ui->setupUi(this);
    m_title = tr("选择计数测量位置");
}

CountMeasurementMainWin::~CountMeasurementMainWin()
{
    delete ui;
}

void CountMeasurementMainWin::on_moveToReference_clicked()
{
    //TODO: 移动滑板位置。
    CountMeasurementTesting *c = new CountMeasurementTesting;
    c->setIsLoop(ui->isLoop->isChecked());
    emit moveToNextWidget(c);
}

void CountMeasurementMainWin::on_moveToTest_clicked()
{
    //TODO: 移动滑板位置。
    CountMeasurementTesting *c = new CountMeasurementTesting;
    c->setIsLoop(ui->isLoop->isChecked());
    emit moveToNextWidget(c);
}

#include "UserCalibration.h"
#include "ui_UserCalibration.h"

UserCalibration::UserCalibration(QWidget *parent) :
    Widget(parent),
    ui(new Ui::UserCalibration)
{
    ui->setupUi(this);
    m_title = tr("用户校准");
}

UserCalibration::~UserCalibration()
{
    delete ui;
}

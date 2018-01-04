#include "TestingWIn.h"
#include "ui_TestingWIn.h"

TestingWIn::TestingWIn(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::TestingWIn)
{
    ui->setupUi(this);
}

TestingWIn::~TestingWIn()
{
    delete ui;
}

#include "Tested.h"
#include "ui_Tested.h"

Tested::Tested(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Tested)
{
    ui->setupUi(this);
}

Tested::~Tested()
{
    delete ui;
}

#include "AlterKBValue.h"
#include "ui_AlterKBValue.h"

AlterKBValue::AlterKBValue(QWidget *parent) :
    Widget(parent),
    ui(new Ui::AlterKBValue)
{
    ui->setupUi(this);
}

AlterKBValue::~AlterKBValue()
{
    delete ui;
}

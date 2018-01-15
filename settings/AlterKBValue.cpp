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

void AlterKBValue::on_sub_clicked()
{
    int index = ui->workQueue->currentIndex();
    if (index == 0)
    {
        return;
    }

    ui->workQueue->setCurrentIndex(--index);
}

void AlterKBValue::on_add_clicked()
{
    int index = ui->workQueue->currentIndex();
    if (index == ui->workQueue->count() - 1)
    {
        return;
    }

    ui->workQueue->setCurrentIndex(++index);
}

void AlterKBValue::on_workQueue_currentIndexChanged(int index)
{
}

#include "ComputeKBValueDoneWidget.h"
#include "ui_ComputeKBValueDoneWidget.h"

ComputeKBValueDoneWidget::ComputeKBValueDoneWidget(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ComputeKBValueDoneWidget)
{
    ui->setupUi(this);
}

ComputeKBValueDoneWidget::~ComputeKBValueDoneWidget()
{
    delete ui;
}

void ComputeKBValueDoneWidget::on_isSave_clicked()
{

}

void ComputeKBValueDoneWidget::on_returnToMainWin_clicked()
{
    emit returnToMainWidget();
}

#include "ComputeKBValueDoneWidget.h"
#include "ui_ComputeKBValueDoneWidget.h"

ComputeKBValueDoneWidget::ComputeKBValueDoneWidget(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ComputeKBValueDoneWidget)
  , m_dateTimeStr("")
{
    ui->setupUi(this);
}

ComputeKBValueDoneWidget::~ComputeKBValueDoneWidget()
{
    delete ui;
}

void ComputeKBValueDoneWidget::setKBR(bool kbrOrA012, float k, float b, float r)
{
    ui->k->setText(QString("%1").arg(k, 4, 'f', 4, '0'));
    ui->b->setText(QString("%1").arg(b, 4, 'f', 4, '0'));
    ui->r->setText(QString("%1").arg(r, 4, 'f', 4, '0'));

    if (kbrOrA012)
    {
        ui->kBuddy->setText("k = ");
        ui->bBuddy->setText("b = ");
        ui->rBuddy->setText("r = ");
    }else
    {
        ui->kBuddy->setText("a0 = ");
        ui->bBuddy->setText("a1 = ");
        ui->rBuddy->setText("a2 = ");
    }
}

void ComputeKBValueDoneWidget::on_isSave_clicked()
{

}

void ComputeKBValueDoneWidget::on_returnToMainWin_clicked()
{
    emit returnToMainWidget();
}

void ComputeKBValueDoneWidget::setDateTimeStr(const QString &dateTimeStr)
{
    m_dateTimeStr = dateTimeStr;
}

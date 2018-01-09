#include "Tested.h"
#include "ui_Tested.h"

Tested::Tested(QWidget *parent) :
    Widget(parent),
    ui(new Ui::Tested)
{
    ui->setupUi(this);
    m_title = tr("测试完成");
    m_isFirstWidget = true;
}

Tested::~Tested()
{
    delete ui;
}

void Tested::on_returnToMainWin_clicked()
{
    emit returnToMainWidget();
}

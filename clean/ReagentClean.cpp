#include "ReagentClean.h"
#include "ui_ReagentClean.h"

ReagentClean::ReagentClean(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ReagentClean)
{
    ui->setupUi(this);
    m_title = tr("试剂清洗");
}

ReagentClean::~ReagentClean()
{
    delete ui;
}

#include "QueryMainWin.h"
#include "ui_QueryMainWin.h"

QueryMainWin::QueryMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::QueryMainWin)
{
    ui->setupUi(this);
}

QueryMainWin::~QueryMainWin()
{
    delete ui;
}

#include "includes.h"

#include "QueryMainWin.h"
#include "ui_QueryMainWin.h"

#include <QSqlTableModel>

#include "DataBase.h"

QueryMainWin::QueryMainWin(QWidget *parent) :
    Widget(parent),
    ui(new Ui::QueryMainWin)
{
    ui->setupUi(this);

    ui->tableView->setModel(MAIN_WINDOW->db()->model());
}

QueryMainWin::~QueryMainWin()
{
    delete ui;
}

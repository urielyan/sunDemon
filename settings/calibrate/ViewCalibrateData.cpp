#include "DataBase.h"
#include "includes.h"

#include "ViewCalibrateData.h"
#include "ui_ViewCalibrateData.h"

#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>

ViewCalibrateData::ViewCalibrateData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::ViewCalibrateData)
{
    ui->setupUi(this);
    m_title = tr("查看标定数据");
}

ViewCalibrateData::~ViewCalibrateData()
{
    delete ui;
}

bool ViewCalibrateData::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    ui->tableView->setModel(db->model("calibrateData"));
    return true;
}

void ViewCalibrateData::on_deleteCalibrateData_clicked()
{
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model)
    {
        DataBaseManager *dbManager = MAIN_WINDOW->db();
        QSqlQuery query(*dbManager->db());
        query.exec("delete FROM calibrateData where 1");
        model->select();
    }
}

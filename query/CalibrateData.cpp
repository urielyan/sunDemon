#include "includes.h"
#include "DataBase.h"

#include "CalibrateData.h"
#include "ui_CalibrateData.h"


#include <QSqlTableModel>
#include <QDebug>

CalibrateData::CalibrateData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrateData)
{
    ui->setupUi(this);
    m_title = tr("标定结果查询");
}

CalibrateData::~CalibrateData()
{
    delete ui;
}

bool CalibrateData::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    ui->tableView->setModel(db->model("calibrateResult"));
    return true;
}

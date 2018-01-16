#include "DataBase.h"
#include "includes.h"

#include "InputSPercentage.h"
#include "ui_InputSPercentage.h"

#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>

InputSPercentage::InputSPercentage(QWidget *parent) :
    Widget(parent),
    ui(new Ui::InputSPercentage)
{
    ui->setupUi(this);
    m_title = tr("输入硫含量");
}

InputSPercentage::~InputSPercentage()
{
    delete ui;
}

bool InputSPercentage::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    ui->tableView->setModel(db->model("calibratePercentage"));
    return true;
}

void InputSPercentage::on_reset_clicked()
{
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model)
    {
        DataBaseManager *dbManager = MAIN_WINDOW->db();
        QSqlQuery query(*dbManager->db());
        query.exec("delete FROM calibratePercentage where 1");
        model->select();
    }
}

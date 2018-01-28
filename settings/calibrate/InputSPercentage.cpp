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
    ui->tableView->setColumnHidden(0, true);
    ui->tableView->sortByColumn(0, Qt::AscendingOrder);
    return true;
}

void InputSPercentage::on_reset_clicked()
{
    QSqlTableModel *model = static_cast<QSqlTableModel*>(ui->tableView->model());
    if (model)
    {
        DataBaseManager *db = MAIN_WINDOW->db();
        QSqlQuery query(*db->db());
        QSqlTableModel *model = db->model("calibratePercentage");
        for (int i = 1;
             i <= model->rowCount();
             ++i)
        {
            query.exec(QString("UPDATE calibratePercentage "
                       "SET percentage = \"0.0000\""
                       " where id = %1").arg(i));
        }
        model->select();
    }
}

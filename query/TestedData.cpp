#include "includes.h"

#include "TestedData.h"
#include "ui_TestedData.h"

#include <QSqlTableModel>
#include <QDebug>

#include "DataBase.h"
#include "TestedDetailsWidget.h"
TestedData::TestedData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestedData)
{
    ui->setupUi(this);
    m_title = tr("含量测量结果查询");
}

TestedData::~TestedData()
{
    delete ui;
}

bool TestedData::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    ui->tableView->setModel(db->model("sample_data"));
    return true;
}

void TestedData::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid())
    {
        return;
    }

    QSqlTableModel *model = MAIN_WINDOW->db()->model("sample_data");
    QSqlRecord record = model->record(index.row());

    TestedDetailsWidget *w = new TestedDetailsWidget;
    w->setRecord(record);
    emit moveToNextWidget(w);
}

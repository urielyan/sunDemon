#include "includes.h"
#include "DataBase.h"

#include "CalibrateData.h"
#include "ui_CalibrateData.h"

#include <QSqlTableModel>
#include <QDebug>

#include "CalibrateResultDetails.h"

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
    ui->tableView->hideColumn(1);
//    ui->tableView->hideColumn(2);
    ui->tableView->setSortingEnabled(true);
    ui->tableView->setAutoScroll(true);
    ui->tableView->resizeColumnsToContents();
    ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    return true;
}

void CalibrateData::on_tableView_doubleClicked(const QModelIndex &index)
{
    int row = index.row();
    QString dateTime = ui->tableView->model()->index(row, 0).data().toString();
    QByteArray data = ui->tableView->model()->index(row, 1).data().toByteArray();
    QString kbr = ui->tableView->model()->index(row, 2).data().toString();

    CalibrateResultDetails *w= new CalibrateResultDetails;
    w->setDateTime(dateTime);
    w->setData(data);
    w->setKBR(kbr);
    emit moveToNextWidget(w);
}

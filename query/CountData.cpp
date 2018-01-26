﻿#include "includes.h"
#include "DataBase.h"

#include "CountData.h"
#include "ui_CountData.h"

#include <QDebug>
#include <QSqlTableModel>
CountData::CountData(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CountData)
{
    ui->setupUi(this);
    m_title = tr("计数数据查询");
}

CountData::~CountData()
{
    delete ui;
}

bool CountData::init()
{
    DataBaseManager *db = MAIN_WINDOW->db();
    ui->tableView->setModel(db->model("countData"));
    return true;
}

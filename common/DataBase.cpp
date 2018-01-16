#include "DataBase.h"

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlTableModel>
#include <QSqlQueryModel>
#include <QSqlRelationalTableModel>
#include <QSqlRecord>
#include <QSqlField>
#include <QTableView>

#include <QDebug>
#include <QSqlError>
#include <QFile>
#include <QMessageBox>
#include <QDateTime>

DataBaseManager::DataBaseManager(QObject *parent)
    : QObject(parent)
    , m_model(NULL)
    , m_db(NULL)
{
    if (!QSqlDatabase::drivers().contains("QSQLITE"))
    {
        QMessageBox::critical(NULL, "Unable to load database",
                              "This software needs the SQLITE driver");
    }
}

DataBaseManager::~DataBaseManager()
{
    if (m_db)
    {
        delete m_db;
        m_db = NULL;
    }
    qDebug() << __FILE__ << __LINE__;
}

bool DataBaseManager::init()
{
    //return false;
    m_db = new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE", m_connectionName));

    m_db->setDatabaseName(m_databaseName);

    if(m_db->open())
    {
        //判断表是否存在，若不存在，则执行建表操作
        if (!m_db->tables().contains(m_tableName))
        {
            QSqlQuery query(*m_db);
            QString createTable = QString(
                        "create table %1 (id integer primary key autoincrement)"
                        ).arg("m_tableName");
            if (!query.exec(createTable))
            {
                return false;
            }
        }
        m_model = new QSqlTableModel(this, *m_db);
        m_model->setTable(m_tableName);
        m_model->select();

        foreach (QString tableName, m_db->tables()) {
                qDebug() << tableName;
                QSqlTableModel *model = new QSqlTableModel(this, *m_db);
                model->setTable(tableName);
                model->select();

                m_models.insert(tableName, model);
        }
        return true;
    }
    else
    {
        qDebug() << m_db->lastError().text() << QFile(m_databaseName).exists();
    }

    return false;
}

QSqlDatabase *DataBaseManager::db() const
{
    return m_db;
}

void DataBaseManager::setDb(QSqlDatabase *db)
{
    m_db = db;
}

QSqlTableModel *DataBaseManager::model() const
{
    return m_model;
}

QSqlTableModel *DataBaseManager::model(QString tableName)
{
    if (m_models.contains(tableName))
    {
        qDebug() << "TODO" << tableName;
        return m_models.value(tableName);
    }
    qDebug() << "TODO" << __FILE__ << __FUNCTION__;
    //TODO: createTable

    return new QSqlTableModel(this);
}

void DataBaseManager::setModel(QSqlTableModel *model)
{
    m_model = model;
}

QString DataBaseManager::tableName() const
{
    return m_tableName;
}

void DataBaseManager::setTableName(const QString &tableName)
{
    m_tableName = tableName;
}

QString DataBaseManager::connectionName() const
{
    return m_connectionName;
}

void DataBaseManager::setConnectionName(const QString &connectionName)
{
    m_connectionName = connectionName;
}

QString DataBaseManager::databaseName() const
{
    return m_databaseName;
}

void DataBaseManager::setDatabaseName(const QString &databaseName)
{
    m_databaseName = databaseName;
}

#ifndef DATABASE_H
#define DATABASE_H

#include <QObject>

class QSqlTableModel;
class QSqlDatabase;
class QSqlQueryModel;
class DataBaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DataBaseManager(QObject *parent = 0);
    ~DataBaseManager();
    bool init();

    QSqlDatabase *db() const;
    void setDb(QSqlDatabase *db);

    QSqlTableModel *model() const;
    void setModel(QSqlTableModel *model);

    QString tableName() const;
    void setTableName(const QString &tableName);

    QString connectionName() const;
    void setConnectionName(const QString &connectionName);

    QString databaseName() const;
    void setDatabaseName(const QString &databaseName);


signals:

public slots:

private:
    QString             m_databaseName;             //!< 数据库的名称，对sqlite来说就是文件名
    QString             m_connectionName;           //!< 数据库的连接名称
    QString             m_tableName;                //!< 数据库的表名称

    QSqlTableModel*      m_model;                    //!< 数据库对应的仿真软件数据model
    QSqlDatabase*       m_db;                       //!< 对应的数据库指针
};

#endif // DATABASE_H

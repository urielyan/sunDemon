#include "DataBase.h"
#include "includes.h"

#include "InputSPercentage.h"
#include "ui_InputSPercentage.h"
#include "VirtualKeyboard.h"

#include <QSqlTableModel>
#include <QDebug>
#include <QSqlQuery>
#include <QVariant>

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

void InputSPercentage::on_tableView_doubleClicked(const QModelIndex &index)
{
    if (!index.isValid())
    {
        return;
    }

    VirtualKeyboard *m_keyBoard = new VirtualKeyboard(this);
    m_keyBoard->setInputMask(".9999");
    m_keyBoard->setInitText(index.data().toString());

    connect(m_keyBoard, &VirtualKeyboard::inputComplete,
            this, &InputSPercentage::setTextAndReturn);
    MAIN_WINDOW->moveToNextWidget(m_keyBoard);

    m_selectedIndex = index;
    //return ui->tableView->doubleClicked(index);
}

void InputSPercentage::setTextAndReturn(QString s)
{
    ui->tableView->model()->setData(m_selectedIndex, s);
    MAIN_WINDOW->moveToPreWidget();
}

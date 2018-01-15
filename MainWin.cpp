#include "MainWin.h"
#include "ui_MianWin.h"

#include "Widget.h"
#include "TestMainWin.h"
#include "MainWidget.h"
#include "SelfCheckWin.h"
#include "DataBase.h"

#include <QStackedLayout>
#include  <QApplication>

MainWin* MainWin::m_instance = NULL;
MainWin::MainWin(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MianWin)
  , m_db(new DataBaseManager)
{
    m_instance = this;

    m_db->setDatabaseName(QApplication::instance()->applicationDirPath() + "/../samplemeasurement.db");
    m_db->setConnectionName("samplemeasurement");
    m_db->setTableName("sample_data");
    m_db->init();

    ui->setupUi(this);

    m_stackedLayout = new QStackedLayout(ui->scrollArea);
    //m_stackedLayout->addWidget(new MainWidget);

    if (selfCheck())
    {
        returnToMainWidget();
    }

    connect(ui->returnButton, &QPushButton::clicked,
            this, &MainWin::moveToPreWidget);
}

MainWin::~MainWin()
{
    delete ui;
}

MainWin *MainWin::instance()
{
    if(m_instance)
    {
        return m_instance;
    }
    return new MainWin;
}

void MainWin::setTitle(QString title)
{
    ui->title->setText(title);
}

void MainWin::setMessage(QString m)
{
    this->statusBar()->showMessage(m);
}

void MainWin::moveToNextWidget(Widget *widget)
{
    ui->scrollArea->setDisabled(true);
    if (!widget->init())
    {
        return;
    }
    ui->scrollArea->setDisabled(false);

    ui->title->setText(widget->title());
    ui->returnButton->setHidden(widget->isFirstWidget());
    m_stackedLayout->addWidget(widget);
    m_stackedLayout->setCurrentWidget(widget);
}

void MainWin::moveToPreWidget()
{
    Widget *widget = static_cast<Widget*>(m_stackedLayout->currentWidget());
    if(!widget)
    {
        return;
    }
    if (m_stackedLayout->count() <= 1)
    {
        ui->title->setText(widget->title());
        ui->returnButton->setHidden(true);
        return;
    }
    m_stackedLayout->removeWidget(widget);
    delete widget;//在栈布局中remove widget时不能自动删除，固需要delete。
    widget = static_cast<Widget*>(m_stackedLayout->currentWidget());
    ui->title->setText(widget->title());
    ui->returnButton->setHidden(widget->isFirstWidget());
    m_stackedLayout->setCurrentWidget(widget);
}

void MainWin::returnToMainWidget()
{
    while (m_stackedLayout->count() > 0)
    {
        m_stackedLayout->removeWidget(m_stackedLayout->widget(0));
    }
    moveToNextWidget(new MainWidget);
}

bool MainWin::selfCheck()
{
    SelfCheckWin *w = new SelfCheckWin;
    ui->title->setText(w->title());
    ui->returnButton->setHidden(w->isFirstWidget());
    m_stackedLayout->addWidget(w);
    m_stackedLayout->setCurrentWidget(w);

    return w->isPass();
}

DataBaseManager *MainWin::db() const
{
    return m_db;
}

void MainWin::setDb(DataBaseManager *db)
{
    m_db = db;
}

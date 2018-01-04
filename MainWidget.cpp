#include "MainWidget.h"
#include "ui_MainWidget.h"

#include "TestMainWin.h"
#include "QueryMainWin.h"
#include "SettingsMainWin.h"
#include "CleanMainWin.h"

MainWidget::MainWidget(QWidget *parent) :
    Widget(parent),
    ui(new Ui::MainWidget)
{
    ui->setupUi(this);
    m_title = tr("油品质量多功能检测仪");
    m_isFirstWidget = true;
}

MainWidget::~MainWidget()
{
    delete ui;
}

void MainWidget::on_testButton_clicked()
{
    TestMainWin * w = new TestMainWin(this);
    emit moveToNextWidget(w);
}

void MainWidget::on_cleanButton_clicked()
{
    CleanMainWin * w = new CleanMainWin(this);
    emit moveToNextWidget(w);
}

void MainWidget::on_queryButton_clicked()
{
    QueryMainWin * w = new QueryMainWin(this);
    emit moveToNextWidget(w);
}

void MainWidget::on_setButton_clicked()
{
    SettingsMainWin * w = new SettingsMainWin(this);
    emit moveToNextWidget(w);
}

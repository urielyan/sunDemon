#include "SpectrumMeasurementTesting.h"
#include "ui_SpectrumMeasurementTesting.h"

#include <QDebug>

SpectrumMeasurementTesting::SpectrumMeasurementTesting(QWidget *parent) :
    MeasurementingWidget(parent),
    ui(new Ui::SpectrumMeasurementTesting)
{
    ui->setupUi(this);
    m_title = tr("正在能谱测量");

    m_count = 40;
    m_seconds = 2;
}

SpectrumMeasurementTesting::~SpectrumMeasurementTesting()
{
    delete ui;
}

bool SpectrumMeasurementTesting::init()
{
    ui->tableWidget->setRowCount(m_count);
    ui->tableWidget->setColumnCount(2);
    ui->tableWidget->setHorizontalHeaderItem(
                0, new QTableWidgetItem(tr("阈值")));
    ui->tableWidget->setHorizontalHeaderItem(
                1, new QTableWidgetItem(tr("计数")));
    for (int i = 0; i < m_count; ++i)
    {
        double threshold = (double)(4 + i) / 10.0;
        qDebug() << threshold;
        QString thresholdString  =  QString("%1").arg(threshold, 1, 'f', 1, '0');
        QTableWidgetItem * item = new QTableWidgetItem(thresholdString);
        ui->tableWidget->setItem(i, 0, item);

        ui->tableWidget->setItem(i, 1, new QTableWidgetItem(threshold));
    }

    return true;
}

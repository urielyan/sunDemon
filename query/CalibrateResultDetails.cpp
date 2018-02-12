#include "CalibrateResultDetails.h"
#include "ui_CalibrateResultDetails.h"

#include <QDebug>

CalibrateResultDetails::CalibrateResultDetails(QWidget *parent) :
    Widget(parent),
    ui(new Ui::CalibrateResultDetails)
{
    ui->setupUi(this);
}

CalibrateResultDetails::~CalibrateResultDetails()
{
    delete ui;
}

void CalibrateResultDetails::setKBR(QString kbr)
{
    ui->kbr->setText(kbr);
}

void CalibrateResultDetails::setDateTime(QString dateTime)
{
    ui->dateTime->setText(dateTime);
}

void CalibrateResultDetails::setData(QByteArray array)
{
    int dataCount = array.size() / sizeof(double);

    qDebug() << dataCount;
    if ( array.isNull() || dataCount % 3 != 0)
    {
        return;
    }
    ui->tableWidget->clear();

    int recordCount = dataCount / 3;

    QDataStream dataStream(&array, QIODevice::ReadOnly);
    ui->tableWidget->setRowCount(recordCount);
    ui->tableWidget->setColumnCount(3);
    for (int i = 0; i < recordCount; ++i)
    {
        double reference = 0;
        double tested = 0;
        double percentage = 0;
        dataStream >> reference >> tested >> percentage;
        QString referenceStr = QString("%1").arg(reference, 4, 'f', 4, '0');
        QString testedStr = QString("%1").arg(tested, 4, 'f', 4, '0');
        QString percentageStr = QString("%1").arg(percentage, 4, 'f', 4, '0');
        ui->tableWidget->setItem( i, 0, new QTableWidgetItem(referenceStr));
        ui->tableWidget->setItem( i, 1, new QTableWidgetItem(testedStr));
        ui->tableWidget->setItem( i, 2, new QTableWidgetItem(percentageStr));
    }
}

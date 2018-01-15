#include "TestedDetailsWidget.h"
#include "ui_TestedDetailsWidget.h"

#include <QHBoxLayout>
#include <QLabel>

TestedDetailsWidget::TestedDetailsWidget(QWidget *parent) :
    Widget(parent),
    ui(new Ui::TestedDetailsWidget)
{
    ui->setupUi(this);
    m_title = tr("含量测量详细信息");
}

TestedDetailsWidget::~TestedDetailsWidget()
{
    delete ui;
}

bool TestedDetailsWidget::init()
{
    if (record.isEmpty())
    {
        return false;
    }

    QVBoxLayout *mainVBoxLayout = new QVBoxLayout(this);

    for (int i= 0; i < record.count(); ++i) {
        QHBoxLayout *aHBoxLayout = new QHBoxLayout(this);
        QLabel *name = new QLabel(record.fieldName(i), this);
        QLabel *value = new QLabel(record.value(i).toString(), this);
        aHBoxLayout->addWidget(name);
        aHBoxLayout->addWidget(value);

        mainVBoxLayout->addLayout(aHBoxLayout);
    }

    return true;
}

QSqlRecord TestedDetailsWidget::getRecord() const
{
    return record;
}

void TestedDetailsWidget::setRecord(const QSqlRecord &value)
{
    record = value;
}

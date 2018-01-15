#ifndef TESTEDDETAILSWIDGET_H
#define TESTEDDETAILSWIDGET_H

#include <QWidget>
#include <Widget.h>
#include <QSqlRecord>

namespace Ui {
class TestedDetailsWidget;
}

class TestedDetailsWidget : public Widget
{
    Q_OBJECT

public:
    explicit TestedDetailsWidget(QWidget *parent = 0);
    ~TestedDetailsWidget();
    virtual bool init();

    QSqlRecord getRecord() const;
    void setRecord(const QSqlRecord &value);

private:
    Ui::TestedDetailsWidget *ui;

    QSqlRecord record;
};

#endif // TESTEDDETAILSWIDGET_H

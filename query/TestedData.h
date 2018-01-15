#ifndef TESTEDDATA_H
#define TESTEDDATA_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class TestedData;
}

class TestedData : public Widget
{
    Q_OBJECT

public:
    explicit TestedData(QWidget *parent = 0);
    ~TestedData();

    virtual bool init();
private slots:
    void on_tableView_doubleClicked(const QModelIndex &index);

private:
    Ui::TestedData *ui;

private:
};

#endif // TESTEDDATA_H

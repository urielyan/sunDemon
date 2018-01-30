#ifndef INPUTSPERCENTAGE_H
#define INPUTSPERCENTAGE_H

#include <QModelIndex>
#include <QWidget>
#include <Widget.h>

namespace Ui {
class InputSPercentage;
}

class InputSPercentage : public Widget
{
    Q_OBJECT

public:
    explicit InputSPercentage(QWidget *parent = 0);
    ~InputSPercentage();

    bool init() Q_DECL_OVERRIDE;

private slots:
    void on_reset_clicked();

    void on_tableView_doubleClicked(const QModelIndex &index);

    void setTextAndReturn(QString s);

private:
    Ui::InputSPercentage *ui;
    QModelIndex m_selectedIndex;
};

#endif // INPUTSPERCENTAGE_H

#ifndef ALTERKBVALUE_H
#define ALTERKBVALUE_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class AlterKBValue;
}

class AlterKBValue : public Widget
{
    Q_OBJECT

public:
    explicit AlterKBValue(QWidget *parent = 0);
    ~AlterKBValue();

private slots:
    void on_sub_clicked();

    void on_add_clicked();

    void on_workQueue_currentIndexChanged(int index);

private:
    Ui::AlterKBValue *ui;
};

#endif // ALTERKBVALUE_H

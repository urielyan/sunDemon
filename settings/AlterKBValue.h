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

private:
    Ui::AlterKBValue *ui;
};

#endif // ALTERKBVALUE_H

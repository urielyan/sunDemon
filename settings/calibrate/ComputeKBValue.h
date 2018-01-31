#ifndef COMPUTEKBVALUE_H
#define COMPUTEKBVALUE_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ComputeKBValue;
}

class ComputeKBValue : public Widget
{
    Q_OBJECT

public:
    explicit ComputeKBValue(QWidget *parent = 0);
    ~ComputeKBValue();
    virtual bool init();

private slots:
    void on_computeKBValue_clicked();

private:
    Ui::ComputeKBValue *ui;
};

#endif // COMPUTEKBVALUE_H

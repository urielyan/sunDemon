#ifndef INPUTSPERCENTAGE_H
#define INPUTSPERCENTAGE_H

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

private:
    Ui::InputSPercentage *ui;
};

#endif // INPUTSPERCENTAGE_H

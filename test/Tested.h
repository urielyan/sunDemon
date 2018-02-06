#ifndef TESTED_H
#define TESTED_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class Tested;
}

class Tested : public Widget
{
    Q_OBJECT

public:
    explicit Tested(QWidget *parent = 0);
    ~Tested();

private slots:
    void on_returnToMainWin_clicked();

    void on_isSave_clicked();

private:
    Ui::Tested *ui;
};

#endif // TESTED_H

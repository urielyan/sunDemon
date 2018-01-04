#ifndef TESTED_H
#define TESTED_H

#include <QWidget>

namespace Ui {
class Tested;
}

class Tested : public QWidget
{
    Q_OBJECT

public:
    explicit Tested(QWidget *parent = 0);
    ~Tested();

private:
    Ui::Tested *ui;
};

#endif // TESTED_H

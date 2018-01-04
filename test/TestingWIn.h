#ifndef TESTINGWIN_H
#define TESTINGWIN_H

#include <QWidget>

namespace Ui {
class TestingWIn;
}

class TestingWIn : public QWidget
{
    Q_OBJECT

public:
    explicit TestingWIn(QWidget *parent = 0);
    ~TestingWIn();

private:
    Ui::TestingWIn *ui;
};

#endif // TESTINGWIN_H

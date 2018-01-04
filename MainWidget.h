#ifndef MAINWIDGET_H
#define MAINWIDGET_H

#include "Widget.h"
#include <QWidget>

namespace Ui {
class MainWidget;
}

class MainWidget : public Widget
{
    Q_OBJECT

public:
    explicit MainWidget(QWidget *parent = 0);
    ~MainWidget();

private slots:
    void on_testButton_clicked();

    void on_cleanButton_clicked();

    void on_queryButton_clicked();

    void on_setButton_clicked();

private:
    Ui::MainWidget *ui;
};

#endif // MAINWIDGET_H

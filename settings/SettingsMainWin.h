#ifndef SETTINGSMAINWIN_H
#define SETTINGSMAINWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class SettingsMainWin;
}

class SettingsMainWin : public Widget
{
    Q_OBJECT

public:
    explicit SettingsMainWin(QWidget *parent = 0);
    ~SettingsMainWin();

private slots:
    void on_parameterSettings_clicked();

    void on_calibration_clicked();

private:
    Ui::SettingsMainWin *ui;
};

#endif // SETTINGSMAINWIN_H

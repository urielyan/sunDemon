#ifndef PARAMETERSETTINGS_H
#define PARAMETERSETTINGS_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ParameterSettings;
}

class ParameterSettings : public Widget
{
    Q_OBJECT

public:
    explicit ParameterSettings(QWidget *parent = 0);
    ~ParameterSettings();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ParameterSettings *ui;
};

#endif // PARAMETERSETTINGS_H

#ifndef FACTORYSETTINGS_H
#define FACTORYSETTINGS_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class FactorySettings;
}

class FactorySettings : public Widget
{
    Q_OBJECT

public:
    explicit FactorySettings(QWidget *parent = 0);
    ~FactorySettings();

private:
    Ui::FactorySettings *ui;
};

#endif // FACTORYSETTINGS_H

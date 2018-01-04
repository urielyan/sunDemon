#ifndef REAGENTCLEAN_H
#define REAGENTCLEAN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ReagentClean;
}

class ReagentClean : public Widget
{
    Q_OBJECT

public:
    explicit ReagentClean(QWidget *parent = 0);
    ~ReagentClean();

private:
    Ui::ReagentClean *ui;
};

#endif // REAGENTCLEAN_H

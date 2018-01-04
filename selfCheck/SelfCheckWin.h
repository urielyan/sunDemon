#ifndef SELFCHECKWIN_H
#define SELFCHECKWIN_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class SelfCheckWin;
}

class SelfCheckWin : public Widget
{
    Q_OBJECT

public:
    explicit SelfCheckWin(QWidget *parent = 0);
    ~SelfCheckWin();

    bool isPass() const;
    void setIsPass(bool isPass);

public slots:
    bool init() Q_DECL_OVERRIDE;

private slots:
    void on_selfButton_clicked();

private:
    Ui::SelfCheckWin *ui;
    bool m_isPass;
};

#endif // SELFCHECKWIN_H

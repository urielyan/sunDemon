#ifndef COMPUTEKBVALUEDONEWIDGET_H
#define COMPUTEKBVALUEDONEWIDGET_H

#include <QWidget>
#include <Widget.h>

namespace Ui {
class ComputeKBValueDoneWidget;
}

class ComputeKBValueDoneWidget : public Widget
{
    Q_OBJECT

public:
    explicit ComputeKBValueDoneWidget(QWidget *parent = 0);
    ~ComputeKBValueDoneWidget();

    void setKBR(bool kbrOrA012, float k, float b, float r);

    void setDateTimeStr(const QString &dateTimeStr);

private slots:
    void on_isSave_clicked();

    void on_returnToMainWin_clicked();

private:
    Ui::ComputeKBValueDoneWidget *ui;
    QString m_dateTimeStr;
};

#endif // COMPUTEKBVALUEDONEWIDGET_H

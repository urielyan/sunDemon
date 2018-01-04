#ifndef SETUPDATETIME_H
#define SETUPDATETIME_H

#include <QWidget>
#include <QButtonGroup>
#include <QList>
#include <QLabel>
#include <Widget.h>

class SetupDatetime : public Widget
{
    Q_OBJECT

public:
    enum ENUM_DATETIME
    {
        YEAR = 0,
        MONTH,
        DAY,
        HOUR,
        MINUTE,
    };
    explicit SetupDatetime(QWidget *parent = 0);
  void show_and_refresh();

private slots:
    void slotSaveButtonClicked();

    void slotButtonUpClicked(int id);
    void slotButtonDownClicked(int id);

private:
    QButtonGroup m_buttonGroupUp, m_buttonGroupDown;
    QList<QLabel*> m_labelList;

    void setLabelCurrentDateTime();
    void examineDayLabelIsRight();
    QString getSetDateTime();
};

class DateTimeFrame : public QFrame
{
    //useless
    Q_OBJECT
public:
    DateTimeFrame(QWidget *parent = 0);
};
#endif // SETUPDATETIME_H

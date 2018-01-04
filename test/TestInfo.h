#ifndef TESTINFO_H
#define TESTINFO_H

#include <QObject>

class TestInfo : public QObject
{
    Q_OBJECT
public:
    explicit TestInfo(QObject *parent = 0);

signals:

public slots:


public:
    QString m_number;
    int m_queue;
    int m_testTime;
    int m_repeatTime;
    int m_standard;
};

#endif // TESTINFO_H

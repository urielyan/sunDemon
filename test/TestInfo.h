#ifndef TESTINFO_H
#define TESTINFO_H

#include <QObject>

class TestInfo : public QObject
{
    Q_OBJECT
public:
    enum TestTime
    {
        Time30,
        Time60,
        Time120,
        Time240,
        Time480
    };

    enum RepeatTime
    {
        Repeat2,
        Repeat3,
        Repeat5,
        Repeat10,
        Repeat50,
    };
    explicit TestInfo(QObject *parent = 0);
    TestInfo(TestInfo &info, QObject *parent = 0);
    bool operator!=(const TestInfo &fileinfo) const;
    TestInfo & operator=(const TestInfo &fileinfo);
    TestInfo & operator=(TestInfo &other);
    bool operator==(const TestInfo &fileinfo) const;


    int getTestTime();
    int getRepeatTime();

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

#include "TestInfo.h"

TestInfo::TestInfo(QObject *parent)
    : QObject(parent)
    , m_number("0123456789")
    , m_queue(0)
    ,  m_testTime(30)
    ,  m_repeatTime(5)
    ,  m_standard(0)
{

}

TestInfo::TestInfo(TestInfo &info, QObject *parent)
{
    m_number = info.m_number;
    m_queue = info.m_queue;
    m_testTime = info.m_testTime;
    m_repeatTime = info.m_repeatTime;
    m_standard = info.m_standard;
}

bool TestInfo::operator!=(const TestInfo &info) const
{
    if (m_number != info.m_number ||
    m_queue != info.m_queue ||
    m_testTime != info.m_testTime ||
    m_repeatTime != info.m_repeatTime ||
    m_standard != info.m_standard
            )
    {
        return false;
    }
}

TestInfo &TestInfo::operator=(const TestInfo &info)
{
    m_number = info.m_number;
    m_queue = info.m_queue;
    m_testTime = info.m_testTime;
    m_repeatTime = info.m_repeatTime;
    m_standard = info.m_standard;
}

TestInfo &TestInfo::operator=(TestInfo &info)
{
    m_number = info.m_number;
    m_queue = info.m_queue;
    m_testTime = info.m_testTime;
    m_repeatTime = info.m_repeatTime;
    m_standard = info.m_standard;
}

bool TestInfo::operator==(const TestInfo &info) const
{
    if (m_number == info.m_number ||
    m_queue == info.m_queue ||
    m_testTime == info.m_testTime ||
    m_repeatTime == info.m_repeatTime ||
    m_standard == info.m_standard
            )
    {
        return false;
    }
}

int TestInfo::getTestTime()
{
    int realTestTime = 0;
    switch (m_testTime) {
    case Time30:
        realTestTime = 30;
        break;
    case Time60:
        realTestTime = 60;
        break;
    case Time120:
        realTestTime = 120;
        break;
    case Time240:
        realTestTime = 240;
        break;
    case Time480:
        realTestTime = 480;
        break;
    default:
        break;
    }

    return realTestTime;
}

int TestInfo::getRepeatTime()
{
    int realRepeatTime = 0;
    switch (m_testTime) {
    case Repeat2:
        realRepeatTime = 2;
        break;
    case Repeat3:
        realRepeatTime = 3;
        break;
    case Repeat5:
        realRepeatTime = 5;
        break;
    case Repeat10:
        realRepeatTime = 10;
        break;
    case Repeat50:
        realRepeatTime = 50;
        break;
    default:
        break;
    }
    return realRepeatTime;
}

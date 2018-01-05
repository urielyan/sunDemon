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

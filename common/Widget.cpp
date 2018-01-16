#include "Widget.h"
#include "includes.h"

#include <QDebug>

Widget::Widget(QWidget *parent)
    : Widget("", false, parent)
{
}

Widget::Widget(QString m_title, bool isFinalWidget, QWidget *parent)
    : QWidget(parent)
    , m_title(m_title)
    , m_isFirstWidget(isFinalWidget)
{
    connect(this, &Widget::moveToNextWidget,
            MAIN_WINDOW, &MainWin::moveToNextWidget);
    connect(this, &Widget::moveToPreWidget,
            MAIN_WINDOW, &MainWin::moveToPreWidget);
    connect(this, &Widget::returnToMainWidget,
            MAIN_WINDOW, &MainWin::returnToMainWidget);
}

Widget::~Widget()
{
    qDebug() << __FUNCTION__;
    disconnect(this, &Widget::moveToNextWidget,
            MAIN_WINDOW, &MainWin::moveToNextWidget);
    disconnect(this, &Widget::moveToPreWidget,
            MAIN_WINDOW, &MainWin::moveToPreWidget);
    disconnect(this, &Widget::returnToMainWidget,
            MAIN_WINDOW, &MainWin::returnToMainWidget);
}

QString Widget::title() const
{
    return m_title;
}

void Widget::setTitle(const QString &title)
{
    m_title = title;
}

bool Widget::isFirstWidget() const
{
    return m_isFirstWidget;
}

void Widget::setIsFirstWidget(bool isFinalWidget)
{
    m_isFirstWidget = isFinalWidget;
}

#include "includes.h"

#include "LineEdit.h"
#include "VirtualKeyboard.h"

#include <QDebug>

LineEdit::LineEdit(QWidget *parent)
    : QLineEdit(parent)
{
    setMaxLength(8);
}

void LineEdit::setTextAndReturn(QString s)
{
    qDebug() << s;
    this->setText(QString::number(s.toFloat()));
    MAIN_WINDOW->moveToPreWidget();
}

void LineEdit::mousePressEvent(QMouseEvent *e)
{
    Q_UNUSED(e);
    VirtualKeyboard *m_keyBoard = new VirtualKeyboard(this);
    m_keyBoard->setInputMask(this->inputMask());
    m_keyBoard->setInitText(text());
    connect(m_keyBoard, &VirtualKeyboard::inputComplete,
            this, &LineEdit::setTextAndReturn);
    MAIN_WINDOW->moveToNextWidget(m_keyBoard);
}

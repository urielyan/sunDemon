#include "Button.h"

#include <QMouseEvent>

Button::Button(QWidget *parent)
    : QPushButton(parent)
{
    //保存图片成员初始化
    buttonPicture = new QPixmap();
    pressPicture = new QPixmap();
    releasePicture = new QPixmap();

    //关闭按钮的默认显示
    this -> setFlat(true);
}

void Button::setButtonPicture(QPixmap pic)
{
    *buttonPicture = pic;

    this -> setIcon(QIcon(*buttonPicture));
}

void Button::setPressPicture(QPixmap pic)
{
    *pressPicture = pic;
}

void Button::setReleasePicture(QPixmap pic)
{
    *releasePicture	= pic;
}

void Button::setXYWidthHeight(int x, int y, int width, int height)
{
    this -> setIconSize(QSize(width, height));
    this -> setGeometry(x, y, width, height);
}

void Button::mouseDoubleClickEvent(QMouseEvent *event)
{
    //TODO
    return QPushButton::mouseDoubleClickEvent(event);
}

void Button::mousePressEvent (QMouseEvent *event)
{
    this -> setIcon (QIcon(*pressPicture));
    return QPushButton::mousePressEvent(event);
}

void Button::mouseMoveEvent(QMouseEvent *event)
{
    //TODO
    return QPushButton::mouseMoveEvent(event);
}


void Button::mouseReleaseEvent (QMouseEvent *event)
{
    this -> setIcon(QIcon(*releasePicture));
    //emit clicked();
    return QPushButton::mouseReleaseEvent(event);

}

#ifndef BUTTON_H
#define BUTTON_H

#include <QPushButton>

class Button : public QPushButton
{
    Q_OBJECT
public:
    explicit Button(QWidget *parent = 0);

    void setButtonPicture(QPixmap pic);
    void setPressPicture(QPixmap pic);
    void setReleasePicture(QPixmap pic);
    void setXYWidthHeight(int x, int y, int width, int height);
signals:

public slots:



protected slots:
    void mouseDoubleClickEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseMoveEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);

private:
    QPixmap *buttonPicture;
    QPixmap *pressPicture;
    QPixmap *releasePicture;
};

#endif // BUTTON_H

#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QDialog>
#include <Widget.h>

namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public Widget
{
    Q_OBJECT

public:
    explicit VirtualKeyboard(QWidget *parent = 0);
    ~VirtualKeyboard();

    QString getStr();

    void setInputMask(QString inputMask);
    void setInitText(QString str);
Q_SIGNALS:
    void inputComplete(QString str);

private slots:
    void buttonsClicked();
    void on_backspace_clicked();

    void on_clear_clicked();

    void on_ok_clicked();

    void on_point_clicked();

private:
    Ui::VirtualKeyboard *ui;
};

#endif // VIRTUALKEYBOARD_H

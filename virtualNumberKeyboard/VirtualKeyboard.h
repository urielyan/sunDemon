#ifndef VIRTUALKEYBOARD_H
#define VIRTUALKEYBOARD_H

#include <QDialog>

namespace Ui {
class VirtualKeyboard;
}

class VirtualKeyboard : public QDialog
{
    Q_OBJECT

public:
    explicit VirtualKeyboard(QWidget *parent = 0);
    ~VirtualKeyboard();

private:
    Ui::VirtualKeyboard *ui;
};

#endif // VIRTUALKEYBOARD_H

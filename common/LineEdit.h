#ifndef LINEEDIT_H
#define LINEEDIT_H

#include <QLineEdit>
#include <QWidget>

class VirtualKeyboard;
class LineEdit : public QLineEdit
{
    Q_OBJECT
public:
    explicit LineEdit(QWidget *parent = 0);

signals:

public slots:
    void setTextAndReturn(QString s);
protected:
    void mousePressEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
};

#endif // LINEEDIT_H

#ifndef MIANWIN_H
#define MIANWIN_H

#include <QMainWindow>

namespace Ui {
class MianWin;
}

class QStackedLayout;
class Widget;
class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();
    static MainWin* instance();
    void setTitle(QString title);
    void setMessage(QString m);

public slots:
    void moveToNextWidget(Widget *widget);
    void moveToPreWidget();
    void returnToMainWidget();
private:
    bool selfCheck();
private:
    Ui::MianWin *ui;
    QStackedLayout *m_stackedLayout;
    static MainWin* m_instance;
};

#endif // MIANWIN_H

#ifndef MIANWIN_H
#define MIANWIN_H

#include <QMainWindow>

namespace Ui {
class MianWin;
}

class QStackedLayout;
class Widget;
class DataBaseManager;
class MainWin : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWin(QWidget *parent = 0);
    ~MainWin();
    static MainWin* instance();
    void setTitle(QString title);
    void setMessage(QString m);

    DataBaseManager *db() const;
    void setDb(DataBaseManager *db);

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
    DataBaseManager *m_db;
};

#endif // MIANWIN_H

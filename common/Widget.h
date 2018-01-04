#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>

class Widget : public QWidget
{
    Q_OBJECT
public:
    explicit Widget(QWidget *parent = 0);
    explicit Widget(QString m_title = "", bool m_isFirstWidget = false, QWidget *parent = 0);

    virtual bool init()
    {
        return true;
    }

    QString title() const;
    void setTitle(const QString &title);

    bool isFirstWidget() const;
    void setIsFirstWidget(bool isFirstWidget);

signals:
    void moveToNextWidget(Widget *w);
    void moveToPreWidget();
    void returnToMainWidget();

public slots:

protected:
    QString m_title;
    bool m_isFirstWidget;
};

#endif // WIDGET_H

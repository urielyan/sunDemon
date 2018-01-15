#include "MainWin.h"
#include <QApplication>


#include <QFile>
#include <QDebug>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin w;
    w.setFixedSize(400, 320);
    w.show();

    QFile file(":/qss/main.qss");
    if (file.open(QIODevice::ReadOnly | QIODevice::Text))
    {
        QString str = file.readAll();
        qDebug() << str;
        a.setStyleSheet(str);
    }


    qDebug() << a.applicationDirPath();
    return a.exec();
}

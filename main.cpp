#include "MainWin.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWin w;
    w.setFixedSize(400, 320);
    w.show();

    return a.exec();
}

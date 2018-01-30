QT += sql

INCLUDEPATH += $$PWD

SOURCES +=  $$PWD/Widget.cpp \
    $$PWD/global.cpp \
    $$PWD/wininforlistdialog.cpp \
    $$PWD/Button.cpp \
    $$PWD/DataBase.cpp \
    $$PWD/MainWin.cpp \
    $$PWD/LineEdit.cpp

HEADERS  +=  $$PWD/Widget.h \
    $$PWD/includes.h \
    $$PWD/global.h \
    $$PWD/wininforlistdialog.h \
    $$PWD/Button.h \
    $$PWD/DataBase.h \
    $$PWD/MainWin.h \
    $$PWD/LineEdit.h

FORMS += \
    $$PWD/MianWin.ui

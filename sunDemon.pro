#-------------------------------------------------
#
# Project created by QtCreator 2017-12-30T12:21:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sunDemon
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

include (common/common.pri)
include (test/test.pri)
include (query/query.pri)
include (settings/settings.pri)
include (clean/clean.pri)serialport
include (selfCheck/selfCheck.pri)
include (serialport/serialport.pri)
include (db/db.pri)

SOURCES += main.cpp\
    MainWidget.cpp \
    MainWin.cpp \
    MeasurementingWidget.cpp

HEADERS  += \
    MainWidget.h \
    MainWin.h \
    MeasurementingWidget.h

FORMS    += MianWin.ui \
    MainWidget.ui


#将文件拷贝到输出目录中。在qmake之后会执行命令。
    src_file = $$PWD/db/samplemeasurement.db
    dst_file = $$OUT_PWD/samplemeasurement.db

win32 {
    src_file ~= s,/,\\,g
    dst_file ~= s,/,\\,g
    system(copy /y $$src_file $$dst_file)
}
unix {
    system(cp -r -f $$src_file $$dst_file)
}

RESOURCES += \
    src.qrc

INCLUDEPATH += $$PWD $$PWD/count $$PWD/factory

SOURCES += $$PWD/SettingsMainWin.cpp \
    $$PWD/ParameterSettings.cpp \
    $$PWD/SetupDatetime.cpp \
    $$PWD/CalibrationMainWin.cpp \
    $$PWD/count/CountMeasurementMainWin.cpp \
    $$PWD/count/CountMeasurementTesting.cpp \
    $$PWD/count/CountMeasurementTested.cpp \
    $$PWD/factory/FactorySettings.cpp

HEADERS  += $$PWD/SettingsMainWin.h \
    $$PWD/ParameterSettings.h \
    $$PWD/SetupDatetime.h \
    $$PWD/CalibrationMainWin.h \
    $$PWD/count/CountMeasurementMainWin.h \
    $$PWD/count/CountMeasurementTesting.h \
    $$PWD/count/CountMeasurementTested.h \
    $$PWD/factory/FactorySettings.h

FORMS    += $$PWD/SettingsMainWin.ui \
    $$PWD/ParameterSettings.ui \
    $$PWD/SetupDatetime.ui \
    $$PWD/CalibrationMainWin.ui \
    $$PWD/count/CountMeasurementMainWin.ui \
    $$PWD/count/CountMeasurementTesting.ui \
    $$PWD/count/CountMeasurementTested.ui \
    $$PWD/factory/FactorySettings.ui

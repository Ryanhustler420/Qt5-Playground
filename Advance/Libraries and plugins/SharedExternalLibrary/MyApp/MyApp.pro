QT -= gui

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        main.cpp

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../build-MyExternalLib-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/release/ -lMyExternalLib
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../build-MyExternalLib-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/debug/ -lMyExternalLib
else:unix: LIBS += -L$$PWD/../build-MyExternalLib-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/ -lMyExternalLib

INCLUDEPATH += $$PWD/../build-MyExternalLib-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/debug
DEPENDPATH += $$PWD/../build-MyExternalLib-Desktop_Qt_5_12_12_MinGW_64_bit-Debug/debug

HEADERS += \
    MyExternalLib_global.h \
    myexternallib.h

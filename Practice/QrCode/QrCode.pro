QT += quick

CONFIG += c++11
CONFIG += qzxing_qml
CONFIG += qzxing_multimedia
CONFIG += enable_encoder_qr_code

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        imageitem.cpp \
        main.cpp \
        qrclazz.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

#include(".\libs\qzxing\src\QZXing-components.pri")
include(".\libs\qzxing\src\QZXing.pri")

HEADERS += \
    imageitem.h \
    qrclazz.h

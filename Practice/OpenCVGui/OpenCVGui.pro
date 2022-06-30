QT += quick core network sql concurrent networkauth

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        application.cpp \
        main.cpp

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32:CONFIG(release, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world460
else:win32:CONFIG(debug, debug|release): LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world460d
else:unix: LIBS += -LC:/opencv/build/x64/vc15/lib/ -lopencv_world460

INCLUDEPATH += C:/opencv/build/include
DEPENDPATH += C:/opencv/build/include

LIBS += C:/opencv-build/bin/libopencv_core460.dll
LIBS += C:/opencv-build/bin/libopencv_highgui460.dll
LIBS += C:/opencv-build/bin/libopencv_imgcodecs460.dll
LIBS += C:/opencv-build/bin/libopencv_imgproc460.dll
LIBS += C:/opencv-build/bin/libopencv_features2d460.dll
LIBS += C:/opencv-build/bin/libopencv_calib3d460.dll

HEADERS += \
    application.h

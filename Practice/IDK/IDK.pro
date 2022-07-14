QT -= gui
QT += concurrent # network networkauth

CONFIG += c++11 console
CONFIG -= app_bundle

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        utility/filesystembroadcaster.cpp \
        parents/commonsuperclass.cpp \
        utility/filesystem.cpp \
        utility/jsonhelper.cpp \
        utility/helpers.cpp \
        utility/threads.cpp \
        utility/timer.cpp \
        utility/os.cpp \
        main.cpp \

HEADERS += \
        utility/filesystembroadcaster.h \
        parents/commonsuperclass.h \
        utility/filesystem.h \
        utility/jsonhelper.h \
        utility/helpers.h \
        utility/threads.h \
        utility/timer.h \
        utility/os.h \

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

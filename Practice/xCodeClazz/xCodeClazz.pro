QT += quick core network sql concurrent networkauth

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        controllers\allstudentspagecontroller.cpp \
        controllers\singlecoursepagecontroller.cpp \
        controllers\allcoursespagecontroller.cpp \
        controllers\allrequestcallbackspage.cpp \
        controllers\dashboardpagecontroller.cpp \
        controllers\loginpagecontroller.cpp \
    database/localcache.cpp \
    database/sqlite3.cpp \
        models\god\modelconventions.cpp \
    networking/apis.cpp \
    networking/network.cpp \
    networking/routes.cpp \
        parents\commonsuperclass.cpp \
        application\manager.cpp \
    utility/filesystem.cpp \
    utility/filesystembroadcaster.cpp \
    utility/helpers.cpp \
    utility/os.cpp \
    utility/threads.cpp \
    utility/timer.cpp \
        utility\jsonhelper.cpp \
        models\course.cpp \
        models\session.cpp \
        ipc\databridge.cpp \
        application.cpp \
        rx\signals.cpp \
        main.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    controllers\singlecoursepagecontroller.h \
    controllers\allstudentspagecontroller.h \
    controllers\allcoursespagecontroller.h \
    controllers\allrequestcallbackspage.h \
    controllers\dashboardpagecontroller.h \
    controllers\loginpagecontroller.h \
    database/localcache.h \
    database/sqlite3.h \
    models\god\modelconventions.h \
    networking/apis.h \
    networking/network.h \
    networking/routes.h \
    parents\commonsuperclass.h \
    shareable/constants.h \
    singleton\singleton_obj.h \
    application\manager.h \
    utility/CursorPosProvider.h \
    utility/filesystem.h \
    utility/filesystembroadcaster.h \
    utility/helpers.h \
    utility/os.h \
    utility/threads.h \
    utility/timer.h \
    utility\jsonhelper.h \
    ipc\databridge.h \
    models\session.h \
    models\course.h \
    application.h \
    rx\signals.h \

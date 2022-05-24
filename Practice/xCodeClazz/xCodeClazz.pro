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
    utility/xcodeclazzdb.cpp \
    utility/xdb.cpp \
        utility\filesystembroadcaster.cpp \
        models\god\modelconventions.cpp \
        parents\commonsuperclass.cpp \
        database\localcache.cpp \
        application\manager.cpp \
        utility\filesystem.cpp \
        networking\network.cpp \
        utility\jsonhelper.cpp \
        networking\routes.cpp \
        database\musicdb.cpp \
        database\sqlite3.cpp \
        utility\helpers.cpp \
        networking\apis.cpp \
        utility\threads.cpp \
        models\session.cpp \
        ipc\databridge.cpp \
        utility\timer.cpp \
        models\course.cpp \
        application.cpp \
        rx\signals.cpp \
        utility\os.cpp \
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
    database\localcache.h \
    database\musicdb.h \
    database\sqlite3.h \
    models\god\modelconventions.h \
    networking\apis.h \
    networking\network.h \
    networking\routes.h \
    parents\commonsuperclass.h \
    shareable\constants.h \
    singleton\singleton_obj.h \
    application\manager.h \
    utility/xcodeclazzdb.h \
    utility/xdb.h \
    utility\CursorPosProvider.h \
    utility\filesystem.h \
    utility\filesystembroadcaster.h \
    utility\helpers.h \
    utility\os.h \
    utility\threads.h \
    utility\timer.h \
    utility\jsonhelper.h \
    ipc\databridge.h \
    models\session.h \
    models\course.h \
    application.h \
    rx\signals.h \

QT       += core gui network sql concurrent

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    utility\os.cpp \
    views\widget.cpp \
    models\spider.cpp \
    models\jocker.cpp \
    utility\timer.cpp \
    utility\threads.cpp \
    utility\helpers.cpp \
    networking\apis.cpp \
    database\sqlite3.cpp \
    networking\routes.cpp \
    utility\filesystem.cpp \
    networking\network.cpp \
    utility\jsonhelper.cpp \
    application\manager.cpp \
    database\localcache.cpp \
    utility\hotkeyhandler.cpp \
    parents\commonsuperclass.cpp \
    serializers\serializejson.cpp \
    serializers\serializeclass.cpp \
    serializers\serializeqobject.cpp \
    utility\filesystembroadcaster.cpp \

HEADERS += \
    utility\os.h \
    views\widget.h \
    models\spider.h \
    models\jocker.h \
    utility\timer.h \
    utility\threads.h \
    utility\helpers.h \
    networking\apis.h \
    database\sqlite3.h \
    networking\routes.h \
    utility\filesystem.h \
    networking\network.h \
    utility\jsonhelper.h \
    application\manager.h \
    database\localcache.h \
    singleton\call_once.h \
    singleton\singleton.h \
    utility\hotkeyhandler.h \
    parents\commonsuperclass.h \
    serializers\serializejson.h \
    serializers\serializeclass.h \
    serializers\serializeqobject.h \
    utility\filesystembroadcaster.h \

FORMS += \
    views\widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

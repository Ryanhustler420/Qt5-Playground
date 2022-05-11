QT       += core gui network sql concurrent networkauth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    rx\signals.cpp \
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
    models\plans\plan.cpp \
    oauths\googleoauth.cpp \
    utility\filesystem.cpp \
    networking\network.cpp \
    utility\jsonhelper.cpp \
    application\manager.cpp \
    database\localcache.cpp \
    models\country\state.cpp \
    utility\hotkeyhandler.cpp \
    models\plans\endpoint.cpp \
    models\country\country.cpp \
    parents\commonsuperclass.cpp \
    serializers\serializejson.cpp \
    serializers\serializeclass.cpp \
    models\god\modelconventions.cpp \
    serializers\serializeqobject.cpp \
    utility\filesystembroadcaster.cpp \
    models\contribution\contribution.cpp \
    models\notifications\notification.cpp \
    models\notifications\notificationmetadata.cpp \
    models\contribution\eachcontributedproduct.cpp \

HEADERS += \
    rx\signals.h \
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
    models\plans\plan.h \
    utility\filesystem.h \
    oauths\googleoauth.h \
    networking\network.h \
    utility\jsonhelper.h \
    shareable\constants.h \
    application\manager.h \
    database\localcache.h \
    models\country\state.h \
    utility\hotkeyhandler.h \
    models\plans\endpoint.h \
    models\country\country.h \
    singleton\singleton_obj.h \
    parents\commonsuperclass.h \
    serializers\serializejson.h \
    singleton\singleton_widget.h \
    serializers\serializeclass.h \
    models\god\modelconventions.h \
    serializers\serializeqobject.h \
    utility\filesystembroadcaster.h \
    models\contribution\contribution.h \
    models\notifications\notification.h \
    models\notifications\notificationmetadata.h \
    models\contribution\eachcontributedproduct.h

FORMS += \
    views\widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    oauth.qrc

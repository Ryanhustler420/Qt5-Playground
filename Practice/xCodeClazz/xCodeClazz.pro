QT += quick core network sql concurrent networkauth

CONFIG += c++11

DEFINES += HTTPSERVER_LIBRARY

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    controllers/allstudentspagecontroller.cpp \
    controllers/singlecoursepagecontroller.cpp \
    controllers/allcoursespagecontroller.cpp \
    controllers/allrequestcallbackspage.cpp \
    controllers/dashboardpagecontroller.cpp \
    controllers/loginpagecontroller.cpp \
    models/callbackrequest.cpp \
    models/fee.cpp \
    models/payment.cpp \
    models/student.cpp \
    models/timeslot.cpp \
    utility/filesystembroadcaster.cpp \
    models/god/modelconventions.cpp \
    parents/commonsuperclass.cpp \
    utility/mongoservice.cpp \
    utility/xcodeclazzdb.cpp \
    database/localcache.cpp \
    application/manager.cpp \
    utility/filesystem.cpp \
    networking/network.cpp \
    utility/jsonhelper.cpp \
    oauth/googleoauth.cpp \
    networking/routes.cpp \
    database/musicdb.cpp \
    database/sqlite3.cpp \
    utility/helpers.cpp \
    networking/apis.cpp \
    utility/threads.cpp \
    models/session.cpp \
    utility/timer.cpp \
    models/course.cpp \
    utility/xdb.cpp \
    application.cpp \
    rx/signals.cpp \
    utility/os.cpp \
    main.cpp \
    server/source/util.cpp \
    server/source/httpData.cpp \
    server/source/httpServer.cpp \
    server/source/httpRequest.cpp \
    server/source/httpResponse.cpp \
    server/source/httpConnection.cpp \
    server/routes/requestHandler.cpp \
    server/source/httpRequestRouter.cpp \
    server/middleware/verifyJson.cpp \
    server/middleware/getObject.cpp \
    server/middleware/getArray.cpp \
    server/middleware/CORS.cpp \
    server/middleware/auth.cpp \
    server/server.cpp \

RESOURCES += qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Additional import path used to resolve QML modules just for Qt Quick Designer
QML_DESIGNER_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include( ./libs/qtpromise/qtpromise.pri )

# win32: LIBS += -lzlib
win32: LIBS += -lz
unix: LIBS += -lz

HEADERS += \
    controllers/singlecoursepagecontroller.h \
    controllers/allstudentspagecontroller.h \
    controllers/allcoursespagecontroller.h \
    controllers/allrequestcallbackspage.h \
    controllers/dashboardpagecontroller.h \
    controllers/loginpagecontroller.h \
    models/callbackrequest.h \
    models/fee.h \
    models/payment.h \
    models/student.h \
    models/timeslot.h \
    utility/filesystembroadcaster.h \
    models/god/modelconventions.h \
    parents/commonsuperclass.h \
    singleton/singleton_obj.h \
    utility/mongoservice.h \
    utility/xcodeclazzdb.h \
    database/localcache.h \
    shareable/constants.h \
    application/manager.h \
    networking/network.h \
    utility/filesystem.h \
    utility/jsonhelper.h \
    networking/routes.h \
    oauth/googleoauth.h \
    database/musicdb.h \
    database/sqlite3.h \
    networking/apis.h \
    utility/helpers.h \
    utility/threads.h \
    models/session.h \
    utility/timer.h \
    models/course.h \
    utility/xdb.h \
    application.h \
    utility/os.h \
    rx/signals.h \
    server/source/util.h \
    server/source/const.h \
    server/source/httpConnection.h \
    server/source/httpRequestRouter.h \
    server/source/httpRequestHandler.h \
    server/source/httpServerConfig.h \
    server/source/httpResponse.h \
    server/source/httpRequest.h \
    server/source/httpServer.h \
    server/source/httpData.h \
    server/source/httpCookie.h \
    server/routes/requestHandler.h \
    server/middleware/middleware.h \
    server/server.h \

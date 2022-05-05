QT += core gui network concurrent networkauth

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

DEFINES += HTTPSERVER_LIBRARY

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
# DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
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

SOURCES += \
    main.cpp \
    views/mainwindow.cpp \

HEADERS += \
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

HEADERS += \
    views/mainwindow.h \

FORMS += \
    views\mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

include( ./libs/qtpromise/qtpromise.pri )

# win32: LIBS += -lzlib
win32: LIBS += -lz
unix: LIBS += -lz

# Copy data folder to build directory
#win32 {
#        copydata.commands = $(COPY_DIR) $$shell_path($$PWD/data) $$shell_path($$OUT_PWD/data)
#        first.depends = $(first) copydata
#        export(first.depends)
#        export(copydata.commands)
#        QMAKE_EXTRA_TARGETS += first copydata
#}

#unix {
#        CONFIG(debug, debug|release) {
#                mkpath($$PWD/debug)

#                DESTDIR = $$PWD/debug
#                OBJECTS_DIR = $$PWD/debug
#        }

#        CONFIG(release, debug|release) {
#                mkpath($$PWD/release)

#                DESTDIR = $$PWD/release
#                OBJECTS_DIR = $$PWD/release
#        }
#}

# Link to httpServer library
#INCLUDEPATH += $$PWD/../src
#DEPENDPATH += $$PWD/../src

#CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../src/release/ -lhttpServer
#CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../src/debug/ -lhttpServer

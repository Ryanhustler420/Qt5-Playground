QT += quick

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
        application/manager.cpp \
        controllers/allcoursespagecontroller.cpp \
        controllers/allrequestcallbackspage.cpp \
        controllers/allstudentspagecontroller.cpp \
        controllers/dashboardpagecontroller.cpp \
        controllers/loginpagecontroller.cpp \
        controllers/singlecoursepagecontroller.cpp \
        application.cpp \
        ipc/databridge.cpp \
        main.cpp \
        models/course.cpp \
        models/god/modelconventions.cpp \
        models/session.cpp \
        parents/commonsuperclass.cpp \
        rx/signals.cpp \
        utility/jsonhelper.cpp

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
    application/manager.h \
    controllers/allcoursespagecontroller.h \
    controllers/allrequestcallbackspage.h \
    controllers/allstudentspagecontroller.h \
    controllers/dashboardpagecontroller.h \
    controllers/loginpagecontroller.h \
    controllers/singlecoursepagecontroller.h \
    application.h \
    ipc/databridge.h \
    models/course.h \
    models/god/modelconventions.h \
    models/session.h \
    parents/commonsuperclass.h \
    rx/signals.h \
    singleton/singleton_obj.h \
    utility/jsonhelper.h

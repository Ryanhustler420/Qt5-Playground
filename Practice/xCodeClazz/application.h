#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "utility/CursorPosProvider.h"

#include "controllers/loginpagecontroller.h"
#include "controllers/dashboardpagecontroller.h"
#include "controllers/allrequestcallbackspage.h"
#include "controllers/allcoursespagecontroller.h"
#include "controllers/allstudentspagecontroller.h"
#include "controllers/singlecoursepagecontroller.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
    void boot(QGuiApplication &app);

public:
    Q_INVOKABLE QString getApplicationPath() { return "qrc:/application.qml"; };
    Q_INVOKABLE QString getLoginPagePath() { return "qrc:/pages/login_page.qml"; };
    Q_INVOKABLE QString getDashboardPath() { return "qrc:/pages/dashboard_page.qml"; };
    Q_INVOKABLE QString getCoursesPagePath() { return "qrc:/pages/all_courses_page.qml"; }
    Q_INVOKABLE QString getRequestCallbacksPagePath() { return "qrc:/pages/all_request_callbacks_page.qml"; }
    Q_INVOKABLE QString getStudentsPagePath() { return "qrc:/pages/all_students_page.qml"; }
    Q_INVOKABLE QString getSingleCoursePagePath() { return "qrc:/pages/single_course_page.qml"; }

signals:
    void clearedStack();
    void pushPage(QString qrc);
    void pageReplaced(QString qrc);
    void poped();

public slots:
    void clearStack();
    void gotoPage(QString qrc);
    void replacePage(QString qrc);
    void pop();

private:
    QQmlApplicationEngine engine;
};

#endif // APPLICATION_H

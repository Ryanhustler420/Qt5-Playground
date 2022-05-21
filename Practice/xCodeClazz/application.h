#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Controllers/loginpagecontroller.h"
#include "Controllers/dashboardpagecontroller.h"
#include "Controllers/allrequestcallbackspage.h"
#include "Controllers/allcoursespagecontroller.h"
#include "Controllers/allstudentspagecontroller.h"
#include "Controllers/singlecoursepagecontroller.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
    void boot(QGuiApplication &app);

public:
    Q_INVOKABLE QString getLoginPagePath() { return "qrc:/pages/login_page.qml"; };
    Q_INVOKABLE QString getApplicationPath() { return "qrc:/pages/application.qml"; };
    Q_INVOKABLE QString getDashboardPath() { return "qrc:/pages/dashboard_page.qml"; };
    Q_INVOKABLE QString getCoursesPagePath() { return "qrc:/pages/all_courses_page.qml"; }
    Q_INVOKABLE QString getRequestCallbacksPagePath() { return "qrc:/pages/all_request_callbacks_page.qml"; }
    Q_INVOKABLE QString getStudentsPagePath() { return "qrc:/pages/all_students_page.qml"; }
    Q_INVOKABLE QString getSingleCoursePagePath() { return "qrc:/pages/single_course_page.qml"; }

signals:
    void clearedStack();
    void pushPage(QString qrc);
    void pageReplaced(QString qrc);

public slots:
    void clearStack();
    void gotoPage(QString qrc);
    void replacePage(QString qrc);

private:
    QQmlApplicationEngine engine;
};

#endif // APPLICATION_H

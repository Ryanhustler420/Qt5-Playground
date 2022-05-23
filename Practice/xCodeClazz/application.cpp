#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
{
    CursorPosProvider *mousePosProvider = new CursorPosProvider(parent);

    // Same Instace Binding Between Different Component/Pages
    engine.rootContext()->setContextProperty("application", this);
    engine.rootContext()->setContextProperty("mousePosition", mousePosProvider);

    // register all the controllers here if you do not want binding of two different component
    qmlRegisterType<LoginPageController>("com.xcodeclazz.loginpagecontroller", 1, 0, "LoginPageController");
    qmlRegisterType<DashboardPageController>("com.xcodeclazz.dashboardcontroller", 1, 0, "DashboardPageController");
    qmlRegisterType<AllRequestCallbacksPage>("com.xcodeclazz.allrequestcallbackspage", 1, 0, "AllRequestCallbacksPage");
    qmlRegisterType<AllCoursesPageController>("com.xcodeclazz.allcoursespagecontroller", 1, 0, "AllCoursesPageController");
    qmlRegisterType<AllStudentsPageController>("com.xcodeclazz.allstudentspagecontroller", 1, 0, "AllStudentsPageController");
    qmlRegisterType<SingleCoursePageController>("com.xcodeclazz.singlecoursepagecontroller", 1, 0, "SingleCoursePageController");
}

void Application::boot(QGuiApplication &app)
{
    const QUrl url(getApplicationPath());
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
}

void Application::clearStack()
{
    emit clearedStack();
}

void Application::gotoPage(QString qrc)
{
    emit pushPage(qrc);
}

void Application::replacePage(QString qrc)
{
    emit pageReplaced(qrc);
}

void Application::pop()
{
    emit poped();
}

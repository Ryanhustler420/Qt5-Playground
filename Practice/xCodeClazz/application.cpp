#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
{
    // Same Instace Binding Between Different Component/Pages
    engine.rootContext()->setContextProperty("application", this);

    // register all the controllers here if you do not want binding of two different component
    qmlRegisterType<LoginPageController>("com.xcodeclazz.loginpagecontroller", 1, 0, "LoginPageController");
    qmlRegisterType<DashboardPageController>("com.xcodeclazz.dashboardcontroller", 1, 0, "DashboardPageController");
}

void Application::boot(QGuiApplication &app)
{
    const QUrl url(QStringLiteral("qrc:/application.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
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

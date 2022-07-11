#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
{
    engine = new QQmlApplicationEngine();
}

void Application::start(QGuiApplication *app)
{
    qmlRegisterType<PageOneController>("com.pageonecontroller", 1, 0, "PageOneController");
    qmlRegisterType<PageTwoController>("com.pagetwocontroller", 1, 0, "PageTwoController");

    engine->rootContext()->setContextProperty("application", this);

    const QUrl url(QStringLiteral("qrc:/application.qml"));
    QObject::connect(engine, &QQmlApplicationEngine::objectCreated, app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine->load(url);
}

void Application::pop()
{
    emit poped();
}

void Application::pageOne()
{
    emit pushPageOne();
}

void Application::pageTwo()
{
    emit pushPageTwo();
}

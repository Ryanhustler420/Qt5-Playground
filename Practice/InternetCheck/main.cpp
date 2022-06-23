#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "inetwork.h"
#include "logger/logger.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    Logger::setPath("E:", "virus.txt");
    Logger::attach();
    Logger::logging = true;
    Logger::dirty_console = false;

    QQmlApplicationEngine engine;
    qmlRegisterType<INetwork>("com.app.inetwork", 1, 0, "INetwork");

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

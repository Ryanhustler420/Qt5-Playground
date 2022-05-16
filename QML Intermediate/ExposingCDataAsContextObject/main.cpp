#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "propertywrapper.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    PropertyWrapper propWrapper;
    propWrapper.setLastName("Doe");
    propWrapper.setFirstName("John");
    engine.rootContext()->setContextObject(&propWrapper);

    /*
    QString firstName = "Gaurav", lastName = "Gupta";
    engine.rootContext()->setContextProperty("mLastName", QVariant::fromValue(lastName));
    engine.rootContext()->setContextProperty("mFirstName", QVariant::fromValue(firstName));
    */

    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

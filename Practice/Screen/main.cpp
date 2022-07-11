#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include <QObject>
#include <QQmlContext>
#include <system.h>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    System s;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty("system", &s);

    const QUrl url(QStringLiteral("qrc:/dashboard_page.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "imageitem.h"
#include "qrclazz.h"
#include <QDebug>

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QrClazz qr;
    qInfo() << qr.parseImage(":/images/raisehand_sample_qr.png");

    qmlRegisterType<QrClazz>("com.QrClazz", 1, 0, "QrClazz");
    qmlRegisterType<ImageItem>("myextension", 1, 0, "ImageItem");

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;    
    const QUrl url(QStringLiteral("qrc:/main.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}

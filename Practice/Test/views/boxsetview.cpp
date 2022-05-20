#include "views\boxsetview.h"

BoxSet::BoxSet(QObject *parent) : QObject(parent)
{
    qmlRegisterType<BoxSetController>("software.raisehand.boxsetcontroller", 1, 0, "BoxSetController");
}

void BoxSet::init(QGuiApplication *base)
{
    Q_UNUSED(base)
    const QUrl url(QStringLiteral("qrc:/boxsetview.qml"));
    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated, this, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl) QGuiApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);
}

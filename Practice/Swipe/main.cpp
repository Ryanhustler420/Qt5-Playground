#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "application.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    Application a;
    a.start(&app);

    return app.exec();
}

#include <QGuiApplication>
#include "boxset.h"


int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    BoxSet bs;
    bs.init(&app);

    return app.exec();
}

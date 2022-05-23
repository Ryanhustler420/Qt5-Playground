#include "application.h"
#include "application/manager.h"

// ****************************************
// https://stackoverflow.com/questions/8834147/c-signal-to-qml-slot-in-qt
// ****************************************

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    // Setting up the env configs
    qInfo() << "Running on:" << Manager::instance().getCurrentEnv();

    // App kicks in
    Application application;
    application.boot(app);

    return app.exec();
}

#include "application.h"
#include "application/manager.h"

#include <QIcon>

// ****************************************
// https://stackoverflow.com/questions/8834147/c-signal-to-qml-slot-in-qt
// ****************************************

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif
    QGuiApplication app(argc, argv);
    app.setWindowIcon(QIcon(":/images/favicon.ico"));

    // Setting up the env configs
    QString env = Manager::instance().getCurrentEnv();
    qInfo() << "The application is running on " << env << " mode.";

    // App kicks in
    Application application;
    application.boot(app);

    return app.exec();
}

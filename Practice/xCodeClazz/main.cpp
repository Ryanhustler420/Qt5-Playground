#include "application.h"

#include "rx/signals.h"
#include "networking/internet.h"
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

    // Check internet in loop
    Signals::instance().onInternetStatusRefresh([=](bool status){
        Manager::instance().setIsInternetPresent(status);
    });

    Internet i;
    i.setCheck_internet_connection_in_loop_is_running(true);
    i.check_internet_connection_in_loop();

    // TODO: // every component can have stackView
    // TODO: we will make google like design for shop keeper to check the product exstence across the city

    // use animation
    // if login page removed from stack view, then gotopage can't call
    // first go to that page and then remove the stack below
    // figure out the design pattern and use that in another project

    return app.exec();
}

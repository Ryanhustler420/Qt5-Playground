#include <QCoreApplication>
#include <QDebug>
#include <QSettings>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QCoreApplication::setOrganizationDomain("www.raisehand.io");
    QCoreApplication::setOrganizationName("Raisehand");
    QCoreApplication::setApplicationName("Raisehand Shop Client");

    QSettings settings(QCoreApplication::organizationName(), QCoreApplication::applicationName());

    // Save the settings
    settings.setValue("test", 1234);

    // Read the settings back
    qInfo() << settings.value("test").toString();
    qInfo() << settings.value("test").toInt();

    return a.exec();
}

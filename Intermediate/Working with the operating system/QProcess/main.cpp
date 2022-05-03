#include <QCoreApplication>
#include <QProcess>
#include <QDebug>

bool openIPConfig() {
    QProcess ipconfig;
    ipconfig.start("ipconfig", QStringList() << "-all");

    if (!ipconfig.waitForStarted()) return false;

    ipconfig.write("qt rocks");
    ipconfig.closeWriteChannel();

    if (!ipconfig.waitForFinished()) return false;
    QByteArray result = ipconfig.readAll();

    qInfo() << "Result: " << result;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    if (openIPConfig()) {
        qInfo() << "IpConfig ran";
    } else {
        qInfo() << "Failed to run IpConfig";
    }

    return a.exec();
}

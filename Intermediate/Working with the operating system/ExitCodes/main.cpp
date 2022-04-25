#include <QCoreApplication>
#include <QDebug>
#include <QProcess>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Starting...";
    QProcess proc;
    proc.execute("start", QStringList() << "brave" << "www.raisehand.software");
    qInfo() << "Exit code: " << proc.exitCode();

    return a.exec();
}

#include <QCoreApplication>
#include <QLockFile>
#include <QDebug>
#include <QFile>
#include <QDir>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Attempting to lock a file...";

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    QFile file(path);

    QLockFile lock (file.fileName() + "l");
    lock.setStaleLockTime(30000); // automatically unlock the file.. after 30000 i.e 30 seconds

    if (lock.tryLock()) {
        qInfo() << "Putting into file...";
        if (file.open(QIODevice::WriteOnly)) {
            QByteArray data;
            file.write(data);
            file.close();
            qInfo() << "Finished into file...";
            // Took over 30 seconds here, auto unlock
        }
        qInfo() << "Unlocking file";
        lock.unlock(); // comment this out and run to see what happen
    } else {
        qInfo() << "Could not lock the file:";
        qint64 pid;
        QString host;
        QString application;

        if (lock.getLockInfo(&pid, &host, &application)) {
            qInfo() << "The file is locked by:";
            qInfo() << "Pid: " << pid;
            qInfo() << "Host: " << host;
            qInfo() << "Application: " << application;
        } else {
            qInfo() << "File is locked, but can't get the info:";
        }
    }

    return a.exec();
}

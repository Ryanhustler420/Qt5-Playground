#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>
#include "worker.h"

// QNetworkAccessManager - FTP Example
// QT += network

void upload(Worker* worker)
{
    QString location = "ftp://speedtest.tele2.net/upload/Raisehand-" + QString::number(QDateTime::currentSecsSinceEpoch()) + ".bin";
    QString path = "C:/Greet.txt"; // Replace this with your file
    worker->upload(location,path);

}

void download(Worker* worker)
{
    QString location = "ftp://speedtest.tele2.net/512KB.zip";
    QString path = "C:/512kb.zip"; // Replace this with your file
    worker->download(location,path);
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Worker worker;
    upload(&worker);
    download(&worker);

    return a.exec();
}

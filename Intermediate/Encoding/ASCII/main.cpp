#include <QCoreApplication>
#include <QDateTime>
#include <QDebug>

#include <QFile>
#include <QDir>

QByteArray makeData() {
    QByteArray data;

    for (int var = 0; var < 10; ++var) {
        data.append(72); // h
        data.append(101); // e
        data.append(108); // l
        data.append(108); // l
        data.append(111); // o
        data.append(33); // !
        data.append(13); // \r
        data.append(10); // \n
    }

    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << __TIME__;
    qInfo() << __DATE__;
    qInfo() << __TIMESTAMP__;

    qInfo() << QDateTime::currentDateTime();
    QDateTime * time = new QDateTime();
    qInfo() << time->currentDateTime();
    delete time;

    QByteArray data = makeData();
    QString path = QDir::currentPath() + QDir::separator() + "data.txt";
    QFile file(path);

    if (file.open(QIODevice::WriteOnly)) {
        file.write(data);
        file.close();
    }

    qInfo() << "Done";

    return a.exec();
}

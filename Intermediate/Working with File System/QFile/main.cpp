#include <QCoreApplication>
#include <QByteArray>
#include <QIODevice>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDir>

bool put (QString path, QByteArray data, QIODevice::OpenMode mode) {
    QFile file(path);

    if (!file.open(mode)) {
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);
    if (!bytes) {
        qWarning() << file.errorString() ;
    } else {
        qInfo() << "Wrote " << bytes << " to the file";
    }

    file.flush(); // not really needed, but for making sure
    file.close();

    return true;
}

void write(QString path, QByteArray data) {
    qInfo() << "Write to file";
    if (put(path, data, QIODevice::WriteOnly)) {
        qInfo() << "Data written to file";
    } else {
        qWarning() << "Failed to write to file:";
    }
}

void append(QString path, QByteArray data) {
    qInfo() << "Write to file";
    if (put(path, data, QIODevice::Append)) {
        qInfo() << "Data appended to file";
    } else {
        qWarning() << "Failed to appended to file:";
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "Path: " << path;

    QByteArray data("Hello Gaurav\r\n");
    for (int var = 0; var < 5; ++var) {
        QString num = QString::number(var);
        num.append(" ");

        QByteArray line(num.toLatin1() + data);
        // write(path, line);
        append(path, line);
    }

    return a.exec();
}

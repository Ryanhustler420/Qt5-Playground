#include <QCoreApplication>
#include <QTextStream>
#include <QByteArray>
#include <QIODevice>
#include <QString>
#include <QDebug>
#include <QFile>
#include <QDir>

bool write(QString path, QByteArray data) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    qint64 bytes = file.write(data);
    // file.flush();
    file.close();
    if (bytes) return true;

    return false;
}

bool createFile(QString path) {
    QByteArray data;
    for (int var = 0; var < 5; ++var) {
        data.append(QString::number(var));
        data.append(" Hello World\r\n");
    }
    return write(path, data);
}

void readFile(QString path) {
    QFile file(path);
    if (!file.exists()) {
        qWarning() << "File not found";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return;
    }

    qInfo() << "****** Reading file";
    qInfo() << file.readAll(); // best for small size file like 1Mb or 4Mb; dont do this for large file. else it will take hell lot of memory
    qInfo() << "****** Done";
}

void readLines(QString path) {
    QFile file(path);
    if (!file.exists()) {
        qWarning() << "File not found";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return;
    }

    qInfo() << "****** Reading file";
    while(!file.atEnd()) {
        QString line(file.readLine());
        qInfo() << "Read: " << line.trimmed(); // best with text files.
    }
    qInfo() << "****** Done";
}

// the file is actually a buffer in system, called file buffer, because it has a starting and an ending point and data in between
// while stream has not end point, like river
void readBytes(QString path) {
    QFile file(path);
    if (!file.exists()) {
        qWarning() << "File not found";
        return;
    }

    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return;
    }

    qInfo() << "****** Reading file";
    while(!file.atEnd()) {
        qInfo() << "Read: " << file.read(5); // best with larger file or structs
    }
    qInfo() << "****** Done";
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "Path: " << path;

    if (createFile(path)) {
        readFile(path);
        readLines(path);
        readBytes(path);
    }

    return a.exec();
}

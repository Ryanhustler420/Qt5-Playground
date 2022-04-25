#include <QCoreApplication>
#include <QRandomGenerator>
#include <QTextStream>
#include <QFileInfo>
#include <QDebug>
#include <QFile>
#include <QDir>

bool createFile(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) {
        qWarning() << file.errorString();
        return false;
    }

    QTextStream stream(&file);
    int max = 1000;
    QString banner = "Random Number:\r\n";
    qInfo() << "Writing " << banner;
    stream << banner; // shifting the data into stream;

    for (int var = 0; var < 5; ++var) {
        qint32 num = QRandomGenerator::global()->bounded(max);
        qInfo() << "Writing " << num;
        stream << num << "\r\n";
    }

    // we are not starting/closing stream because it doesn't have ending...
    file.close();
    return true;
}

void readFile(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) {
        qWarning() << file.errorString();
        return;
    }

    QTextStream stream(&file);

    QString banner;
    stream >> banner; // reading from stream

    qInfo() << "Banner: " << banner;
    for (int var = 0; var < 5; ++var) {
        // qint32 num;
        QString num;
        stream >> num;
        qInfo() << "Random: " << num;
    }

    file.close();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString path = QDir::currentPath() + QDir::separator() + "test.txt";
    qInfo() << "Path: " << path;
    if (createFile(path)) {
        readFile(path);
    }
    return a.exec();
}

#include <QCoreApplication>
#include <QDataStream>
#include <QDebug>
#include <QFile>

// Serialization

bool saveFile(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::WriteOnly)) return false;

    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_5_9);

    QString title = "The answer is 42";
    qint64 num = 42;

    out << title;
    out << num;

    file.flush();
    file.close();

    return true;
}

bool readFile(QString path) {
    QFile file(path);
    if (!file.open(QIODevice::ReadOnly)) return false;

    QDataStream in(&file);
    if (in.version() != QDataStream::Qt_5_9) {
        qCritical() << "Bad version";
        file.close();
        return false;
    }

    QString title;
    qint64 num;

    in >> title;
    in >> num;

    qInfo() << title;
    qInfo() << num;

    return true;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);
    QString name = "test.txt";
    if (saveFile(name)) {
        qInfo () << "Saved";
        if (readFile(name)) {

        }
    }
    return a.exec();
}

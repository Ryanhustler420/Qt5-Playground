#include <QCoreApplication>
#include <QRandomGenerator>
#include <QTextStream>
#include <QDebug>
#include <QFile>
#include <QDir>

QString makeData() {
    QString data;
    data.append("unicode test\r\n");
    for (int var = 0; var < 10; ++var) {
        int number = QRandomGenerator::global()->bounded(1112064);
        data.append(number);
    }
    data.append("\r\n");
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    // QString sc = "12345678945214752";
    // qDebug() << sc.toUtf8().toBase64() + "108@";

    QString data = makeData();
    QString path = QDir::currentPath() + QDir::separator() + "data.txt";

    QFile file(path);
    if (file.open(QIODevice::WriteOnly)) {

        QTextStream stream(&file);

        stream.setCodec("UTF-8");
        stream << data;
        stream.flush();

        file.close();
    }

    qInfo() << "Done";
    qInfo() << "Unicode: " << data;
    qInfo("");
    qInfo() << "ASCII: " << data.toLatin1();

    return a.exec();
}

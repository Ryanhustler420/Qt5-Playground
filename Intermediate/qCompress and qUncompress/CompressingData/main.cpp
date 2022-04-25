#include <QCoreApplication>
#include <QDebug>

QByteArray makeData() {
    QByteArray data;
    for (int var = 0; var < 1000; ++var) {
        data.append(QString::number(var) + "\r\n");
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QByteArray data = makeData();
    QByteArray compressed = qCompress(data);
    QByteArray decompressed = qUncompress(compressed);

    qInfo() << "original: " << data.length();
    qInfo() << "compressed: " << compressed.length();
    qInfo() << "decompressed: " << decompressed.length();

    return a.exec();
}

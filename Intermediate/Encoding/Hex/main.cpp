#include <QCoreApplication>
#include <QDebug>

QString makeData() {
    QString data;
    for (int var = 0; var < 10; ++var) {
        data.append("Hello\r\n");
    }
    return data;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QString data = makeData();

    QByteArray bytes(data.toLatin1());
    QByteArray encoded = bytes.toHex();
    QByteArray decoded = encoded.fromHex(encoded);

    qInfo() << "Encoded: " << encoded; // blob
    qInfo() << "--------------------";
    qInfo() << "Decoded: " << decoded;
    qInfo() << "--------------------";
    qInfo() << "Basic encoded: " << data.toUtf8().toHex();

    return a.exec();
}

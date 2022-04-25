#include <QCoreApplication>
#include <QDebug>
#include <QTextCodec>

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
    QTextCodec *codec = QTextCodec::codecForName("UTF-16");
    if(!codec) qFatal("No codec!");

    QByteArray bytes = codec->fromUnicode(data);
    qInfo() << "Bytes: " << bytes;
    qInfo() << "------------------------------";
    QString string = codec->toUnicode(bytes);
    qInfo() << "String: " << string;

    return a.exec();
}

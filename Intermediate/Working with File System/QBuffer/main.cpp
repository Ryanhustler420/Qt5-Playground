#include <QCoreApplication>
#include <QIODevice>
#include <QBuffer>
#include <QDebug>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QBuffer buffer;

    if(buffer.open(QIODevice::ReadWrite)) {
        qInfo() << "Buffer opened: ";
        QByteArray data("Hello World");

        for (int var = 0; var < 5; ++var) {
            buffer.write(data);
            buffer.write("\r\n");
        }
        // File and device access you may need to flush the data to the device
        // buffer.flush();

        // Move to the first position
        buffer.seek(0);

        qInfo() << buffer.readAll();
        qInfo() << "closing the buffer";

        // ALWAYS close your device:
        buffer.close();
    } else {
        qInfo() << "Could not open buffer";
    }

    return a.exec();
}

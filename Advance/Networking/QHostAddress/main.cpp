#include <QCoreApplication>
#include <QDebug>
#include <QHostAddress>
#include <QNetworkInterface>
#include <QAbstractSocket>

// QT += network

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<QHostAddress> list = QNetworkInterface::allAddresses();

    for (int i = 0;i < list.count();i++)
    {
        QHostAddress address = list.at(i);
        qInfo() << address.toString();

        //Never leaves the machine
        qInfo() << "\t Loopback:" << address.isLoopback();

        //Send to many
        qInfo() << "\t Multicast:" << address.isMulticast();

        switch (address.protocol())
        {
            case QAbstractSocket::UnknownNetworkLayerProtocol:
                qInfo() << "\t Protocol: Unknown";
                break;
            case QAbstractSocket::AnyIPProtocol:
                qInfo() << "\t Protocol: Any";
                break;

            case QAbstractSocket::IPv4Protocol:
                qInfo() << "\t Protocol: IPv4";
                break;

            case QAbstractSocket::IPv6Protocol:
                qInfo() << "\t Protocol: IPv6";
                break;
        }

    }

    return a.exec();
}

#include <QCoreApplication>
#include "client.h"

// QT += network

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
     // client.connectToHost("raisehand.software", 80); // Not encrypted
    client.connectToHost("raisehand.software", 443); //SSL

    return a.exec();
}

#include <QCoreApplication>
#include "client.h"

// Raisehand 101
// Raisehand Loom
// Raisehand Admins
// Raisehand Handshake

// Raisehand -> Shop -> Companies
// Companies -> Shop -> Raisehand
//           |-> Admin -> Raisehand

// QT += network

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.connectToHost("www.gouravgupta.com", 80);

    return a.exec();
}

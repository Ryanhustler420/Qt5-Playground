#include <QCoreApplication>
#include "client.h"

// QT += network

// Raisehand Mimic

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Client client;
    client.connectToHost("gouravgupta.com", 80);

    return a.exec();
}

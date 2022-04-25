#include <QCoreApplication>
#include "server.h"

// QT += network

// High performance multi-threaded TCP server

// Test with Siege
// https://www.joedog.org/siege-home/

// siege -c 1 127.0.0.1:2020
// siege -c 10 127.0.0.1:2020
// siege -c 100 127.0.0.1:2020

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start(2020);

    return a.exec();
}

#include <QCoreApplication>
#include "server.h"

// QT += network
// https://support.code42.com/Incydr/Agent/Troubleshooting/Test_your_network_connection <- telnet on windows

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Server server;
    server.start();

    // telnet 127.0.0.1 2020
    // Note: look at both terminal since on will take the input and the other will show the data which received

    return a.exec();
}

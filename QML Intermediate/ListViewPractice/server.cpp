#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{

}

void Server::fetchData()
{
    qInfo() << "Fetching...";
    QList<QString> list;

    list.append("{hello: world}");

    emit response(list);
}

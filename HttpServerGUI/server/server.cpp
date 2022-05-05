#include "server.h"

Server::Server(QObject *parent) : QObject(parent)
{
    server = nullptr;
    handler = nullptr;

    config.port = defaultPort;
    config.requestTimeout = 20;
    config.responseTimeout = 5;
    config.verbosity = HttpServerConfig::Verbose::All;
    config.maxMultipartSize = 512 * 1024 * 1024;
    config.errorDocumentMap[HttpStatus::NotFound] = "data/404_2.html";
    config.errorDocumentMap[HttpStatus::InternalServerError] = "data/404_2.html";
    config.errorDocumentMap[HttpStatus::BadGateway] = "data/404_2.html";
}

void Server::start()
{
    handler = new RequestHandler();
    server = new HttpServer(config, handler);
    server->listen();
}

void Server::stop()
{
    if (server && server->isListening()) {
        qInfo() << "Was open now closing...";
        server->close();
        server = nullptr;
        handler = nullptr;
    }
}

void Server::setPort(int port)
{
    config.port = port;
}

void Server::setRequestTimeout(int seconds)
{
    config.requestTimeout = seconds;
}

void Server::setResponseTimeout(int seconds)
{
    config.responseTimeout = seconds;
}

void Server::setMultipartSize(int size)
{
    config.maxMultipartSize = size;
}

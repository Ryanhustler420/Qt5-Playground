#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "server/source/httpServer.h"
#include "server/routes/requestHandler.h"

// https://techoverflow.net/2020/01/10/how-to-fix-usr-bin-ld-cannot-find-lzlib/
// https://github.com/addisonElliott/HttpServer

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);
    void start();
    void stop();
    void setPort(int port = defaultPort);
    void setRequestTimeout(int seconds = 20);
    void setResponseTimeout(int seconds = 5);
    void setMultipartSize(int size = 512 * 1024 * 1024);

signals:

private:
    HttpServerConfig config;
    RequestHandler *handler;
    HttpServer *server;

    static int const defaultPort = 8080;
};

#endif // SERVER_H

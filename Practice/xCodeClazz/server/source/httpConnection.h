#ifndef HTTP_SERVER_HTTP_CONNECTION_H
#define HTTP_SERVER_HTTP_CONNECTION_H

#include "server/source/httpRequestHandler.h"
#include "server/source/httpServerConfig.h"
#include "server/source/httpResponse.h"
#include "server/source/httpRequest.h"
#include "server/source/httpData.h"
#include "server/source/util.h"

#include <exception>
#include <list>
#include <memory>
#include <QTcpSocket>
#include <QThread>
#include <QSslConfiguration>
#include <QTimer>
#include <QtPromise>
#include <queue>
#include <unordered_map>

class HTTPSERVER_EXPORT HttpConnection : public QObject
{
	Q_OBJECT

private:
    HttpServerConfig *config;
    QTcpSocket *socket;
    QHostAddress address;
    QTimer *timeoutTimer;
    bool keepAliveMode;

    HttpRequest *currentRequest;
    HttpResponse *currentResponse;

    HttpRequestHandler *requestHandler;
    // Responses are stored in a queue to support HTTP pipelining and sending multiple responses
    std::queue<HttpResponse *> pendingResponses;
    // Store data for each request to enable asynchronous logic
    std::unordered_map<HttpResponse *, HttpDataPtr> data;

    const QSslConfiguration *sslConfig;

    void createSocket(qintptr socketDescriptor);

public:
    HttpConnection(HttpServerConfig *config, HttpRequestHandler *requestHandler, qintptr socketDescriptor,
        QSslConfiguration *sslConfig = nullptr, QObject *parent = nullptr);
    ~HttpConnection();

private slots:
    void read();
    void bytesWritten(qint64 bytes);
    void timeout();
    void socketDisconnected();
    void sslErrors(const QList<QSslError> &errors);

signals:
    void disconnected();
};

#endif // HTTP_SERVER_HTTP_CONNECTION_H

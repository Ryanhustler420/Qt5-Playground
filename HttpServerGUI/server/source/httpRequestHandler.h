#ifndef HTTP_SERVER_HTTP_REQUEST_HANDLER_H
#define HTTP_SERVER_HTTP_REQUEST_HANDLER_H

#include <QtPromise>

#include "server/source/const.h"
#include "server/source/httpData.h"
#include "server/source/httpRequest.h"
#include "server/source/httpResponse.h"

class HTTPSERVER_EXPORT HttpRequestHandler : public QObject
{
    Q_OBJECT

public:
    HttpRequestHandler(QObject *parent = nullptr) : QObject(parent) {}

    virtual HttpPromise handle(HttpDataPtr data) = 0;
};

#endif // HTTP_SERVER_HTTP_REQUEST_HANDLER_H

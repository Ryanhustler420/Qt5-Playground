#include "networking/network.h"

Network::Network(CommonSuperClass *parent) : CommonSuperClass(parent)
  , mNetMan(new QNetworkAccessManager(parent))
  , cookie_jar(new QNetworkCookieJar)
  , mNetReply(nullptr)
  , mDataBuffer(new QByteArray)
{
}

void Network::attachHeader(QNetworkRequest &netRequest, QByteArray key, QByteArray value)
{
    netRequest.setRawHeader(key, value);
}

void Network::printCookies(QUrl qurl)
{
    for (QNetworkCookie c : mNetMan->cookieJar()->cookiesForUrl(qurl)) {
        qInfo() << c.name() << " -> " << QString(c.value());
    }
}

void Network::clearResponse()
{
    mDataBuffer->clear();
}

void Network::handleSpecifStatusCode(
        QNetworkReply *reply,
        std::function<void()> ok,
        std::function<void()> bad,
        std::function<void()> unauthorized,
        std::function<void()> unprocessable,
        std::function<void()> upgrade,
        std::function<void()> not_implemented,
        std::function<void()> bad_gateway,
        std::function<void()> under_maintenance
)
{
    int errorCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    switch (errorCode) {
        case 200: ok(); break;
        case 400: bad(); break;
        case 401: unauthorized(); break;
        case 422: unprocessable(); break;
        case 426: upgrade(); break;
        case 501: not_implemented(); break;
        case 502: bad_gateway(); break;
        case 503: under_maintenance(); break;
    }
}

void Network::handleAllStatusCode(QNetworkReply *reply, QByteArray *response, std::function<void ()> ok, std::function<void (QByteArray)> error)
{
    int errorCode = reply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
    switch (errorCode) {
        case 200: ok(); break;
        case 400:
        case 401:
        case 422:
        case 426:
        case 501:
        case 502:
        case 503:
            error(*response);
            break;
    }
}

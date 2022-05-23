#include "networking/network.h"

Network::Network(CommonSuperClass *parent) :
    CommonSuperClass(parent)
  , mNetMan(new QNetworkAccessManager(parent))
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

void Network::houseKeeper()
{
    mNetReply->deleteLater();
    mNetReply = nullptr;
    mDataBuffer->clear();
}

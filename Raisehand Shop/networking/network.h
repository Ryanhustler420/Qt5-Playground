#ifndef NETWORK_H
#define NETWORK_H

#include "parents/commonsuperclass.h"

#include <QNetworkReply>
#include <QNetworkRequest>
#include <QNetworkAccessManager>

#include <QNetworkCookie>
#include <QNetworkCookieJar>

// this class will only responsible for network connection,
// interpretor and other things, we need to add dependencies in this class
class Network : public CommonSuperClass
{
public:
    explicit Network(CommonSuperClass *parent = nullptr);

private:
    QNetworkAccessManager *mNetMan;
    QNetworkCookieJar *cookieJar;
    QNetworkReply *mNetReply;
    QByteArray *mDataBuffer;
signals:

public:
    void attachHeader(QNetworkRequest &netRequest);
    void attachHeader(QNetworkRequest &netRequest, QByteArray key, QByteArray value);

private:
    void printCookies(QUrl qurl);

    void houseKeeper();

private:
    QNetworkCookieJar cookie_jar;
};

#endif // NETWORK_H

#ifndef NETWORK_H
#define NETWORK_H

#include "parents/commonsuperclass.h"

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QNetworkCookieJar>
#include <QNetworkCookie>

class Network : public CommonSuperClass
{
public:
    explicit Network(CommonSuperClass *parent = nullptr);

public:
    void attachHeader(QNetworkRequest &netRequest, QByteArray key, QByteArray value);
    void attachHeader(QNetworkRequest &netRequest);
    void printCookies(QUrl qurl);
    void clearResponse();
    void handleSpecifStatusCode(QNetworkReply *reply,
                          std::function<void()> ok = nullptr,
                          std::function<void()> bad = nullptr,
                          std::function<void()> unauthorized = nullptr,
                          std::function<void()> unprocessable = nullptr,
                          std::function<void()> upgrade = nullptr,
                          std::function<void()> not_implemented = nullptr,
                          std::function<void()> bad_gateway = nullptr,
                          std::function<void()> under_maintenance = nullptr);
    void handleAllStatusCode(QNetworkReply *reply,
                          std::function<void()> ok,
                          std::function<void()> error);

public:
    QNetworkAccessManager *mNetMan;
    QNetworkCookieJar *cookie_jar;
    QNetworkReply *mNetReply;
    QByteArray *mDataBuffer;

};

#endif // NETWORK_H

#ifndef GOOGLEOAUTH_H
#define GOOGLEOAUTH_H

#include <QObject>
#include <QOAuth2AuthorizationCodeFlow>
#include <QNetworkAccessManager>
#include <QNetworkReply>
#include <QNetworkRequest>
#include <QUrl>
#include <QUrlQuery>
#include <QOAuthHttpServerReplyHandler>
#include <QDesktopServices>

// https://developers.google.com/oauthplayground

class CustomRequestHandler : public QOAuthHttpServerReplyHandler
{
    // QAbstractOAuthReplyHandler interface
public:
    QString callback() const {
        return QString("http://127.0.0.1:3003/google_oauth/");
    }
};

class GoogleOAuth : public QObject
{
    Q_OBJECT
public:
    explicit GoogleOAuth(QObject *parent = nullptr);
    Q_INVOKABLE void click();

private:
    QOAuth2AuthorizationCodeFlow * google;
};

#endif // GOOGLEOAUTH_H

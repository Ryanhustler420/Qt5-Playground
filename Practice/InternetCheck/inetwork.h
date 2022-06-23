#ifndef INETWORK_H
#define INETWORK_H

#include <QObject>
#include <QVariant>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QEventLoop>

#include <QMap>

class INetwork : public QObject
{
    Q_OBJECT
public:
    explicit INetwork(QObject *parent = nullptr);

    Q_INVOKABLE void fetch();
    Q_INVOKABLE void load();

signals:
    void fetched(QByteArray data);
    void loaded(QString v);

private:
    QNetworkAccessManager *mNetMan;

};

#endif // INETWORK_H

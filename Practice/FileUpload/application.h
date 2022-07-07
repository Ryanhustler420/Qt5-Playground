#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QBuffer>
#include <QImage>
#include <QFile>

#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>

#include <QNetworkCookieJar>
#include <QNetworkCookie>
#include <QEventLoop>

#include <QList>

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);

    Q_INVOKABLE void uploadSingleImage();
    Q_INVOKABLE void uploadSingleFile();
    Q_INVOKABLE void uploadMultipleImages();
    Q_INVOKABLE void uploadMultipleFiles();

signals:

private:
    QNetworkAccessManager *mNetMan;
    QNetworkCookieJar *cookie_jar;
    QNetworkReply *mNetReply;
    QByteArray *mDataBuffer;

};

#endif // APPLICATION_H

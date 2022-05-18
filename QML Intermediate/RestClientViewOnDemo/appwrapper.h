#ifndef APPWRAPPER_H
#define APPWRAPPER_H

#include <QNetworkAccessManager>
#include <QNetworkRequest>
#include <QNetworkReply>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>
#include <QObject>
#include <QDebug>

class AppWrapper : public QObject
{
    Q_OBJECT
public:
    explicit AppWrapper(QObject *parent = nullptr);

    Q_INVOKABLE void fetchPosts(int number);
    Q_INVOKABLE void removeLast();

public:
    const QStringList &jocks() const;

public slots:

private slots:
    void dataReadyRead();
    void dataReadFinished();

signals:

private:
    QNetworkAccessManager * mNetManager;
    QNetworkReply * mNetReply;
    QByteArray * mDataBuffer;
    QStringList mJocks;
};

#endif // APPWRAPPER_H

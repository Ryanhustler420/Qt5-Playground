#include "inetwork.h"

INetwork::INetwork(QObject *parent) : QObject(parent)
{
    mNetMan = new QNetworkAccessManager();
}

void INetwork::fetch()
{
    QNetworkRequest request(QUrl("https://jsonplaceholder.typicode.com/posts"));

    QNetworkReply *mNetReply = mNetMan->get(request);
    QByteArray *mDataBuffer = new QByteArray(nullptr);

    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        qInfo() << *mDataBuffer;
        emit fetched(*mDataBuffer);
    });
}

void INetwork::load()
{
    // first figure out what version of OpenSSL is supported
    if (!QSslSocket::supportsSsl()) {
        emit loaded(
                    "sslLibraryBuildVersionString:: " + QSslSocket::sslLibraryBuildVersionString() + "\n" +
                    "sslLibraryVersionString:: " + QSslSocket::sslLibraryVersionString() + "\n" +
                    "supportsSsl:: " + "false");
    } else {
        emit loaded(
                    "sslLibraryBuildVersionString:: " + QSslSocket::sslLibraryBuildVersionString() + "\n" +
                    "sslLibraryVersionString:: " + QSslSocket::sslLibraryVersionString() + "\n" +
                    "supportsSsl:: " + "true");
    }
    // install the required OpenSSL to system and set the path variable as well
    // or show user to download the supported ssl link download setup
}

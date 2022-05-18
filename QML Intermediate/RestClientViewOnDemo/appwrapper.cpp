#include "appwrapper.h"

AppWrapper::AppWrapper(QObject *parent) : QObject(parent),
    mNetManager(new QNetworkAccessManager(this)),
    mNetReply(nullptr),
    mDataBuffer(new QByteArray)
{

}

void AppWrapper::fetchPosts(int number)
{
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/todos");
    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply, &QNetworkReply::readyRead, this, &AppWrapper::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &AppWrapper::dataReadFinished);
}

void AppWrapper::removeLast()
{

}

const QStringList &AppWrapper::jocks() const
{
    return mJocks;
}

void AppWrapper::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void AppWrapper::dataReadFinished()
{
    if (mNetReply->error()) {
        qDebug() << "There was some error: " << mNetReply->errorString();
    } else {
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);
        QJsonArray array = doc.array();
        for (QJsonValue v: array) {
            mJocks.append(v.toString());
        }
        mDataBuffer->clear();
    }

}

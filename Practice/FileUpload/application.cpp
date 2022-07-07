#include "application.h"

Application::Application(QObject *parent) : QObject(parent)
    , mNetMan(new QNetworkAccessManager(parent))
    , cookie_jar(new QNetworkCookieJar)
    , mNetReply(nullptr)
    , mDataBuffer(new QByteArray)
{

}

void Application::uploadSingleImage()
{
    QBuffer imgBuffer;
    imgBuffer.open(QIODevice::WriteOnly);

    QImage qp("C:/Users/Raisehand/Desktop/zzz/download.jpg");
    qp.save(&imgBuffer, "PNG");

    QJsonObject mainObject;
    mainObject.insert("image", (QString) imgBuffer.data().toBase64());

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(QUrl("http://localhost:3002/sandbox/v1/test"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        qInfo() << *mDataBuffer;
    });
}

void Application::uploadSingleFile()
{
    QBuffer fileBuffer;
    fileBuffer.open(QIODevice::WriteOnly);

    QFile *ff = new QFile("D:/Tutorials.txt");
    ff->open(QIODevice::ReadOnly);

    QJsonObject mainObject;
    mainObject.insert("text", (QString) ff->readAll().toBase64());

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(QUrl("http://localhost:3002/sandbox/v1/test"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        qInfo() << *mDataBuffer;
    });
}

void Application::uploadMultipleImages()
{
    QList<QString> urls;
    urls.append("C:/Users/Raisehand/Desktop/zzz/(MyPornVid.fun)_indian-bhabhi-hot-boobs-downblouse-124-big-boobs.jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/download.jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/images (1).jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/images.jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/indian_downblou-4253.jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/Jills-Mohan-5.jpg");
    urls.append("C:/Users/Raisehand/Desktop/zzz/xstag-c8pdz-98f52c.jpg");

    QJsonArray images_arr;
    for (QString img_url: urls)
    {
        QBuffer imgBuffer;
        imgBuffer.open(QIODevice::WriteOnly);
        QImage qp(img_url);
        qp.save(&imgBuffer, "JPG");
        images_arr.push_back( (QString) imgBuffer.data().toBase64());
    }

    QJsonObject mainObject;
    mainObject.insert("images", images_arr);

    QJsonDocument jsonDoc;
    jsonDoc.setObject(mainObject);

    QNetworkRequest request(QUrl("http://localhost:3002/sandbox/v1/test"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/json");

    QNetworkReply *mNetReply = mNetMan->post(request, jsonDoc.toJson());
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        qInfo() << *mDataBuffer;
    });
}

void Application::uploadMultipleFiles()
{

}

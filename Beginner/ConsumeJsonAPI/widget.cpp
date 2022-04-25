#include "widget.h"
#include "ui_widget.h"

#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonArray>
#include <QJsonObject>
#include <QVariantMap>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget),
      mNetManager(new QNetworkAccessManager(this)),
      mNetReply(nullptr),
      mDataBuffer(new QByteArray)
{
    ui->setupUi(this);

    qInfo() << QSslSocket::sslLibraryBuildVersionString();
    qInfo() << QSslSocket::supportsSsl();
    qInfo() << QSslSocket::sslLibraryVersionString();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::on_fetchBtn_clicked()
{
    // Initialze our Api endpoint
    const QUrl API_ENDPOINT("https://jsonplaceholder.typicode.com/posts");

    QNetworkRequest request;
    request.setUrl(API_ENDPOINT);

    mNetReply = mNetManager->get(request);
    connect(mNetReply, &QIODevice::readyRead, this, &Widget::dataReadyRead);
    connect(mNetReply, &QNetworkReply::finished, this, &Widget::dataReadFinished);
}

void Widget::dataReadyRead()
{
    mDataBuffer->append(mNetReply->readAll());
}

void Widget::dataReadFinished()
{
    if (mNetReply -> error()) {
        qDebug() << "Error: " << mNetReply->errorString();
    } else {
        qDebug() << "Data fetched finished: " << QString(*mDataBuffer);

        // Turn the data into a json document
        QJsonDocument doc = QJsonDocument::fromJson(*mDataBuffer);

        /*
        //  What if you get an object from the server
        QJsonDocument oDoc = QJsonDocument::fromJson(*mDataBuffer);
        QJsonObject o = oDoc.toVariant().toJsonObject();
        */

        // Turn document into json array
        QJsonArray array = doc.array();

        for (int var = 0; var < array.size(); ++var) {
            QJsonObject object = array.at(var).toObject();
            QVariantMap map = object.toVariantMap();

            QString title = map["title"].toString();
            // qDebug() << " Title [" << QString::number(var) << "] is : " << title;

            ui->listWidget->addItem(QString::number(var + 1) + " - " + title);
        }

    }
}

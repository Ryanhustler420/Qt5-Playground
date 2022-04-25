#include "widget.h"
#include "ui_widget.h"

#include <QNetworkReply>
#include <QDebug>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // Define Network Manage Once In An Entire Application
    netManager = new QNetworkAccessManager(this);
    netReply = nullptr;
    mDataBuffer = new QByteArray();

    // Define Network Request
    QNetworkRequest request;
    request.setUrl(QUrl("http://localhost:3002/sandbox/v1/"));
    netReply = netManager->get(request);

    connect(netReply, &QIODevice::readyRead, this, &Widget::dataReadyToRead);
    connect(netReply, &QNetworkReply::finished, this, &Widget::dataReadyFinished);

    qDebug() << QSslSocket::sslLibraryBuildVersionString();
    qDebug() << QSslSocket::supportsSsl();
    qDebug() << QSslSocket::sslLibraryVersionString();
}

Widget::~Widget()
{
    delete ui;
}

void Widget::dataReadyToRead()
{
    qDebug() << "Some data available";
    mDataBuffer->append(netReply->readAll());
}

void Widget::dataReadyFinished()
{
    if (netReply->error()) {
        qDebug() << "Error : " << netReply->errorString();
    } else {
        qInfo() << QString(*mDataBuffer);
        // ui->textEdit->setPlainText(QString(*mDataBuffer));
    }
}

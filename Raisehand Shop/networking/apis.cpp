#include "apis.h"

Apis::Apis(CommonSuperClass *parent) :
    CommonSuperClass(parent)
  , mNetwork(new Network(parent))
  , mNetMan(new QNetworkAccessManager(parent))
  , enums(new Enums)
{

}

void Apis::attachHeader(QNetworkRequest &netRequest)
{
    netRequest.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    mNetwork->attachHeader(netRequest, enums->_raw_headers.raisehand_access_platform_names_array.toLatin1(), "[android]");
    mNetwork->attachHeader(netRequest, enums->_raw_headers.raisehand_route_caller_appname.toLatin1(), "shop");
    mNetwork->attachHeader(netRequest, enums->_raw_headers.raisehand_server_version.toLatin1(), "8");
    mNetwork->attachHeader(netRequest, enums->_raw_headers.raisehand_app_version.toLatin1(), "54");
    mNetwork->attachHeader(netRequest, enums->_raw_headers.raisehand_auth_token.toLatin1(), "");
}

void Apis::login(QString email, QString password, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error) {
    QByteArray postData;
    postData.append(QString("email=%1").arg(email));
    postData.append("&");
    postData.append(QString("password=%1").arg(password));
    postData.append("&");
    postData.append(QString("appName=%1").arg("shop"));
    postData.append("&");
    postData.append(QString("deviceUUID=%1").arg("123abc@jjhhdddkkhhsRH"));

    QNetworkRequest request(routes.post_api_shop_user_login());
    attachHeader(request);

    QByteArray * mDataBuffer = new QByteArray();
    QNetworkReply *mNetReply = mNetMan->post(request, postData);
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        int errorCode = mNetReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        switch (errorCode) {
        case 200: /* OK */
            response(*mDataBuffer);
            break;
        case 400: /* BAD */
        case 401: /* UN AUTHORIZED */
        case 422: /* Unprocessable Entity */
        case 426: /* UPGRADE REQUIRED */
        case 501: /* NOT IMPLEMENTED */
        case 502: /* BAD GATEWAY */
        case 503: /* UNDER MAINTENANCE */
            error(mNetReply->errorString().toLatin1());
            break;
        }
    });
}

void Apis::getMyStockIds(QString s_id, std::function<void (QByteArray)> response, std::function<void(QByteArray)> error)
{
    QByteArray postData;
    postData.append(QString("s_id=%1").arg(s_id));

    QNetworkRequest request(routes.post_api_shop_shop_all_shop_products_ids());
    attachHeader(request);

    QByteArray * mDataBuffer = new QByteArray();
    QNetworkReply *mNetReply = mNetMan->post(request, postData);
    connect(mNetReply, &QIODevice::readyRead, this, [=]() { mDataBuffer->append(mNetReply->readAll()); });
    connect(mNetReply, &QNetworkReply::finished, this, [=](){
        int errorCode = mNetReply->attribute(QNetworkRequest::HttpStatusCodeAttribute).toInt();
        switch (errorCode) {
        case 200: /* OK */
            response(*mDataBuffer);
            break;
        case 400: /* BAD */
        case 401: /* UN AUTHORIZED */
        case 422: /* Unprocessable Entity */
        case 426: /* UPGRADE REQUIRED */
        case 501: /* NOT IMPLEMENTED */
        case 502: /* BAD GATEWAY */
        case 503: /* UNDER MAINTENANCE */
            error(mNetReply->errorString().toLatin1());
            break;
        }
    });
}

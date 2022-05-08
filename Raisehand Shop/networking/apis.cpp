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

// NOTE: the code=? is valid for one call only, please make sure you mention this before user hit the oauth button
void Apis::exchangeGoogleOAuthCode(QString code, std::function<void(QByteArray)> response, std::function<void(QByteArray)> error)
{
    QByteArray postData;
    postData.append(QString("code=%1").arg(code));
    postData.append("&");
    postData.append(QString("client_id=%1").arg("926313063462-r1ua8s90db0tgghvpaitt7t96vku7svi.apps.googleusercontent.com"));
    postData.append("&");
    postData.append(QString("client_secret=%1").arg("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"));
    postData.append("&");
    postData.append(QString("redirect_uri=%1").arg("http%3A%2F%2F127.0.0.1:3003%2Fgoogle_oauth%2F"));
    postData.append("&");
    postData.append(QString("grant_type=%1").arg("authorization_code"));

    QNetworkRequest request(QUrl("https://oauth2.googleapis.com/token"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    // request.setRawHeader("Content-length", QString::number(code.length()).toLatin1()); // this was producing the error

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

void Apis::exchangeGoogleAccessTokenForUserInfo(QString tokenType, QString accessToken, std::function<void (QByteArray)> response, std::function<void (QByteArray)> error)
{
    QNetworkRequest request(QUrl("https://www.googleapis.com/oauth2/v2/userinfo"));
    request.setHeader(QNetworkRequest::ContentTypeHeader, "application/x-www-form-urlencoded");
    request.setRawHeader("Authorization", QString("%1 %2").arg(tokenType).arg(accessToken).toLatin1());

    QByteArray * mDataBuffer = new QByteArray();
    QNetworkReply *mNetReply = mNetMan->get(request);
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

/*
 * // JAVASCRIPT (Server Code)
 * // https://developers.google.com/oauthplayground
  const fetch = require('node-fetch');
  app.get(`${version}/__run__`, async (req, res) => {
    const url ='https://oauth2.googleapis.com/token';
    const code = '4%2F0AX4XfWgBta1lNpxoG1EHCPhPD3PfG312pLsAaHkNaYwDhURswc7E7JAUwZXsckqt9CHp8w';
    const headers = {
      "Content-Type": "application/x-www-form-urlencoded",
      'Content-length': code.length,
    }
    fetch(url, {
        method: 'POST', headers: headers,
        body: `code=${code}&client_id=926313063462-r1ua8s90db0tgghvpaitt7t96vku7svi.apps.googleusercontent.com
        &client_secret=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&redirect_uri=http%3A%2F%2F127.0.0.1:3003%2Fgoogle_oauth%2F&grant_type=authorization_code`
    })
    .then(res => res.json())
    .then((json) => {
      fetch('https://www.googleapis.com/oauth2/v2/userinfo', {
        method: 'GET',
        headers: {
          Authorization: `${json.token_type} ${json.access_token}`
        },
      })
      .then(res => res.json())
      .then((json) => {
        return new RESPONSE(res).ok({json});
      })
    });
  });
*/


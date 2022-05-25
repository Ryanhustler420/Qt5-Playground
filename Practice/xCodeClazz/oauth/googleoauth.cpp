#include "oauth/googleoauth.h"

GoogleOAuth::GoogleOAuth(QObject *parent) : QObject(parent)
{
    this->google = new QOAuth2AuthorizationCodeFlow(this);

    // Set Scope or Permissions required from Google
    // List can be obtained from https://developers.google.com/identity/protocols/oauth2/scopes

    this->google->setScope("email");

    connect(this->google, &QOAuth2AuthorizationCodeFlow::authorizeWithBrowser, [=](QUrl url) {
        QUrlQuery query(url);

        query.addQueryItem("prompt", "consent");      // Param required to get data everytime
        query.addQueryItem("access_type", "offline"); // Needed for Refresh Token (as AccessToken expires shortly)
        url.setQuery(query);
        QDesktopServices::openUrl(url);
    });

    // Here the parameters from Google JSON are filled up
    // Attached screenshot of JSON file and Google Console

    this->google->setAuthorizationUrl(QUrl("https://accounts.google.com/o/oauth2/auth"));
    this->google->setAccessTokenUrl(QUrl("https://oauth2.googleapis.com/token"));
    this->google->setClientIdentifier("926313063462-r1ua8s90db0tgghvpaitt7t96vku7svi.apps.googleusercontent.com");
    this->google->setClientIdentifierSharedKey("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");

    this->google->setReplyHandler(new CustomRequestHandler);
    connect(this->google, &QOAuth2AuthorizationCodeFlow::granted, this, [=]() {
        qDebug() << __FUNCTION__ << __LINE__ << "Access Granted!";

        auto reply = this->google->get(QUrl("https://www.googleapis.com/oauth2/v2/userinfo"));
        connect(reply, &QNetworkReply::finished, [reply]() {
            qDebug() << "REQUEST FINISHED. Error? " << (reply->error() != QNetworkReply::NoError);
            qDebug() << reply->readAll();
        });
    });
}

// Call this function to prompt authentication
// and receive data from Google

void GoogleOAuth::click()
{
    this->google->grant();
}

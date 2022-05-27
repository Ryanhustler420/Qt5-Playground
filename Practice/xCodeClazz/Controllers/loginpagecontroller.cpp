#include "controllers/loginpagecontroller.h"

LoginPageController::LoginPageController(QObject *parent) : QObject(parent)
{
}

void LoginPageController::checkAuthentication()
{
    QTimer::singleShot(1000, this, [=](){
        emit userAuthenticated(false);
    });
}

void LoginPageController::login(QString email, QString password)
{
    qInfo() << email << password;
    QTimer::singleShot(1000, this, [=](){
        emit loginSucced();
    });
}

void LoginPageController::oauthGoogleLogin()
{
    server.setPort(3003);
    server.start();
    google_oauth.click();

    Signals::instance().onGoogleOAuthCodeReceive([=](QString code){
        apis.exchangeGoogleOAuthCode(code, [=](QByteArray response){
            QJsonObject root = QJsonDocument::fromJson(response).object();
            QString access_token = root.find("access_token")->toString();
            QString token_type = root.find("token_type")->toString();
            apis.exchangeGoogleAccessTokenForUserInfo(token_type, access_token, [=](QByteArray response){
                qInfo() << QJsonDocument::fromJson(response);
            }, [=](QByteArray error){
                qInfo() << error;
            });
        }, [=](QByteArray error){
            qWarning() << error;
        });
    });
}

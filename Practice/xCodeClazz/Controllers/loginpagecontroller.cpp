#include "controllers/loginpagecontroller.h"

LoginPageController::LoginPageController(QObject *parent) : QObject(parent)
{
}

void LoginPageController::checkAuthentication()
{
    QJsonObject doc = xdb.getLoginDetails();
    if (doc.contains("email")) {
        emit userAuthenticated(true);
    } else {
        emit userAuthenticated(false);
    }
}

void LoginPageController::login(QString email, QString password)
{
    Q_UNUSED(email);
    Q_UNUSED(password);
    QTimer::singleShot(1000, this, [=](){ emit loginSucced(); });
}

void LoginPageController::oauthGoogleLogin()
{
    server.setPort(3003);
    server.start();
    google_oauth.click();

    timer.wait_once(30000, [=](){
        server.stop();
        emit googleOauthFailed();
    });

    Signals::instance().onGoogleOAuthCodeReceive([=](QString code){
        apis.exchangeGoogleOAuthCode(code, [=](QByteArray response){
            QJsonObject root = QJsonDocument::fromJson(response).object();
            QString access_token = root.find("access_token")->toString();
            QString token_type = root.find("token_type")->toString();
            apis.exchangeGoogleAccessTokenForUserInfo(token_type, access_token, [=](QByteArray response){
                QJsonObject doc = QJsonDocument::fromJson(response).object();
                if(xdb.saveLoginDetails(doc))
                    emit googleOauthSucced();
                server.stop();
            }, [=](QByteArray error){
                server.stop();
                emit googleOauthFailed();
                qInfo() << error;
            });
        }, [=](QByteArray error){
            server.stop();
            emit googleOauthFailed();
            qWarning() << error;
        });
    });
}

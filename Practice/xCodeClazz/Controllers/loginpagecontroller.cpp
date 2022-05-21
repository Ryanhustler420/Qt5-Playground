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

#ifndef LOGINPAGECONTROLLER_H
#define LOGINPAGECONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

#include "utility/xcodeclazzdb.h"
#include "application/manager.h"
#include "utility/jsonhelper.h"
#include "oauth/googleoauth.h"
#include "networking/apis.h"
#include "server/server.h"
#include "rx/signals.h"

class LoginPageController : public QObject
{
    Q_OBJECT
public:
    explicit LoginPageController(QObject *parent = nullptr);
    Q_INVOKABLE void checkAuthentication();
    Q_INVOKABLE void oauthGoogleLogin();
    Q_INVOKABLE void login(QString email, QString password);

signals:
    void userAuthenticated(bool isAuthenticated);
    void loginSucced();
    void loginFailed();
    void googleOauthSucced();
    void googleOauthFailed();

private:
    Apis apis;
    Server server;
    XCodeClazzDB xdb;
    GoogleOAuth google_oauth;

};

#endif // LOGINPAGECONTROLLER_H

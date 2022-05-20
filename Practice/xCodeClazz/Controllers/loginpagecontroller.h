#ifndef LOGINPAGECONTROLLER_H
#define LOGINPAGECONTROLLER_H

#include <QObject>
#include <QDebug>
#include <QTimer>

class LoginPageController : public QObject
{
    Q_OBJECT
public:
    explicit LoginPageController(QObject *parent = nullptr);
    Q_INVOKABLE void checkAuthentication();
    Q_INVOKABLE void login(QString email, QString password);

signals:
    void userAuthenticated(bool isAuthenticated);
    void loginSucced();
    void loginFailed();

};

#endif // LOGINPAGECONTROLLER_H

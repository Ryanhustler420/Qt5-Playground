#ifndef APPLICATION_H
#define APPLICATION_H

#include <QObject>
#include <QQmlContext>
#include <QGuiApplication>
#include <QQmlApplicationEngine>

#include "Controllers/loginpagecontroller.h"
#include "Controllers/dashboardpagecontroller.h"

class Application : public QObject
{
    Q_OBJECT
public:
    explicit Application(QObject *parent = nullptr);
    void boot(QGuiApplication &app);

public:
    Q_INVOKABLE QString getLoginPagePath() { return "qrc:/login_page.qml"; };
    Q_INVOKABLE QString getApplicationPath() { return "qrc:/application.qml"; };
    Q_INVOKABLE QString getDashboardPath() { return "qrc:/dashboard_page.qml"; };

signals:
    void clearedStack();
    void pushPage(QString qrc);

public slots:
    void clearStack();
    void gotoPage(QString qrc);

private:
    QQmlApplicationEngine engine;
};

#endif // APPLICATION_H

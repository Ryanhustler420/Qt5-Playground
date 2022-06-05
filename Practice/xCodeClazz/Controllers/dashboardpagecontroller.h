#ifndef DASHBOARDPAGECONTROLLER_H
#define DASHBOARDPAGECONTROLLER_H

#include <QDebug>
#include <QObject>

#include "utility/xcodeclazzdb.h"
#include "application/manager.h"
#include "utility/jsonhelper.h"
#include "networking/apis.h"
#include "rx/signals.h"

class DashboardPageController : public QObject
{
    Q_OBJECT
public:
    explicit DashboardPageController(QObject *parent = nullptr);
    Q_INVOKABLE void openCountState(QString name, QString count);
    Q_INVOKABLE void logout();
    Q_INVOKABLE void loadUserData();

signals:
    void logedout();
    void loadedUserData(QJsonObject o);

private:
    XCodeClazzDB xdb;
    Apis apis;

};

#endif // DASHBOARDPAGECONTROLLER_H

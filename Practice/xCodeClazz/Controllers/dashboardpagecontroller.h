#ifndef DASHBOARDPAGECONTROLLER_H
#define DASHBOARDPAGECONTROLLER_H

#include <QDebug>
#include <QObject>

#include "utility/xcodeclazzdb.h"
#include "application/manager.h"
#include "utility/jsonhelper.h"
#include "networking/apis.h"
#include "utility/timer.h"
#include "rx/signals.h"

class DashboardPageController : public QObject
{
    Q_OBJECT
public:
    explicit DashboardPageController(QObject *parent = nullptr);
    Q_INVOKABLE void openCountState(QString name, QString count);
    Q_INVOKABLE void logout();
    Q_INVOKABLE void loadUserData();

    Q_INVOKABLE void listViewReachedBottom(QVariant o);
    Q_INVOKABLE void scrollViewReachedBottom(QVariant o);

signals:
    void showLoading(bool b);
    void listViewReached(QVariant o);
    void scrollViewReached(QVariant o);

signals:
    void logedout();
    void loadedUserData(QJsonObject o);

private:
    XCodeClazzDB xdb;
    Apis apis;
    Timer timer;

};

#endif // DASHBOARDPAGECONTROLLER_H

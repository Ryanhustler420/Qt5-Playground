#ifndef MANAGER_H
#define MANAGER_H

#include "singleton/singleton_obj.h"
#include <QUrl>

class Manager : public OSingleton<Manager>
{

public:
    explicit Manager(QObject *parent = nullptr);

signals:

public:
    int getVersionCode() const;
    QString getCurrentEnv() const;
    QUrl getCurrentHostUrl() const;
    QString getAppVersionName() const;
    QString getServerVersionCode() const;

private:
    int versionCode;
    QString env, appVersionName, serverVersionCode;
    QUrl *hostUrl;

};

#endif // MANAGER_H

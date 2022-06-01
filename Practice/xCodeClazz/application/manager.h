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
    QUrl getCurrentAssetsUrl() const;
    QString getAppVersionName() const;
    QString getServerVersionCode() const;

public:
    bool getIsInternetPresent() const;
    void setIsInternetPresent(bool newIsInternetPresent);

private:
    int versionCode;
    bool isInternetPresent;
    QString env, appVersionName, serverVersionCode;
    QUrl *hostUrl, *siteAssets;

};

#endif // MANAGER_H

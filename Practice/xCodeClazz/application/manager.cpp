#include "application/manager.h"

// this class will be manager of entire application
// will track of the current enviorment and other stuff.
Manager::Manager(QObject *parent) : OSingleton<Manager>()
{
    versionCode = 1;
    appVersionName = "1";
    serverVersionCode = "8";
#ifdef QT_DEBUG
    env = "dev";
    siteAssets = new QUrl("http://xcodeclazz.com");
    hostUrl = new QUrl("http://localhost:3000/v1");
#else
    env = "prod";
    siteAssets = new QUrl("http://xcodeclazz.com");
    hostUrl = new QUrl("https://xcodeclazz.herokuapp.com/v1");
#endif
}

int Manager::getVersionCode() const
{
    return versionCode;
}

QString Manager::getCurrentEnv() const
{
    return env;
}

QUrl Manager::getCurrentHostUrl() const
{
    return *hostUrl;
}

QUrl Manager::getCurrentAssetsUrl() const
{
    return *siteAssets;
}

QString Manager::getAppVersionName() const
{
    return appVersionName;
}

QString Manager::getServerVersionCode() const
{
    return serverVersionCode;
}

bool Manager::getIsInternetPresent() const
{
    return isInternetPresent;
}

void Manager::setIsInternetPresent(bool newIsInternetPresent)
{
    isInternetPresent = newIsInternetPresent;
}

#include "application/manager.h"

// this class will be manager of entire application
// will track of the current enviorment and other stuff.
Manager::Manager(QObject *parent) : Singleton<Manager>()
{
    Q_UNUSED(parent);
#ifdef QT_DEBUG
    env = "Development";
    hostUrl = new QUrl("http://localhost:3002/sandbox/v1");
#else
    env = "Production";
    hostUrl = new QUrl("http://localhost:3002/v1");
#endif
}

QString Manager::getCurrentEnv() const
{
    return env;
}

QUrl Manager::getCurrentHostUrl() const
{
    return *hostUrl;
}

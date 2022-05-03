#include "application/manager.h"

// this class will be manager of entire application
// will track of the current enviorment and other stuff.
Manager::Manager(CommonSuperClass *parent) : CommonSuperClass(parent)
{
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

Manager *Manager::createInstance()
{
    return new Manager();
}

Manager *Manager::instance()
{
    return  Singleton<Manager>::instance(Manager::createInstance);
}


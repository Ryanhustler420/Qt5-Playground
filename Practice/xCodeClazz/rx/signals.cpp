#include "rx/signals.h"

Signals::Signals(QWidget *parent) : OSingleton<Signals>()
{
    Q_UNUSED(parent);
}

void Signals::onApplicationLoading(std::function<void (bool)> callback)
{
    connect(this, &Signals::applicationLoading, this, [=](bool b){ callback(b); });
}

void Signals::onInternetStatusRefresh(std::function<void (bool)> callback)
{
    connect(this, &Signals::internetStatusRefreshed, this, [=](bool b){ callback(b); });
}

void Signals::onGoogleOAuthCodeReceive(std::function<void (QString)> callback)
{
    connect(this, &Signals::googleOAuthCodeReceive, this, [=](QString code){ callback(code); });
}

void Signals::onCourseDeleted(std::function<void (QJsonObject)> callback)
{
    connect(this, &Signals::deleteCourse, this, [=](QJsonObject o){ callback(o); });
}

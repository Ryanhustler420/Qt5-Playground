#include "rx/signals.h"

Signals::Signals(QWidget *parent) : OSingleton<Signals>()
{
    Q_UNUSED(parent);
}

void Signals::onInternetStatusRefresh(std::function<void (bool)> callback)
{
    connect(this, &Signals::internetStatusRefreshed, this, [=](bool b){ callback(b); });
}

void Signals::onGoogleOAuthCodeReceive(std::function<void (QString)> callback)
{
    connect(this, &Signals::googleOAuthCodeReceive, this, [=](QString code){ callback(code); });
}

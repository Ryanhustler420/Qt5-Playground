#include "rx/signals.h"

Signals::Signals(QWidget *parent) : WSingleton<Signals>()
{
    Q_UNUSED(parent);
}

void Signals::signalOneReceiver(std::function<void ()> callback)
{
    connect(this, &Signals::signalOne, this, [=](){ callback(); });
}

void Signals::signalTwoReceiver(std::function<void (int)> callback)
{
    connect(this, &Signals::signalTwo, this, [=](int a) { callback(a); });
}

#include "reactive.h"

Reactive::Reactive(QObject *parent) : Singleton<Reactive>()
{
    Q_UNUSED(parent);
}

void Reactive::signalOneReceiver(std::function<void ()> callback)
{
    connect(this, &Reactive::signalOne, this, [=](){ callback(); });
}

void Reactive::signalTwoReceiver(std::function<void (int)> callback)
{
    connect(this, &Reactive::signalTwo, this, [=](int a) { callback(a); });
}

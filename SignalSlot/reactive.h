#ifndef REACTIVE_H
#define REACTIVE_H

#include "singleton.h"
#include <QDebug>

class Reactive : public Singleton<Reactive>
{
    Q_OBJECT
public:
    explicit Reactive(QObject *parent = nullptr);

signals:
    void signalOne();
    void signalTwo(int a = 0);

public slots:
    void signalOneReceiver(std::function<void ()> callback);
    void signalTwoReceiver(std::function<void (int a)> callback);

};

#endif // REACTIVE_H

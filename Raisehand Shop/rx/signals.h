#ifndef SIGNALS_H
#define SIGNALS_H

#include "singleton/singleton_widget.h"
#include <QObject>

class Signals : public WSingleton<Signals>
{
    Q_OBJECT
public:
    explicit Signals(QWidget *parent = nullptr);

signals:
    void signalOne();
    void signalTwo(int a = 0);

public slots:
    void signalOneReceiver(std::function<void ()> callback);
    void signalTwoReceiver(std::function<void (int a)> callback);

};

#endif // SIGNALS_H

#ifndef TIMER_H
#define TIMER_H

#include <QObject>
#include <QTimer>
#include <QDebug>
#include <QTime>

#include <bits/stdc++.h>
#include <stdexcept>

using namespace std;
using namespace chrono;

class Timer : public QObject
{
    Q_OBJECT
public:
    explicit Timer(QObject *parent = nullptr);

    void simple_message();
    void wait_once(int ms);
    void wait_once(int ms, function<void()> callback);

    void startInterval();
    void timeout();

    // https://stackoverflow.com/a/62631757
    function<void()> debounced(function<void()>&f , int period);
signals:

private:
    QTimer timer;
    int number;

};

#endif // TIMER_H

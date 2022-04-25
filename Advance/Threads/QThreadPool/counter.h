#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRunnable>
#include <QRandomGenerator>

class counter : public QRunnable
{
public:
    void run();

};

#endif // COUNTER_H

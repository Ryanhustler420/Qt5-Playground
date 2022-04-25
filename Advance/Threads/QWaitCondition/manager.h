#ifndef MANAGER_H
#define MANAGER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QMutex>
#include <QWaitCondition>
#include "producer.h"
#include "consumer.h"

class Manager : public QObject
{
    Q_OBJECT
public:
    explicit Manager(QObject *parent = nullptr);

signals:

public slots:
    void start();
    void ready();

private:
    QList<int> data;
    QMutex mutex;
    QThread producerThread;
    QThread consumerThread;
    QWaitCondition condition;
    Producer producer;
    Consumer consumer;

};

#endif // MANAGER_H


#include "consumer.h"

Consumer::Consumer(QObject *parent) : QObject(parent)
{
    qInfo() << "Consumer Created on " << QThread::currentThread();

    thread.setObjectName("Timer Thread");
    //Qt::AutoConnection - runs on both
    //Qt::QueuedConnection - runs on main thread
    //Qt::DirectConnection - runs on thread
    //Qt::BlockingQueuedConnection - blocks
    //Qt::UniqueConnection - combined with others

    connect(&timer, &Timer::timeout,this, &Consumer::timeout,Qt::QueuedConnection);
    connect(&thread, &QThread::started,&timer, &Timer::started,Qt::QueuedConnection);
    connect(&thread, &QThread::finished,this, &Consumer::finished,Qt::QueuedConnection);
}

void Consumer::timeout()
{
    qInfo() << "Consumer timeout on " << QThread::currentThread();
    thread.quit();
}

void Consumer::start()
{
    qInfo() << "Consumer Started On " << QThread::currentThread();
    timer.setInterval(500);
    timer.moveToThread(&thread);
    thread.start();
}

void Consumer::finished()
{
    qInfo() << "Thread finished on " << QThread::currentThread();
}

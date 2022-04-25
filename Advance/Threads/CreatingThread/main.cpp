#include <QCoreApplication>
#include <QThread>
#include <QDebug>
#include <QSharedPointer>
#include "test.h"

static QSharedPointer<QThread> sptr;
void timeout() {
    if (!sptr.isNull()) {
        qInfo() << "Timeout stopping other thread from: " << QThread::currentThread();
        sptr.data()->quit(); // or .terminate();
    }
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "Application Thread: " << a.thread();
    qInfo() << "Current Thread: " << QThread::currentThread();

    // test t(&a); // you should not provide parent, it will not work, even if it will work, you have to manage your memory on your own
    test t;
    qInfo() << "Timer Thread (before): " << t.thread();

    QThread thread;
    sptr.reset(&thread);

    t.moveToThread(&thread); // move to another thread
    qInfo() << "Timer Thread (after): " << t.thread();

    t.start();
    qInfo() << "Thread State: " << thread.isRunning();
    thread.start();

    QTimer timer;
    timer.singleShot(5000, &timeout);

    return a.exec();
}

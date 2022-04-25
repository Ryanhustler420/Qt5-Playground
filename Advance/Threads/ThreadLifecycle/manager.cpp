#include "manager.h"

manager::manager(QObject *parent) : QObject(parent)
{
    for (int var = 0; var < 5; ++var) {
        QThread* thread = new QThread(this);
        thread->setObjectName("Thread " + QString::number(var));
        qInfo() << "Created: " << thread->objectName();

        connect(thread, &QThread::started, this, &manager::started);
        connect(thread, &QThread::finished, this, &manager::finished);

        threads.append(thread);
    }
}

void manager::start()
{
    qInfo() << "Starting...";
    foreach (QThread * thread, threads) {
        qInfo() << "Starting: " << thread->objectName();
        counter * c = new counter(); // SHOULD NOT HAVE ANY PARENT!!! counter * c = new counter(true);
        c->moveToThread(thread);
        // c->start(); // single thread!!!

        connect(thread, &QThread::started, c, &counter::start);
        thread->start();
    }
}

void manager::started()
{
    QThread * thread = qobject_cast<QThread *>(sender());
    if (!thread) return;
    qInfo() << "Started: " << thread -> objectName();
}

void manager::finished()
{
    QThread * thread = qobject_cast<QThread *>(sender());
    if (!thread) return;
    qInfo() << "Finished: " << thread -> objectName();
}

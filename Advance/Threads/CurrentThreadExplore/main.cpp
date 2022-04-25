#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QDateTime>

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    qInfo() << "App Thread: " << a.thread();
    qInfo() << "Current Thread: " << QThread::currentThread();

    Q_ASSERT(a.thread() == QThread::currentThread());

    qInfo () << "Running: " << QThread::currentThread()->isRunning();
    qInfo () << "Loop Level: " << QThread::currentThread()->loopLevel();
    qInfo () << "Stack Size: " << QThread::currentThread()->stackSize();
    qInfo () << "is Finished: " << QThread::currentThread()->isFinished();

    qInfo () << "Before: " << QDateTime::currentDateTime().toString();
    QThread::sleep(5);
    qInfo () << "After: " << QDateTime::currentDateTime().toString();

    return a.exec();
}

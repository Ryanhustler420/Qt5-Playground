#include <QCoreApplication>
#include <QDebug>
#include <QThread>
#include <QtConcurrent>
#include <QFuture>
#include <QFutureSynchronizer>

void doStuff(int value) {
    for (int var = 0; var < 10; ++var) {
        QThread::currentThread()->msleep(100);
        qInfo() << "Thread: " << value << " = " << var;
    }
}

void runthread() {
    QFutureSynchronizer <void> sync;
    for (int var = 0; var < 10; ++var) {
        QFuture<void> f = QtConcurrent::run(&doStuff, var);
        sync.addFuture(f);
    }
    // waitForFinished called in the QFutureSynchronizer deconstructor
    // sync.waitForFinished();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    runthread();
    qInfo() << "Done";

    return a.exec();
}

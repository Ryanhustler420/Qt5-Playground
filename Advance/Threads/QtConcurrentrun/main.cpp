#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent/QtConcurrent>
#include <QThread>
#include <QThreadPool>

// At Concurrent - Feature
// ADD QT += concurrent to .pro file

void loop() {
    for (int var = 0; var < 10; ++var) {
        qInfo() << "Loop" << var << " on: " << QThread::currentThread();
    }
}

void test() {
    qInfo() << "Test on: " << QThread::currentThread();
    loop();
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QThread::currentThread()->setObjectName("Main");

    QThreadPool pool;
    QFuture<void> future = QtConcurrent::run(&pool, test);
    qInfo() << "Main on: " << QThread::currentThread();
    loop();

    return a.exec();
}

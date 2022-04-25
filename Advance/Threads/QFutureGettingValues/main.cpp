#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QList>
#include <QtConcurrent/QtConcurrent>

int multiply (const int &value) {
    qInfo() << "Called: " << value;
    return value * 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int var = 0; var < 100; ++var) {
        list.append(var);
    }

    QFutureWatcher<int> watcher;

    QFuture<int> future = QtConcurrent::mapped(list, &multiply);
    watcher.setFuture(future);
    qInfo() << "Back in main";

    watcher.waitForFinished();

    qInfo() << "Done!";
    qInfo() << future.results();

    return a.exec();
}

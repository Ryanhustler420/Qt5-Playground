#include <QCoreApplication>
#include <QDebug>
#include <QFuture>
#include <QFutureWatcher>
#include <QList>
#include <QtConcurrent/QtConcurrent>

void multiply (int &value) {
    qInfo() << "Called: " << value;
    value = value * 10;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int var = 0; var < 100; ++var) {
        list.append(var);
    }

    QFutureWatcher<void> watcher;

    QFuture<void> future = QtConcurrent::map(list, &multiply);
    watcher.setFuture(future);
    qInfo() << "Back in main";

    watcher.waitForFinished();

    qInfo() << "Done!";
    qInfo() << list;

    return a.exec();
}

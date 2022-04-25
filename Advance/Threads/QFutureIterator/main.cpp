#include <QCoreApplication>
#include <QDebug>
#include <QtConcurrent>
#include <QFuture>
#include <QList>
#include <QFutureIterator>

int multiply(const int &value)
{
    qInfo() << "Called: " << value;
    int num = value * 10;
    return num;
}

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QList<int> list;
    for (int i = 0;i < 100;i++)
    {
        list.append(i);
    }

    //Do stuff async
    QFutureWatcher<int> watcher;
    QFuture<int> future = QtConcurrent::mapped(list,&multiply);
    watcher.setFuture(future);

    //So normal stuff

    watcher.waitForFinished();

    //Java style
    QFutureIterator<int> iter(future);
    while (iter.hasNext())
    {
        qInfo() << "Java: " << iter.next();
    }

    //Index style
    for (int i = 0;i < future.results().length();i++)
    {
        qInfo() << "Index: " << future.resultAt(i);
    }

    //Qt style
    foreach(int i, future.results())
    {
        qInfo() << "Qt: " << i;
    }

    //STL - DOES NOT LIKE FUTURES!!!
    QList<int> values = future.results();
    for (auto i = values.begin();i < values.end();i++)
    {
        qInfo() << "STL: " << *i;
    }

    qInfo() << "Done";

    return a.exec();
}

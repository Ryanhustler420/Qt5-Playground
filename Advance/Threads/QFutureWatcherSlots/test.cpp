#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    //Connect
    /*
    void canceled();
    void finished();
    void paused();
    void progressRangeChanged(int minimum, int maximum);
    void progressTextChanged(const QString &progressText);
    void progressValueChanged(int progressValue);
    void resultReadyAt(int index);
    void resultsReadyAt(int beginIndex, int endIndex);
    void resumed();
    void started();
    */

    connect(&watcher, &QFutureWatcher<void>::canceled, this, &test::canceled);
    connect(&watcher, &QFutureWatcher<void>::finished, this, &test::finished);
    connect(&watcher, &QFutureWatcher<void>::paused, this, &test::paused);
    connect(&watcher, &QFutureWatcher<void>::progressRangeChanged, this, &test::progressRangeChanged);
    connect(&watcher, &QFutureWatcher<void>::progressTextChanged, this, &test::progressTextChanged);
    connect(&watcher, &QFutureWatcher<void>::progressValueChanged, this, &test::progressValueChanged);
    connect(&watcher, &QFutureWatcher<void>::resultReadyAt, this, &test::resultReadyAt);
    connect(&watcher, &QFutureWatcher<void>::resumed, this, &test::resumed);
    connect(&watcher, &QFutureWatcher<void>::started, this, &test::started);
}

void test::process()
{
    QMutex mutex;
    mutex.lock();

    list.clear();
    for (int i = 0;i < 100; i++)
    {
        list.append(i);
    }
    mutex.unlock();

    future = QtConcurrent::map(list,&test::multiply);
    watcher.setFuture(future);
}

void test::multiply(int &value)
{
    qInfo() << "Called: " << value;

    value = value * 10;

    //Slow things down
    QThread::currentThread()->msleep(250);
}

void test::canceled()
{
    qInfo() << "Canceled";
}

void test::finished()
{
    qInfo() << "Finished";
    qInfo() << list;
}

void test::paused()
{
    qInfo() << "Paused";
}

void test::progressRangeChanged(int minimum, int maximum)
{
    qInfo() << "Range " << minimum << " to " << maximum;
}

void test::progressTextChanged(const QString &progressText)
{
    qInfo() << "Text: " << progressText;
}

void test::progressValueChanged(int progressValue)
{
    qInfo() << "Progress: " << progressValue;
}

void test::resultReadyAt(int index)
{
    qInfo() << "ReadyAt: " << index;
}

void test::resultsReadyAt(int beginIndex, int endIndex)
{
    qInfo() << "ResultsReadyAt " << beginIndex << " to " << endIndex;
}

void test::resumed()
{
    qInfo() << "Resumed";
}

void test::started()
{
    qInfo() << "Started";
}

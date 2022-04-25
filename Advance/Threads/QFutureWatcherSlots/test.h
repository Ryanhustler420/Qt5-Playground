#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDebug>
#include <QMutex>
#include <QThread>
#include <QFuture>
#include <QtConcurrent>
#include <QFutureWatcher>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

    void process();
    static void multiply(int &value);

signals:

public slots:
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

private:
    QFutureWatcher<void> watcher;
    QFuture<void> future;
    QList<int> list;
};

#endif // TEST_H

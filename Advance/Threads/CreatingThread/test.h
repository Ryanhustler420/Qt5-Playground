#ifndef TEST_H
#define TEST_H

#include <QObject>
#include <QDateTime>
#include <QThread>
#include <QTimer>
#include <QDebug>

class test : public QObject
{
    Q_OBJECT
public:
    explicit test(QObject *parent = nullptr);

signals:

public slots:
    void timeout();
    void start();

private:
    QTimer timer;

};

#endif // TEST_H

#ifndef COUNTER_H
#define COUNTER_H

#include <QObject>
#include <QDebug>
#include <QThread>
#include <QRandomGenerator>

class counter : public QObject
{
    Q_OBJECT
public:
    explicit counter(QObject *parent = nullptr);

signals:

public slots:
    void start();

};

#endif // COUNTER_H

#ifndef THREADS_H
#define THREADS_H

#include "parents/commonsuperclass.h"
#include "utility/timer.h"

#include <QFutureIterator>
#include <QtConcurrent>
#include <QFuture>

class Threads : public CommonSuperClass
{
    Q_OBJECT
public:
    explicit Threads(CommonSuperClass *parent = nullptr);
    void example();

signals:

};

#endif // THREADS_H

#include "test.h"

test::test(QObject *parent) : QThread(parent)
{
    // we are not modifing the behavior of thread.. it will work just fine
}

void test::quit()
{
    ok = false;
    QThread::quit();
}

void test::run()
{
    ok = true;
    for (int var = 0; var < 1000; ++var) {
        qInfo() << var;
        this->sleep(1);
        // this is bad because now code become unpredictable
        // control can come from anywhere

        if (!ok) break;
    }

    qInfo() << "Finished";
}

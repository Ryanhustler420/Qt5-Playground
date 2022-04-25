#include "test.h"

test::test(QObject *parent) : QObject(parent)
{
    qDebug() << this << "This is a bullshit!!";
}

void test::run()
{
    qWarning() << "This is a test!!";
}

#include "test.h"

test::test(QObject *parent) : QObject(parent)
{

}

void test::doStuff()
{

}

void test::doStuff(QString param)
{
    Q_UNUSED(param);
}

void test::myslot()
{

}

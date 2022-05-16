#include "cppsignalsender.h"

CppSignalSender::CppSignalSender(QObject *parent) : QObject(parent),
    mTimer(new QTimer(parent)),
    mValue(0)
{
    connect(mTimer, &QTimer::timeout, [=](){
        ++mValue;
        emit cppTimer(QString::number(mValue));
    });
    mTimer->start(1000);
}

void CppSignalSender::cppSlot()
{
    emit callQml("Information From Cpp");
}

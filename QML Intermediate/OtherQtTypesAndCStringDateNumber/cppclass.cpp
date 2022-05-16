#include "cppclass.h"

CppClass::CppClass(QObject *parent) : QObject(parent)
{

}

void CppClass::cppSlot()
{
    qInfo() << "C++ here, cppSlot() called";
    emit sendTime(QTime::currentTime());
    emit sendDateTime(QDateTime::currentDateTime());
}

void CppClass::timeSlot(QTime time)
{
    qDebug() << "Time from QML is: " << time;
}

void CppClass::dateTimeSlot(QDateTime dateTime)
{
    qDebug() << "DateTime from QML is : "<< dateTime;
}

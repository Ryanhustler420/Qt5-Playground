#include <QDebug>
#include "cppworker.h"

CppWorker::CppWorker(QObject *parent) : QObject(parent)
{

}

void CppWorker::regularMethod()
{
    qInfo() << "This is c++ talking, reglarMethod called.";
}

QString CppWorker::regularMethodWithReturn(QString name, int age)
{
    return QString(name + ":" + QString::number(age) + " years old");
}

void CppWorker::cppSlot()
{
    qDebug() << "This is c++ talking, cppSlot called.";
}

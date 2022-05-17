#include "cppclass.h"

CppClass::CppClass(QObject *parent) : QObject(parent)
{
    mVector.append("One");
    mVector.append("Two");
    mVector.append("Three");
    mVector.append("Four");
}

void CppClass::qmlArrayToCpp(QVector<QString> vactor)
{
    foreach (QString string, vactor) {
        qDebug() << string;
    }
}

QVector<QString> CppClass::retrieveStrings()
{
    return mVector;
}

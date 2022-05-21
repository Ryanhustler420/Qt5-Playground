#include "modelconventions.h"

template<typename T>
QList<QString> ModelConventions<T>::parseOnlyStringJSONArray(QJsonArray o) throw()
{
    Q_UNUSED(o);
    QList<QString> list;
    return list;
}

template<typename T>
QList<double> ModelConventions<T>::parseOnlyDoubleJSONArray(QJsonArray o) throw()
{
    Q_UNUSED(o);
    QList<double> list;
    return list;
}

template<typename T>
QList<long> ModelConventions<T>::parseOnlyLongJSONArray(QJsonArray o) throw()
{
    Q_UNUSED(o);
    QList<long> list;
    return list;
}

template<typename T>
QList<int> ModelConventions<T>::parseOnlyIntegerJSONArray(QJsonArray o) throw()
{
    Q_UNUSED(o);
    QList<int> list;
    return list;
}

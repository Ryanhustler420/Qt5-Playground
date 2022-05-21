#ifndef MODELCONVENTIONS_H
#define MODELCONVENTIONS_H

#include <QObject>
#include <QVector>
#include <QList>
#include "utility/jsonhelper.h"

template<typename T>
class ModelConventions : public QObject
{
public:
    QList<QString> parseOnlyStringJSONArray(QJsonArray o) throw();
    QList<double> parseOnlyDoubleJSONArray(QJsonArray o) throw();
    QList<long> parseOnlyLongJSONArray(QJsonArray o) throw();
    QList<int> parseOnlyIntegerJSONArray(QJsonArray o) throw();

protected:
    QString className;
    int const fallbackZero = 0;
    QString const fallbackValue = nullptr;
    QVector<int> const fallbackIntArray;
    QString const fallbackTime = "1997-07-21T12:09:43.233Z";

public:
    // You have to implement these methods in child class else you will get error
    virtual QList<QString> getAllFields() = 0;
    virtual QString getPackageName() = 0;

    virtual QList<T*> parseJSONArray(QJsonArray o) throw() = 0;
    virtual T* parseJSONObject(QJsonObject o) throw() = 0;
    virtual QList<T*> parseArrayString(QString o) throw() = 0;
    virtual T* parseObjectString(QString o) throw() = 0;

    virtual bool equal(T* o) = 0;
    virtual void copy(T *o) = 0;
};

#endif // MODELCONVENTIONS_H

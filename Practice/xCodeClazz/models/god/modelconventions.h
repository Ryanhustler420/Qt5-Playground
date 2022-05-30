#ifndef MODELCONVENTIONS_H
#define MODELCONVENTIONS_H

#include <QObject>
#include <QVector>
#include <QList>
#include "utility/jsonhelper.h"
#include "utility/mongoservice.h"
#include "utility/exceptionthrow.h"

// Please don't use explicit construtor of child class
template<typename T>
class ModelConventions : public QObject
{
public:
    QList<QString> *parseOnlyStringJSONArray(QJsonArray o) throw()
    {
        QList<QString> *list = new QList<QString>();
        for (int i = 0; i < o.size(); i++)
            list->append(o.at(i).toString());
        return list;
    }
    QList<double> *parseOnlyDoubleJSONArray(QJsonArray o) throw()
    {
        QList<double> *list = new QList<double>();
        for (int i = 0; i < o.size(); i++)
            list->append(o.at(i).toDouble());
        return list;
    }
    QList<long> *parseOnlyLongJSONArray(QJsonArray o) throw()
    {
        QList<long> *list = new QList<long>();
        for (int i = 0; i < o.size(); i++)
            list->append(o.at(i).toDouble());
        return list;
    }
    QList<int> *parseOnlyIntegerJSONArray(QJsonArray o) throw()
    {
        QList<int> *list = new QList<int>();
        for (int i = 0; i < o.size(); i++)
            list->append(o.at(i).toInt());
        return list;
    }

protected:
    QString className;
    int const fallbackZero = 0;
    QString const fallbackValue = nullptr;
    QVector<int> const fallbackIntArray;
    QString const fallbackTime = "1997-07-21T12:09:43.233Z";

public:
    MongoService mongo;
    JsonHelper json;

public:
    // You have to implement these methods in child class else you will get error
    virtual QList<QString> getAllFields() = 0;
    virtual QString getPackageName() = 0;

    virtual QList<T*> parseJSONArray(QJsonArray o) throw(ExceptionThrow) = 0;
    virtual QVariantList parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow) = 0;
    virtual T* parseJSONObject(QJsonObject o) throw(ExceptionThrow) = 0;
    virtual QVariant parseJSONObjectToVariant(QJsonObject o) = 0;
    virtual QJsonArray getAsJsonArray(QList<T> *t) const = 0;
    virtual QJsonObject getAsJson() const = 0;

    virtual bool equal(T* o) = 0;
    virtual void copy(T *o) = 0;
};

#endif // MODELCONVENTIONS_H

#include "models/counter.h"

Counter::Counter(int v, long count, const QString &id, const QString &name, const QString &countryName, const QString &language, const QString &countryISOCode, const QString &currencyCode, const QString &createdAt, const QString &updatedAt)
{
    this->__v = v;
    this->count = count;
    this->_id = id;
    this->name = name;
    this->countryName = countryName;
    this->language = language;
    this->countryISOCode = countryISOCode;
    this->currencyCode = currencyCode;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "Counter";
    this->fields = new _fields();
}

const QString &Counter::getUpdatedAt() const
{
    return updatedAt;
}

void Counter::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

const QString &Counter::getCreatedAt() const
{
    return createdAt;
}

void Counter::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &Counter::getCurrencyCode() const
{
    return currencyCode;
}

void Counter::setCurrencyCode(const QString &newCurrencyCode)
{
    currencyCode = newCurrencyCode;
}

const QString &Counter::getCountryISOCode() const
{
    return countryISOCode;
}

void Counter::setCountryISOCode(const QString &newCountryISOCode)
{
    countryISOCode = newCountryISOCode;
}

const QString &Counter::getLanguage() const
{
    return language;
}

void Counter::setLanguage(const QString &newLanguage)
{
    language = newLanguage;
}

const QString &Counter::getCountryName() const
{
    return countryName;
}

void Counter::setCountryName(const QString &newCountryName)
{
    countryName = newCountryName;
}

const QString &Counter::getName() const
{
    return name;
}

void Counter::setName(const QString &newName)
{
    name = newName;
}

const QString &Counter::id() const
{
    return _id;
}

void Counter::setId(const QString &newId)
{
    _id = newId;
}

long Counter::getCount() const
{
    return count;
}

void Counter::setCount(long newCount)
{
    count = newCount;
}

int Counter::v() const
{
    return __v;
}

void Counter::setV(int newV)
{
    __v = newV;
}

QList<QString> Counter::getAllFields()
{

}

QString Counter::getPackageName()
{
    return this->className;
}

QList<Counter *> Counter::parseJSONArray(QJsonArray o) throw()
{

}

Counter *Counter::parseJSONObject(QJsonObject o) throw()
{

}

QList<Counter *> Counter::parseArrayString(QString o) throw()
{

}

Counter *Counter::parseObjectString(QString o) throw()
{

}

bool Counter::equal(Counter *o)
{
    return o == this;
}

QList<Counter> Counter::getAllCountersOfCountry(QList<Counter> *counters, QString countryName)
{

}

QString Counter::getPolishedCounterName()
{

}

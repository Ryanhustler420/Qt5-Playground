#include "models/country/country.h"

Country::Country(bool active, const QString &name) : active(active),
    name(name)
{
    this->className = "Country";
    this->fields = new _fields();
    this->countries = new _countries();
}

QList<State> *Country::getStates() const
{
    return states;
}

void Country::setStates(QList<State> *newStates)
{
    states = newStates;
}

const QString &Country::getName() const
{
    return name;
}

void Country::setName(const QString &newName)
{
    name = newName;
}

bool Country::getActive() const
{
    return active;
}

void Country::setActive(bool newActive)
{
    active = newActive;
}

QList<QString> Country::getAllFields()
{

}

QString Country::getPackageName()
{
    return this->className;
}

QList<Country *> Country::parseJSONArray(QJsonArray o) throw()
{

}

Country *Country::parseJSONObject(QJsonObject o) throw()
{

}

QList<Country *> Country::parseArrayString(QString o) throw()
{

}

Country *Country::parseObjectString(QString o) throw()
{

}

bool Country::equal(Country *o)
{
    return o == this;
}

Country Country::getDummyCountry()
{

}

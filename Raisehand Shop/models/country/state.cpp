#include "models/country/state.h"

State::State(const QString &name, QList<QString> *cities)
{
    this->name = name;
    this->cities = cities;
    this->className = "State";
    this->fields = new _fields();
}

const QList<QString> &State::getCities() const
{
    return *cities;
}

void State::setCities(const QList<QString> &newCities)
{
    *cities = newCities;
}

const QString &State::getName() const
{
    return name;
}

void State::setName(const QString &newName)
{
    name = newName;
}

State State::getDummyState()
{

}

QString State::getDummyCity()
{

}


QList<QString> State::getAllFields()
{

}

QString State::getPackageName()
{
    return this->className;
}

QList<State *> State::parseJSONArray(QJsonArray o) throw()
{

}

State *State::parseJSONObject(QJsonObject o) throw()
{

}

QList<State *> State::parseArrayString(QString o) throw()
{

}

State *State::parseObjectString(QString o) throw()
{

}

bool State::equal(State *o)
{
    return o == this;
}

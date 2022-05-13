#include "models/location.h"

Location::Location(const QString &type, QList<double> *coordinates)
{
    this->type = type;
    this->coordinates = coordinates;
    this->className = "Location";
    this->fields = new _fields();
}

QList<QString> Location::getAllFields()
{

}

QString Location::getPackageName()
{
    return this->className;
}

QList<Location *> Location::parseJSONArray(QJsonArray o) throw()
{

}

Location *Location::parseJSONObject(QJsonObject o) throw()
{

}

QList<Location *> Location::parseArrayString(QString o) throw()
{

}

Location *Location::parseObjectString(QString o) throw()
{

}

bool Location::equal(Location *o)
{
    return o == this;
}

QList<double> *Location::getCoordinates() const
{
    return coordinates != nullptr ? coordinates : new QList<double>();
}

void Location::setCoordinates(QList<double> *newCoordinates)
{
    coordinates = newCoordinates;
}

Coordinates* Location::turnCoordinated()
{
    Coordinates *coordinates = new Coordinates(0.0, 0.0);
    if (getCoordinates()->size() >= 2) {
        coordinates->setLng(getCoordinates()->at(0));
        coordinates->setLat(getCoordinates()->at(1));
    }
    return coordinates;
}

const QString &Location::getType() const
{
    return type;
}

void Location::setType(const QString &newType)
{
    type = newType;
}

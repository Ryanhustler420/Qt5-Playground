#include "models/coordinates.h"

Coordinates::Coordinates(double lat, double lng)
{
    this->lat = lat;
    this->lng = lng;
    this->className = "Coordinates";
    this->fields = new _fields();
}

QList<QString> Coordinates::getAllFields()
{

}

QString Coordinates::getPackageName()
{
    return this->className;
}

QList<Coordinates *> Coordinates::parseJSONArray(QJsonArray o) throw()
{

}

Coordinates *Coordinates::parseJSONObject(QJsonObject o) throw()
{

}

QList<Coordinates *> Coordinates::parseArrayString(QString o) throw()
{

}

Coordinates *Coordinates::parseObjectString(QString o) throw()
{

}

bool Coordinates::equal(Coordinates *o)
{
    return o == this;
}

double Coordinates::getLng() const
{
    return lng;
}

void Coordinates::setLng(double newLng)
{
    lng = newLng;
}

double Coordinates::getLat() const
{
    return lat;
}

void Coordinates::setLat(double newLat)
{
    lat = newLat;
}

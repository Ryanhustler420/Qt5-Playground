#include "models/plans/endpoint.h"

EndPoint::EndPoint(const QString &endpoint, QList<QString> *pleaseSend)
{
    this->className = "EndPoint";
    this->endpoint = endpoint;
    this->pleaseSend = pleaseSend;

    this->fields = new _fields();
}

void EndPoint::setEndpoint(const QString &newEndpoint)
{
    endpoint = newEndpoint;
}

QString EndPoint::getEndpoint() const
{
    return endpoint;
}

QList<QString> *EndPoint::getPleaseSend() const
{
    return pleaseSend;
}

void EndPoint::setPleaseSend(QList<QString> *newPleaseSend)
{
    pleaseSend = newPleaseSend;
}

QList<QString> EndPoint::getAllFields()
{

}

QString EndPoint::getPackageName()
{
    return this->className;
}

QList<EndPoint *> EndPoint::parseJSONArray(QJsonArray o) throw()
{

}

EndPoint *EndPoint::parseJSONObject(QJsonObject o) throw()
{

}

QList<EndPoint *> EndPoint::parseArrayString(QString o) throw()
{

}

EndPoint *EndPoint::parseObjectString(QString o) throw()
{

}

bool EndPoint::equal(EndPoint *o)
{
    return o == this;
}

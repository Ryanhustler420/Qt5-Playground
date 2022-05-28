#include "models/session.h"

Session::Session(QObject *parent)
{
    this->className = "Session";
    this->fields = new _fields();
}

Session::Session(const QString &starts, const QString &ends)
{
    this->starts = starts;
    this->ends = ends;

    this->className = "Session";
    this->fields = new _fields();
}

const QString &Session::getEnds() const
{
    return ends;
}

void Session::setEnds(const QString &newEnds)
{
    ends = newEnds;
}

const QString &Session::getStarts() const
{
    return starts;
}

void Session::setStarts(const QString &newStarts)
{
    starts = newStarts;
}

QList<QString> Session::getAllFields()
{

}

QString Session::getPackageName()
{
    return this->className;
}

QList<Session *> Session::parseJSONArray(QJsonArray o) throw()
{

}

QVariantList Session::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

Session *Session::parseJSONObject(QJsonObject o) throw()
{

}

QVariant Session::parseJSONObjectToVariant(QJsonObject o)
{

}

bool Session::equal(Session *o)
{
    return o == this;
}

void Session::copy(Session *o)
{
    this->starts = o->starts;
    this->ends = o->ends;
}

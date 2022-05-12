#include "models/siunit.h"

SiUnit::SiUnit(const QString &id, const QString &title)
{
    this->_id = id;
    this->title = title;
    this->className = "SiUnit";
    this->fields = new _fields();
}

const QString &SiUnit::getId() const
{
    return _id;
}

void SiUnit::setId(const QString &newId)
{
    _id = newId;
}

const QString &SiUnit::getTitle() const
{
    return title;
}

void SiUnit::setTitle(const QString &newTitle)
{
    title = newTitle;
}

QList<QString> SiUnit::getAllFields()
{

}

QString SiUnit::getPackageName()
{
    return this->className;
}

QList<SiUnit *> SiUnit::parseJSONArray(QJsonArray o) throw()
{

}

SiUnit *SiUnit::parseJSONObject(QJsonObject o) throw()
{

}

QList<SiUnit *> SiUnit::parseArrayString(QString o) throw()
{

}

SiUnit *SiUnit::parseObjectString(QString o) throw()
{

}

bool SiUnit::equal(SiUnit *o)
{
    return o == this;
}

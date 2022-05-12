#include "models/repo_product/tag.h"

Tag::Tag(const QString &title)
{
    this->title = title;
    this->className = "Tag";
    this->fields = new _fields();
}

const QString &Tag::getTitle() const
{
    return title;
}

void Tag::setTitle(const QString &newTitle)
{
    title = newTitle;
}

QList<QString> Tag::getAllFields()
{

}

QString Tag::getPackageName()
{
    return this->className;
}

QList<Tag *> Tag::parseJSONArray(QJsonArray o) throw()
{

}

Tag *Tag::parseJSONObject(QJsonObject o) throw()
{

}

QList<Tag *> Tag::parseArrayString(QString o) throw()
{

}

Tag *Tag::parseObjectString(QString o) throw()
{

}

bool Tag::equal(Tag *o)
{
    return o == this;
}

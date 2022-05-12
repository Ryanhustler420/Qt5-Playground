#include "models/product_repository/contributor.h"

Contributor::Contributor(const QString &id, const QString &name, const QString &imageUrl, const QString &imageContainer)
{
    this->_id = (id);
    this->name = (name);
    this->imageUrl = (imageUrl);
    this->imageContainer = (imageContainer);

    this->className = "Contributor";
    this->fields = new _fields();
}

bool Contributor::equal(Contributor *o)
{
    return o == this;
}

const QString &Contributor::getImageContainer() const
{
    return imageContainer;
}

void Contributor::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &Contributor::getImageUrl() const
{
    return imageUrl;
}

void Contributor::setImageUrl(const QString &newImageUrl)
{
    imageUrl = newImageUrl;
}

const QString &Contributor::getName() const
{
    return name;
}

void Contributor::setName(const QString &newName)
{
    name = newName;
}

const QString &Contributor::id() const
{
    return _id;
}

void Contributor::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> Contributor::getAllFields()
{

}

QString Contributor::getPackageName()
{
    return this->className;
}

QList<Contributor *> Contributor::parseJSONArray(QJsonArray o) throw()
{

}

Contributor *Contributor::parseJSONObject(QJsonObject o) throw()
{

}

QList<Contributor *> Contributor::parseArrayString(QString o) throw()
{

}

Contributor *Contributor::parseObjectString(QString o) throw()
{

}

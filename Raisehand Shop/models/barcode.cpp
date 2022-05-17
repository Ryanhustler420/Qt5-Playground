#include "models/barcode.h"

Barcode::Barcode(const QString &id, long barcode, bool isVerified, const QString &repoProduct, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->barcode = barcode;
    this->isVerified = isVerified;
    this->repoProduct = repoProduct;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "Barcode";
    this->fields = new _fields();
}

bool Barcode::getIsVerified() const
{
    return isVerified;
}

void Barcode::setIsVerified(bool newIsVerified)
{
    isVerified = newIsVerified;
}

const QString &Barcode::getRepoProduct() const
{
    return repoProduct;
}

void Barcode::setRepoProduct(const QString &newRepoProduct)
{
    repoProduct = newRepoProduct;
}

const QString &Barcode::getCreatedAt() const
{
    return createdAt;
}

void Barcode::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &Barcode::getUpdatedAt() const
{
    return updatedAt;
}

void Barcode::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

void Barcode::setBarcode(long newBarcode)
{
    barcode = newBarcode;
}

const long &Barcode::getBarcode() const
{
    return barcode;
}

const QString &Barcode::id() const
{
    return _id;
}

void Barcode::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> Barcode::getAllFields()
{

}

QString Barcode::getPackageName()
{
    return this->className;
}

QList<Barcode *> Barcode::parseJSONArray(QJsonArray o) throw()
{

}

Barcode *Barcode::parseJSONObject(QJsonObject o) throw()
{

}

QList<Barcode *> Barcode::parseArrayString(QString o) throw()
{

}

Barcode *Barcode::parseObjectString(QString o) throw()
{

}

bool Barcode::equal(Barcode *o)
{
    return o == this;
}

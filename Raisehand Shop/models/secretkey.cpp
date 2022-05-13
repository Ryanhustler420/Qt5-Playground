#include "models/secretkey.h"

SecretKey::SecretKey(const QString &key, const QString &value)
{
    this->key = key;
    this->value = value;

    this->className = "SecretKey";
    this->fields = new _fields();
}

QList<QString> SecretKey::getAllFields()
{

}

QString SecretKey::getPackageName()
{
    return this->className;
}

QList<SecretKey *> SecretKey::parseJSONArray(QJsonArray o) throw()
{

}

SecretKey *SecretKey::parseJSONObject(QJsonObject o) throw()
{

}

QList<SecretKey *> SecretKey::parseArrayString(QString o) throw()
{

}

SecretKey *SecretKey::parseObjectString(QString o) throw()
{

}

bool SecretKey::equal(SecretKey *o)
{
    return o == this;
}

#include "models/repo_product/repoproduct.h"

QString RepoProduct::getEncryptedData()
{

}

QList<int> RepoProduct::getActionTypes()
{

}

QString RepoProduct::encode()
{

}

QList<QString> RepoProduct::getAllFields()
{

}

QString RepoProduct::getPackageName()
{
    return this->className;
}

QList<RepoProduct *> RepoProduct::parseJSONArray(QJsonArray o) throw()
{

}

RepoProduct *RepoProduct::parseJSONObject(QJsonObject o) throw()
{

}

QList<RepoProduct *> RepoProduct::parseArrayString(QString o) throw()
{

}

RepoProduct *RepoProduct::parseObjectString(QString o) throw()
{

}

bool RepoProduct::equal(RepoProduct *o)
{
    return o == this;
}

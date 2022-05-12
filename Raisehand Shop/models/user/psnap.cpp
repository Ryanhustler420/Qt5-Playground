#include "models/user/psnap.h"

PSnap::PSnap(const QString &repoProduct, long repoProduct_Snapshot, const QString &postFix, const QString &createdAt)
{
    this->repoProduct = repoProduct;
    this->repoProduct_Snapshot = repoProduct_Snapshot;
    this->postFix = postFix;
    this->createdAt = createdAt;

    this->className = "PSnap";
    this->fields = new _fields();
}

const QString &PSnap::getCreatedAt() const
{
    return createdAt;
}

void PSnap::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &PSnap::getPostFix() const
{
    return postFix;
}

void PSnap::setPostFix(const QString &newPostFix)
{
    postFix = newPostFix;
}

long PSnap::getRepoProductSnapshot() const
{
    return repoProduct_Snapshot;
}

void PSnap::setRepoProductSnapshot(long newRepoProduct_Snapshot)
{
    repoProduct_Snapshot = newRepoProduct_Snapshot;
}

const QString &PSnap::getRepoProduct() const
{
    return repoProduct;
}

void PSnap::setRepoProduct(const QString &newRepoProduct)
{
    repoProduct = newRepoProduct;
}

QList<QString> PSnap::getAllFields()
{

}

QString PSnap::getPackageName()
{
    return this->className;
}

QList<PSnap *> PSnap::parseJSONArray(QJsonArray o) throw()
{

}

PSnap *PSnap::parseJSONObject(QJsonObject o) throw()
{

}

QList<PSnap *> PSnap::parseArrayString(QString o) throw()
{

}

PSnap *PSnap::parseObjectString(QString o) throw()
{

}

bool PSnap::equal(PSnap *o)
{
    return o == this;
}

bool PSnap::hasPostFix() const
{
    return getPostFix() != nullptr && !getPostFix().compare("null");
}

const QString PSnap::getFormattedProductSnapshot() const
{
    return this->hasPostFix() ? QString("#%1%2%3").arg(getRepoProductSnapshot()).arg(SNAPSHOT_SEPARATOR).arg(getPostFix())
                              : QString("#%1").arg(getRepoProductSnapshot());
}

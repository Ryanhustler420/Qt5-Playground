#ifndef EACHCONTRIBUTEDPRODUCT_H
#define EACHCONTRIBUTEDPRODUCT_H

#include "models/god/modelconventions.h"

class EachContributedProduct : public ModelConventions<EachContributedProduct>
{
    Q_OBJECT
public:
    explicit EachContributedProduct(QObject *parent = nullptr);
    EachContributedProduct(const QString &postFix, const QString &createdAt, const QString &repoProduct, long repoProduct_Snapshot);

private:
    QString postFix;
    QString createdAt;
    QString repoProduct;
    long repoProduct_Snapshot;

private:
    typedef struct FIELDS {
        QString postFix = "postFix";
        QString createdAt = "createdAt";
        QString repoProduct = "repoProduct";
        QString repoProduct_Snapshot = "repoProduct_Snapshot";
    } _fields;

    _fields *fields;

signals:


    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<EachContributedProduct *> parseJSONArray(QJsonArray o) throw();
    EachContributedProduct *parseJSONObject(QJsonObject o) throw();
    QList<EachContributedProduct *> parseArrayString(QString o) throw();
    EachContributedProduct *parseObjectString(QString o) throw();
    bool equal(EachContributedProduct *o);

    const QString &getPostFix() const;
    void setPostFix(const QString &newPostFix);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getRepoProduct() const;
    void setRepoProduct(const QString &newRepoProduct);
    long getRepoProduct_Snapshot() const;
    void setRepoProduct_Snapshot(long newRepoProduct_Snapshot);
};

#endif // EACHCONTRIBUTEDPRODUCT_H

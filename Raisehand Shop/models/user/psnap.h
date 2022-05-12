#ifndef PSNAP_H
#define PSNAP_H

#include "models/god/modelconventions.h"
#include "shareable/constants.h"

class PSnap : public ModelConventions<PSnap>
{
    Q_OBJECT
public:
    explicit PSnap(QObject *parent = nullptr);
    PSnap(const QString &repoProduct, long repoProduct_Snapshot, const QString &postFix, const QString &createdAt);

private:
    QString repoProduct;
    long repoProduct_Snapshot;
    QString postFix;
    QString createdAt;

private:
    typedef struct FIELDS {
        QString repoProduct = "repoProduct";
        QString repoProduct_Snapshot = "repoProduct_Snapshot";
        QString postFix = "postFix";
        QString createdAt = "createdAt";
    } _fields;

    _fields *fields;

signals:

public:
    bool hasPostFix() const;
    const QString getFormattedProductSnapshot() const;

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<PSnap *> parseJSONArray(QJsonArray o) throw();
    PSnap *parseJSONObject(QJsonObject o) throw();
    QList<PSnap *> parseArrayString(QString o) throw();
    PSnap *parseObjectString(QString o) throw();
    bool equal(PSnap *o);

    const QString &getRepoProduct() const;
    void setRepoProduct(const QString &newRepoProduct);
    long getRepoProductSnapshot() const;
    void setRepoProductSnapshot(long newRepoProduct_Snapshot);
    const QString &getPostFix() const;
    void setPostFix(const QString &newPostFix);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
};

#endif // PSNAP_H

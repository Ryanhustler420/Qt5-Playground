#ifndef CONTRIBUTION_H
#define CONTRIBUTION_H

#include "models/god/modelconventions.h"
#include "models/contribution/eachcontributedproduct.h"

class Contribution : public ModelConventions<Contribution>
{
    Q_OBJECT
public:
    explicit Contribution(QObject *parent = nullptr);
    Contribution(QList<EachContributedProduct> *productSnapshot, QString &productRepositoryName, QString &productRepository, QString &id, QString &createdAt, QString &updatedAt);


private:
    QList<EachContributedProduct> *productSnapshot;
    QString productRepositoryName;
    QString productRepository;
    QString createdAt;
    QString updatedAt;
    QString _id;

private:
    typedef struct FIELDS {
        QString productSnapshot = "productSnapshot";
        QString productRepositoryName = "productRepositoryName";
        QString productRepository = "productRepository";
        QString indexPosition = "indexPosition";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Contribution*> parseJSONArray(QJsonArray o) throw();
    Contribution* parseJSONObject(QJsonObject o) throw();
    QList<Contribution*> parseArrayString(QString o) throw();
    Contribution* parseObjectString(QString o) throw();
    bool equal(Contribution* o);

    QList<EachContributedProduct> *getProductSnapshot() const;
    void setProductSnapshot(QList<EachContributedProduct> *newProductSnapshot);
    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    const QString &getProductRepository() const;
    void setProductRepository(const QString &newProductRepository);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
    const QString &id() const;
    void setId(const QString &newId);
};

#endif // CONTRIBUTION_H

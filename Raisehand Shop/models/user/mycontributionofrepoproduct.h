#ifndef MYCONTRIBUTIONOFREPOPRODUCT_H
#define MYCONTRIBUTIONOFREPOPRODUCT_H

#include "models/god/modelconventions.h"
#include "models/user/psnap.h"

class MyContributionOfRepoProduct : public ModelConventions<MyContributionOfRepoProduct>
{
    Q_OBJECT
public:
    explicit MyContributionOfRepoProduct(QObject *parent = nullptr);
    MyContributionOfRepoProduct(QList<PSnap> *productSnapshot, const QString &productRepositoryName, const QString &productRepository);

private:
    QList<PSnap>* productSnapshot;
    QString productRepositoryName;
    QString productRepository;

private:
    typedef struct FIELDS {
        QString productSnapshot = "productSnapshot";
        QString productRepositoryName = "productRepositoryName";
        QString productRepository = "productRepository";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<MyContributionOfRepoProduct *> parseJSONArray(QJsonArray o) throw();
    MyContributionOfRepoProduct *parseJSONObject(QJsonObject o) throw();
    QList<MyContributionOfRepoProduct *> parseArrayString(QString o) throw();
    MyContributionOfRepoProduct *parseObjectString(QString o) throw();
    bool equal(MyContributionOfRepoProduct *o);

public:
    QString getAllTheProductFormattedSnapshots() const;

    QList<PSnap> *getProductSnapshot() const;
    void setProductSnapshot(QList<PSnap> *newProductSnapshot);
    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    const QString &getProductRepository() const;
    void setProductRepository(const QString &newProductRepository);
};

#endif // MYCONTRIBUTIONOFREPOPRODUCT_H

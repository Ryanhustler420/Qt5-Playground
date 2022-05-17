#ifndef MERGEREQUEST_H
#define MERGEREQUEST_H

#include "models/god/modelconventions.h"

class MergeRequest : public ModelConventions<MergeRequest>
{
    Q_OBJECT
public:
    explicit MergeRequest(QObject *parent = nullptr);
    MergeRequest(bool isAccepted, long hostRepoProductSnapshot, QList<long> *senderRequestingProductSnaps, const QString &senderProductRepositoryName, const QString &hostRepoProductPostFix, const QString &productRepository, const QString &createdAt, const QString &updatedAt);

private:
    bool isAccepted;
    long hostRepoProductSnapshot;
    QList<long>* senderRequestingProductSnaps;
    QString senderProductRepositoryName;
    QString hostRepoProductPostFix;
    QString productRepository;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString isAccepted = "isAccepted";
        QString hostRepoProductSnapshot = "hostRepoProductSnapshot";
        QString senderRequestingProductSnaps = "senderRequestingProductSnaps";
        QString senderProductRepositoryName = "senderProductRepositoryName";
        QString hostRepoProductPostFix = "hostRepoProductPostFix";
        QString productRepository = "productRepository";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<MergeRequest *> parseJSONArray(QJsonArray o) throw();
    MergeRequest *parseJSONObject(QJsonObject o) throw();
    QList<MergeRequest *> parseArrayString(QString o) throw();
    MergeRequest *parseObjectString(QString o) throw();
    bool equal(MergeRequest *o);

public:
    bool getIsAccepted() const;
    void setIsAccepted(bool newIsAccepted);
    long getHostRepoProductSnapshot() const;
    void setHostRepoProductSnapshot(long newHostRepoProductSnapshot);
    QList<long> *getSenderRequestingProductSnaps() const;
    void setSenderRequestingProductSnaps(QList<long> *newSenderRequestingProductSnaps);
    const QString &getSenderProductRepositoryName() const;
    void setSenderProductRepositoryName(const QString &newSenderProductRepositoryName);
    const QString &getHostRepoProductPostFix() const;
    void setHostRepoProductPostFix(const QString &newHostRepoProductPostFix);
    const QString &getProductRepository() const;
    void setProductRepository(const QString &newProductRepository);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // MERGEREQUEST_H

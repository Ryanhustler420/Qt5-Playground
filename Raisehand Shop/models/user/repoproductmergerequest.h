#ifndef REPOPRODUCTMERGEREQUEST_H
#define REPOPRODUCTMERGEREQUEST_H

#include "models/god/modelconventions.h"

class RepoProductMergeRequest : public ModelConventions<RepoProductMergeRequest>
{
    Q_OBJECT
public:
    explicit RepoProductMergeRequest(QObject *parent = nullptr);
    RepoProductMergeRequest(bool isAccepted, const QString &productRepository, const QString &senderProductRepositoryName, const QString &hostRepoProductPostFix, long hostRepoProductSnapshot, QList<long> *senderRequestingProductSnaps, const QString &createdAt);

private:
    bool isAccepted;
    QString productRepository;
    QString senderProductRepositoryName;
    QString hostRepoProductPostFix;
    long hostRepoProductSnapshot;
    QList<long>* senderRequestingProductSnaps;
    QString createdAt;

private:
    typedef struct FIELDS {
        QString isAccepted = "isAccepted";
        QString productRepository = "productRepository";
        QString senderProductRepositoryName = "senderProductRepositoryName";
        QString hostRepoProductPostFix = "hostRepoProductPostFix";
        QString hostRepoProductSnapshot = "hostRepoProductSnapshot";
        QString senderRequestingProductSnaps = "senderRequestingProductSnaps";
        QString createdAt = "createdAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<RepoProductMergeRequest *> parseJSONArray(QJsonArray o) throw();
    RepoProductMergeRequest *parseJSONObject(QJsonObject o) throw();
    QList<RepoProductMergeRequest *> parseArrayString(QString o) throw();
    RepoProductMergeRequest *parseObjectString(QString o) throw();
    bool equal(RepoProductMergeRequest *o);

public:
    bool getIsAccepted() const;
    void setIsAccepted(bool newIsAccepted);

    const QString &getProductRepository() const;
    void setProductRepository(const QString &newProductRepository);

    const QString &getSenderProductRepositoryName() const;
    void setSenderProductRepositoryName(const QString &newSenderProductRepositoryName);

    const QString &getHostRepoProductPostFix() const;
    void setHostRepoProductPostFix(const QString &newHostRepoProductPostFix);

    long getHostRepoProductSnapshot() const;
    void setHostRepoProductSnapshot(long newHostRepoProductSnapshot);

    QList<long> *getSenderRequestingProductSnaps() const;
    void setSenderRequestingProductSnaps(QList<long> *newSenderRequestingProductSnaps);

    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);

    QString getMergeRequestDetail() const;
};

#endif // REPOPRODUCTMERGEREQUEST_H

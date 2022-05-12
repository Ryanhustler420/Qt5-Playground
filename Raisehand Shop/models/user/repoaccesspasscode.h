#ifndef REPOACCESSPASSCODE_H
#define REPOACCESSPASSCODE_H

#include "models/god/modelconventions.h"

class RepoAccessPasscode : public ModelConventions<RepoAccessPasscode>
{
    Q_OBJECT
public:
    explicit RepoAccessPasscode(QObject *parent = nullptr);
    RepoAccessPasscode(const QString &productRepositoryName, long productRepositorySnapshot, const QString &productRepositoryProfilePassword, const QString &createdAt, const QString &updatedAt);

private:
    QString productRepositoryName;
    long productRepositorySnapshot;
    QString productRepositoryProfilePassword;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString productRepositoryName = "productRepositoryName";
        QString productRepositorySnapshot = "productRepositorySnapshot";
        QString productRepositoryProfilePassword = "productRepositoryProfilePassword";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<RepoAccessPasscode *> parseJSONArray(QJsonArray o) throw();
    RepoAccessPasscode *parseJSONObject(QJsonObject o) throw();
    QList<RepoAccessPasscode *> parseArrayString(QString o) throw();
    RepoAccessPasscode *parseObjectString(QString o) throw();
    bool equal(RepoAccessPasscode *o);

    const QString &getProductRepositoryName() const;
    void setProductRepositoryName(const QString &newProductRepositoryName);
    long getProductRepositorySnapshot() const;
    void setProductRepositorySnapshot(long newProductRepositorySnapshot);
    const QString &getProductRepositoryProfilePassword() const;
    void setProductRepositoryProfilePassword(const QString &newProductRepositoryProfilePassword);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // REPOACCESSPASSCODE_H

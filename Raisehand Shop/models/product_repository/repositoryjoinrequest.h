#ifndef REPOSITORYJOINREQUEST_H
#define REPOSITORYJOINREQUEST_H

#include "models/god/modelconventions.h"

class RepositoryJoinRequest : public ModelConventions<RepositoryJoinRequest>
{
    Q_OBJECT
public:
    explicit RepositoryJoinRequest(QObject *parent = nullptr);
    RepositoryJoinRequest(const QString &id, const QString &uid, const QString &email, const QString &isReviewed, const QString &isAllowed, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    QString uid;
    QString email;
    QString isReviewed;
    QString isAllowed;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString uid = "uid";

        QString email = "email";
        QString isReviewed = "isReviewed";
        QString isAllowed = "isAllowed";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<RepositoryJoinRequest *> parseJSONArray(QJsonArray o) throw();
    RepositoryJoinRequest *parseJSONObject(QJsonObject o) throw();
    QList<RepositoryJoinRequest *> parseArrayString(QString o) throw();
    RepositoryJoinRequest *parseObjectString(QString o) throw();
    bool equal(RepositoryJoinRequest *o);

    const QString &id() const;
    void setId(const QString &newId);
    const QString &getUid() const;
    void setUid(const QString &newUid);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    const QString &getIsReviewed() const;
    void setIsReviewed(const QString &newIsReviewed);
    const QString &getIsAllowed() const;
    void setIsAllowed(const QString &newIsAllowed);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // REPOSITORYJOINREQUEST_H

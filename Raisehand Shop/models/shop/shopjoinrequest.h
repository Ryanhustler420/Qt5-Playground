#ifndef SHOPJOINREQUEST_H
#define SHOPJOINREQUEST_H

#include "models/god/modelconventions.h"

class ShopJoinRequest : public ModelConventions<ShopJoinRequest>
{
    Q_OBJECT
public:
    explicit ShopJoinRequest(QObject *parent = nullptr);
    ShopJoinRequest(const QString &id, const QString &uid, const QString &email, bool isReviewed, bool isAllowed, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    QString uid;
    QString email;
    bool isReviewed;
    bool isAllowed;
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
    QList<ShopJoinRequest *> parseJSONArray(QJsonArray o) throw();
    ShopJoinRequest *parseJSONObject(QJsonObject o) throw();
    QList<ShopJoinRequest *> parseArrayString(QString o) throw();
    ShopJoinRequest *parseObjectString(QString o) throw();
    bool equal(ShopJoinRequest *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getUid() const;
    void setUid(const QString &newUid);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    bool getIsReviewed() const;
    void setIsReviewed(bool newIsReviewed);
    bool getIsAllowed() const;
    void setIsAllowed(bool newIsAllowed);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // SHOPJOINREQUEST_H

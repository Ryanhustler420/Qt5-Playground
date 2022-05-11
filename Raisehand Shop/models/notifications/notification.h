#ifndef NOTIFICATION_H
#define NOTIFICATION_H

#include "models/god/modelconventions.h"
#include "models/notifications/notificationmetadata.h"

class Notification : public ModelConventions<Notification>
{
    Q_OBJECT
public:
    explicit Notification(QObject *parent = nullptr);
    Notification(const QString &id, const QString &body, const QString &imageUrl, const QString &imageContainer, bool isRead, const QString &appName, const QString &n_reason, const QString &senderId, NotificationMetaData *metaData, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    QString body;
    QString imageUrl;
    QString imageContainer;
    bool isRead;
    QString appName;
    QString n_reason;
    QString senderId;
    NotificationMetaData *metaData; // could be null
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString body = "body";
        QString imageUrl = "imageUrl";
        QString imageContainer = "imageContainer";
        QString isRead = "isRead";
        QString appName = "appName";
        QString senderId = "senderId";
        QString metaData = "metaData";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    // If added or removed reason on nodeServer, then remove or add here also
    typedef struct N_REASON {
        QString SEEN = "SEEN";
        QString WISH = "WISH";
        QString QUOTE = "QUOTE";
        QString NOTIFY = "NOTIFY";
        QString PRODUCT_EDIT = "PRODUCT_EDIT";
        QString MERGE_REQUEST = "MERGE_REQUEST";
        QString REPOSITORY_ACCESS = "REPOSITORY_ACCESS";
        QString PRODUCT_CONTRIBUTION = "PRODUCT_CONTRIBUTION";
    } _n_reason;

    _fields *fields;
    _n_reason *reason;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Notification *> parseJSONArray(QJsonArray o) throw();
    Notification *parseJSONObject(QJsonObject o) throw();
    QList<Notification *> parseArrayString(QString o) throw();
    Notification *parseObjectString(QString o) throw();

    bool equal(Notification *o);
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getBody() const;
    void setBody(const QString &newBody);
    const QString &getImageUrl() const;
    void setImageUrl(const QString &newImageUrl);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    bool getIsRead() const;
    void setIsRead(bool newIsRead);
    const QString &getAppName() const;
    void setAppName(const QString &newAppName);
    const QString &getN_reason() const;
    void setN_reason(const QString &newN_reason);
    bool reasonBeingMergeRequest();
    const QString &getSenderId() const;
    void setSenderId(const QString &newSenderId);
    NotificationMetaData *getMetaData() const;
    void setMetaData(NotificationMetaData *newMetaData);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
};

#endif // NOTIFICATION_H

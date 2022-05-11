#ifndef NOTIFICATIONMETADATA_H
#define NOTIFICATIONMETADATA_H

#include "models/god/modelconventions.h"

class NotificationMetaData : public ModelConventions<NotificationMetaData>
{
    Q_OBJECT
public:
    explicit NotificationMetaData(QObject *parent = nullptr);
    NotificationMetaData(const QString &mergeRequestID);

private:
    QString mergeRequestID;

private:
    typedef struct FIELDS {
        QString mergeRequestID = "mergeRequestID";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<NotificationMetaData *> parseJSONArray(QJsonArray o) throw();
    NotificationMetaData *parseJSONObject(QJsonObject o) throw();
    QList<NotificationMetaData *> parseArrayString(QString o) throw();
    NotificationMetaData *parseObjectString(QString o) throw();
    bool equal(NotificationMetaData *o);

    const QString &getMergeRequestID() const;
    void setMergeRequestID(const QString &newMergeRequestID);
};

#endif // NOTIFICATIONMETADATA_H

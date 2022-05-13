#ifndef RECHARGECOUPON_H
#define RECHARGECOUPON_H

#include "models/god/modelconventions.h"
#include "models/plans/plan.h"

class RechargeCoupon : public ModelConventions<RechargeCoupon>
{
    Q_OBJECT
public:
    explicit RechargeCoupon(QObject *parent = nullptr);
    RechargeCoupon(const QString &id, const QString &code, bool subscribed, const QString &offerDescription, Plan *plan, const QString &appName, const QString &createdAt, const QString &updatedAt);

private:
    QString _id;
    QString code;
    bool subscribed;
    QString offerDescription;
    Plan* plan;
    QString appName;
    QString createdAt;
    QString updatedAt;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString code = "code";
        QString subscribed = "subscribed";
        QString offerDescription = "offerDescription";
        QString plan = "plan";
        QString appName = "appName";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<RechargeCoupon *> parseJSONArray(QJsonArray o) throw();
    RechargeCoupon *parseJSONObject(QJsonObject o) throw();
    QList<RechargeCoupon *> parseArrayString(QString o) throw();
    RechargeCoupon *parseObjectString(QString o) throw();
    bool equal(RechargeCoupon *o);

};

#endif // RECHARGECOUPON_H

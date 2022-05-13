#include "models/rechargecoupon.h"

RechargeCoupon::RechargeCoupon(const QString &id, const QString &code, bool subscribed, const QString &offerDescription, Plan *plan, const QString &appName, const QString &createdAt, const QString &updatedAt)
{
    this->_id = id;
    this->code = code;
    this->subscribed = subscribed;
    this->offerDescription = offerDescription;
    this->plan = plan;
    this->appName = appName;
    this->createdAt = createdAt;
    this->updatedAt = updatedAt;

    this->className = "RechargeCoupon";
    this->fields = new _fields();
}

QList<QString> RechargeCoupon::getAllFields()
{

}

QString RechargeCoupon::getPackageName()
{
    return this->className;
}

QList<RechargeCoupon *> RechargeCoupon::parseJSONArray(QJsonArray o) throw()
{

}

RechargeCoupon *RechargeCoupon::parseJSONObject(QJsonObject o) throw()
{

}

QList<RechargeCoupon *> RechargeCoupon::parseArrayString(QString o) throw()
{

}

RechargeCoupon *RechargeCoupon::parseObjectString(QString o) throw()
{

}

bool RechargeCoupon::equal(RechargeCoupon *o)
{
    return this == o;
}

#include "models/shop/workingtime.h"

WorkingTime::WorkingTime(const QString &open, const QString &close)
{
    this->open = open;
    this->close = close;
    this->className = "WorkingTime";
    this->fields = new _fields();
}

const QString &WorkingTime::getClose() const
{
    return close;
}

void WorkingTime::setClose(const QString &newClose)
{
    close = newClose;
}

const QString &WorkingTime::getOpen() const
{
    return open;
}

void WorkingTime::setOpen(const QString &newOpen)
{
    open = newOpen;
}

QList<QString> WorkingTime::getAllFields()
{

}

QString WorkingTime::getPackageName()
{
    return this->className;
}

QList<WorkingTime *> WorkingTime::parseJSONArray(QJsonArray o) throw()
{

}

WorkingTime *WorkingTime::parseJSONObject(QJsonObject o) throw()
{

}

QList<WorkingTime *> WorkingTime::parseArrayString(QString o) throw()
{

}

WorkingTime *WorkingTime::parseObjectString(QString o) throw()
{

}

bool WorkingTime::equal(WorkingTime *o)
{
    return o == this;
}

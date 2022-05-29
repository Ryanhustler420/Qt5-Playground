#include "models/payment.h"

Payment::Payment(const QString &title, const QString &date) :
    title(title),
    date(date)
{
    this->className = "Payment";
    this->fields = new _fields();
}

const QString &Payment::getDate() const
{
    return date;
}

void Payment::setDate(const QString &newDate)
{
    date = newDate;
}

const QString &Payment::getTitle() const
{
    return title;
}

void Payment::setTitle(const QString &newTitle)
{
    title = newTitle;
}

QList<QString> Payment::getAllFields()
{

}

QString Payment::getPackageName()
{
    return this->className;
}

QList<Payment *> Payment::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{

}

QVariantList Payment::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

Payment *Payment::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{

}

QVariant Payment::parseJSONObjectToVariant(QJsonObject o)
{

}

bool Payment::equal(Payment *o)
{
    return this->title == o->title;
}

void Payment::copy(Payment *o)
{

}

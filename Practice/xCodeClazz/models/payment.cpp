#include "models/payment.h"

Payment::Payment(QObject *parent)
{
    this->className = "Payment";
    this->fields = new _fields();
}

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

QList<Payment *> Payment::parseJSONArray(QJsonArray o)
{
    QList<Payment *> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        parseJSONObject(o.at(i).toObject());
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Payment::parseJSONArrayToVariantList(QJsonArray o)
{
    return o.toVariantList();
}

Payment *Payment::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    Payment *n = new Payment();

    try {
        if (o.contains(fields->title)) {
            n->setTitle(o.value(fields->title).toString());
        } else {
            n->setTitle(fallbackValue);
        }
    }  catch (QString error) {
        n->setTitle(fallbackValue);
    }

    try {
        if (o.contains(fields->date)) {
            n->setDate(o.value(fields->date).toString());
        } else {
            n->setDate(fallbackValue);
        }
    }  catch (QString error) {
        n->setDate(fallbackValue);
    }

    return n;
}

QVariant Payment::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool Payment::equal(Payment *o)
{
    return this->title == o->title;
}

QJsonObject Payment::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->title, this->title);
    mainObject.insert(this->fields->date, this->date);
    return mainObject;
}

QJsonArray Payment::getAsJsonArray(QList<Payment *> t) const
{
    QJsonArray array;
    for (int var = 0; var < t.size(); ++var) array.append(t.at(var)->getAsJson());
    return array;
}

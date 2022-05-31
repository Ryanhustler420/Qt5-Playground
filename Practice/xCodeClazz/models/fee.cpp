#include "models/fee.h"

Fee::Fee(QObject *parent)
{
    this->className = "Fee";
    this->fields = new _fields();
}

Fee::Fee(double amount, const QString &per) :
    amount(amount),
    per(per)
{
    this->className = "Fee";
    this->fields = new _fields();
}

const QString &Fee::getPer() const
{
    return per;
}

void Fee::setPer(const QString &newPer)
{
    per = newPer;
}

double Fee::getAmount() const
{
    return amount;
}

void Fee::setAmount(double newAmount)
{
    amount = newAmount;
}

QList<QString> Fee::getAllFields()
{

}

QString Fee::getPackageName()
{
    return this->className;
}

QList<Fee *> Fee::parseJSONArray(QJsonArray o)
{
    QList<Fee *> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        parseJSONObject(o.at(i).toObject());
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Fee::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

Fee *Fee::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    Fee *n = new Fee();

    try {
        if (o.contains(fields->amount)) {
            n->setAmount(o.value(fields->amount).toDouble());
        } else {
            n->setAmount(fallbackZero);
        }
    }  catch (QString error) {
        n->setAmount(fallbackZero);
    }

    try {
        if (o.contains(fields->per)) {
            n->setPer(o.value(fields->per).toString());
        } else {
            n->setPer(fallbackValue);
        }
    }  catch (QString error) {
        n->setPer(error);
    }

    return n;
}

QVariant Fee::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool Fee::equal(Fee *o)
{
    return o->amount = this->amount;
}

QJsonObject Fee::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->amount, this->amount);
    mainObject.insert(this->fields->per, this->per);
    return mainObject;
}

QJsonArray Fee::getAsJsonArray(QList<Fee *> t) const
{
    QJsonArray array;
    for (int var = 0; var < t.size(); ++var) array.append(t.at(var)->getAsJson());
    return array;
}

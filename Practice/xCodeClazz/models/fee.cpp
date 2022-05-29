#include "models/fee.h"

Fee::Fee(double amount, const QString &per) :
    amount(amount),
    per(per)
{
    this->className = "Fee";
    this->field = new _fields();
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

QList<Fee *> Fee::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{

}

QVariantList Fee::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

Fee *Fee::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{

}

QVariant Fee::parseJSONObjectToVariant(QJsonObject o)
{

}

bool Fee::equal(Fee *o)
{
    return o->amount = this->amount;
}

void Fee::copy(Fee *o)
{

}

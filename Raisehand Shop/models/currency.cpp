#include "models/currency.h"

Currency::Currency(const QString &currencyName, const QString &countryName, const QString &countryCode, const QString &countryISOCode, const QString &currencyCode, const QString &language, const QString &symbol, const QString &supported)
{
   this->currencyName = currencyName;
    this->countryName = countryName;
    this->countryCode = countryCode;
    this->countryISOCode = countryISOCode;
    this->currencyCode = currencyCode;
    this->language = language;
    this->symbol = symbol;
    this->supported = supported;

    this->className = "Currency";
    this->fields = new _fields();
}

const QString &Currency::getSupported() const
{
    return supported;
}

void Currency::setSupported(const QString &newSupported)
{
    supported = newSupported;
}

const QString &Currency::getSymbol() const
{
    return symbol;
}

void Currency::setSymbol(const QString &newSymbol)
{
    symbol = newSymbol;
}

const QString &Currency::getLanguage() const
{
    return language;
}

void Currency::setLanguage(const QString &newLanguage)
{
    language = newLanguage;
}

const QString &Currency::getCurrencyCode() const
{
    return currencyCode;
}

void Currency::setCurrencyCode(const QString &newCurrencyCode)
{
    currencyCode = newCurrencyCode;
}

const QString &Currency::getCountryISOCode() const
{
    return countryISOCode;
}

void Currency::setCountryISOCode(const QString &newCountryISOCode)
{
    countryISOCode = newCountryISOCode;
}

const QString &Currency::getCountryCode() const
{
    return countryCode;
}

void Currency::setCountryCode(const QString &newCountryCode)
{
    countryCode = newCountryCode;
}

const QString &Currency::getCountryName() const
{
    return countryName;
}

void Currency::setCountryName(const QString &newCountryName)
{
    countryName = newCountryName;
}

const QString &Currency::getCurrencyName() const
{
    return currencyName;
}

void Currency::setCurrencyName(const QString &newCurrencyName)
{
    currencyName = newCurrencyName;
}

QList<QString> Currency::getAllFields()
{

}

QString Currency::getPackageName()
{
    return this->className;
}

QList<Currency *> Currency::parseJSONArray(QJsonArray o) throw()
{

}

Currency *Currency::parseJSONObject(QJsonObject o) throw()
{

}

QList<Currency *> Currency::parseArrayString(QString o) throw()
{

}

Currency *Currency::parseObjectString(QString o) throw()
{

}

bool Currency::equal(Currency *o)
{
    return o == this;
}

QList<QString> Currency::getCurrencyNames(QList<Currency> currencies)
{
    QList<QString> v;
    for (int var = 0; var < currencies.size(); ++var) {
        v.append(currencies.at(var).getCurrencyName());
    }
    return v;
}

Currency* Currency::findCurrency(QList<Currency*> availableCurrencies, Currency* currency)
{
    QList<Currency*> *selected = new QList<Currency*>();
    selected->append(currency);
    for (int var = 0; var < availableCurrencies.size(); ++var) {
        if (availableCurrencies.at(var)->getCountryCode().compare(currency->getCountryCode())) {
            selected->insert(0, availableCurrencies.at(var));
        }
    }
    return selected->at(0);
}

QString Currency::appendSymbol(double price)
{
    return QString::number(price);
    // return QString("%1%1").arg(getCurrencySymbolByCurrencyCode(getCurrencyCode())).arg(helper.refineDecimalAndGroup(price));
}

QString Currency::currencyKeywordWithCurrencyName()
{
    return QString("%1, %1").arg(CURRENCY).arg(getCurrencyName());
}

QString Currency::currencySupport(bool supportAll)
{
    return supportAll ? "Supports all currencies" : getCurrencyName();
}

QString Currency::currencyCodeSupport(bool supportAll)
{
    return supportAll ? "Multiple" : getCurrencyCode();
}

QString Currency::getCurrencySymbolByCurrencyCode(QString currencyCode)
{
    if (currencyCode == nullptr || currencyCode.compare(EMPTY_STRING)) return SYMBOL_INR;
    if (currencyCode.compare("INR")) return SYMBOL_INR;
    if (currencyCode.compare("EUR")) return SYMBOL_EUR;
    if (currencyCode.compare("JPY")) return SYMBOL_JPY;
    if (currencyCode.compare("RUB")) return SYMBOL_RUB;
    if (currencyCode.compare("USD")) return SYMBOL_USD;
    return SYMBOL_INR;
}

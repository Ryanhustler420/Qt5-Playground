#ifndef CURRENCY_H
#define CURRENCY_H

#include "models/god/modelconventions.h"
#include "shareable/constants.h"

class Currency : public ModelConventions<Currency>
{
    Q_OBJECT
public:
    explicit Currency(QObject *parent = nullptr);
    Currency(const QString &currencyName, const QString &countryName, const QString &countryCode, const QString &countryISOCode, const QString &currencyCode, const QString &language, const QString &symbol, const QString &supported);

private:
    QString currencyName;
    QString countryName;
    QString countryCode;
    QString countryISOCode;
    QString currencyCode;
    QString language;
    QString symbol;
    QString supported;

private:
    typedef struct FIELDS {
        QString countryISOCode = "countryISOCode";
        QString currencyName = "currencyName";
        QString currencyCode = "currencyCode";
        QString countryCode = "countryCode";
        QString countryName = "countryName";
        QString supported = "supported";
        QString language = "language";
        QString symbol = "symbol";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Currency *> parseJSONArray(QJsonArray o) throw();
    Currency *parseJSONObject(QJsonObject o) throw();
    QList<Currency *> parseArrayString(QString o) throw();
    Currency *parseObjectString(QString o) throw();
    bool equal(Currency *o);

    const QString &getCurrencyName() const;
    void setCurrencyName(const QString &newCurrencyName);
    const QString &getCountryName() const;
    void setCountryName(const QString &newCountryName);
    const QString &getCountryCode() const;
    void setCountryCode(const QString &newCountryCode);
    const QString &getCountryISOCode() const;
    void setCountryISOCode(const QString &newCountryISOCode);
    const QString &getCurrencyCode() const;
    void setCurrencyCode(const QString &newCurrencyCode);
    const QString &getLanguage() const;
    void setLanguage(const QString &newLanguage);
    const QString &getSymbol() const;
    void setSymbol(const QString &newSymbol);
    const QString &getSupported() const;
    void setSupported(const QString &newSupported);

    static QList<QString> getCurrencyNames(QList<Currency> currencies);
    // static Currency getCurrencyBasedOnUserCountry(QList<Currency> availableCurrencies, User user);
    static Currency* findCurrency(QList<Currency*> availableCurrencies, Currency* currency);
    QString appendSymbol(double price);
    QString currencyKeywordWithCurrencyName();
    QString currencySupport(bool supportAll);
    QString currencyCodeSupport(bool supportAll);
    static QString getCurrencySymbolByCurrencyCode(QString currencyCode);

};

#endif // CURRENCY_H

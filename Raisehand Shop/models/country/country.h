#ifndef COUNTRY_H
#define COUNTRY_H

#include "models/god/modelconventions.h"
#include "models/country/state.h"

class Country : public ModelConventions<Country>
{
    Q_OBJECT
public:
    explicit Country(QObject *parent = nullptr);
    Country(bool active, const QString &name);

private:
    bool active;
    QString name;
    QList<State> *states;

private:
    typedef struct FIELDS {
        QString active = "active";
        QString name = "name";
        QString states = "states";
    } _fields;

    typedef struct COUNTRIES {
        QString COUNTRY_RUSSIA = ("russia");
        QString COUNTRY_INDIA = ("india");
        QString COUNTRY_JAPAN = ("japan");
        QString COUNTRY_CHINA = ("china");
        QString COUNTRY_USA = ("usa");
        QString COUNTRY_UK = ("uk");
    } _countries;

    _fields *fields;
    _countries *countries;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Country *> parseJSONArray(QJsonArray o) throw();
    Country *parseJSONObject(QJsonObject o) throw();
    QList<Country *> parseArrayString(QString o) throw();
    Country *parseObjectString(QString o) throw();
    bool equal(Country *o);

    static Country getDummyCountry();

    bool getActive() const;
    void setActive(bool newActive);
    const QString &getName() const;
    void setName(const QString &newName);
    QList<State> *getStates() const;
    void setStates(QList<State> *newStates);
};

#endif // COUNTRY_H

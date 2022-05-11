#ifndef STATE_H
#define STATE_H

#include "models/god/modelconventions.h"

class State : public ModelConventions<State>
{
    Q_OBJECT
public:
    explicit State(QObject *parent = nullptr);
    State(const QString &name, QList<QString> *cities);

private:
    QString name;
    QList<QString> *cities;

private:
    typedef struct FIELDS {
        QString name = "name";
        QString cities = "cities";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<State *> parseJSONArray(QJsonArray o) throw();
    State *parseJSONObject(QJsonObject o) throw();
    QList<State *> parseArrayString(QString o) throw();
    State *parseObjectString(QString o) throw();
    bool equal(State *o);

    const QString &getName() const;
    void setName(const QString &newName);
    const QList<QString> &getCities() const;
    void setCities(const QList<QString> &newCities);

    static State getDummyState();
    static QString getDummyCity();
};

#endif // STATE_H

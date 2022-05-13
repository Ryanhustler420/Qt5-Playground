#ifndef LOCATION_H
#define LOCATION_H

#include "models/god/modelconventions.h"
#include "models/coordinates.h"

class Location : public ModelConventions<Location>
{
    Q_OBJECT
public:
    explicit Location(QObject *parent = nullptr);
    Location(const QString &type, QList<double> *coordinates);

private:
    QString type;
    QList<double>* coordinates;

private:
    typedef struct FIELDS {
        QString type = "type";
        QString coordinates = "coordinates";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Location *> parseJSONArray(QJsonArray o) throw();
    Location *parseJSONObject(QJsonObject o) throw();
    QList<Location *> parseArrayString(QString o) throw();
    Location *parseObjectString(QString o) throw();
    bool equal(Location *o);

public:
    const QString &getType() const;
    void setType(const QString &newType);
    QList<double> *getCoordinates() const;
    void setCoordinates(QList<double> *newCoordinates);

    Coordinates* turnCoordinated();
};

#endif // LOCATION_H

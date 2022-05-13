#ifndef COORDINATES_H
#define COORDINATES_H

#include "models/god/modelconventions.h"

class Coordinates : public ModelConventions<Coordinates>
{
    Q_OBJECT
public:
    explicit Coordinates(QObject *parent = nullptr);
    Coordinates(double lat, double lng);

private:
    double lat;
    double lng;

private:
    typedef struct FIELDS {
        QString lat = "lat";
        QString lng = "lng";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Coordinates *> parseJSONArray(QJsonArray o) throw();
    Coordinates *parseJSONObject(QJsonObject o) throw();
    QList<Coordinates *> parseArrayString(QString o) throw();
    Coordinates *parseObjectString(QString o) throw();
    bool equal(Coordinates *o);

public:
    double getLat() const;
    void setLat(double newLat);

    double getLng() const;
    void setLng(double newLng);

};

#endif // COORDINATES_H

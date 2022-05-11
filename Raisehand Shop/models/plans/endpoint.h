#ifndef ENDPOINT_H
#define ENDPOINT_H

#include "models/god/modelconventions.h"

class EndPoint : public ModelConventions<EndPoint>
{
    Q_OBJECT
public:
    explicit EndPoint(QObject *parent = nullptr);
    EndPoint(const QString &endpoint, QList<QString> *pleaseSend);

private:
    QString endpoint;
    QList<QString> *pleaseSend;

private:
    typedef struct FIELDS {
        QString endpoint = "endpoint";
        QString pleaseSend = "pleaseSend";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<EndPoint *> parseJSONArray(QJsonArray o) throw();
    EndPoint *parseJSONObject(QJsonObject o) throw();
    QList<EndPoint *> parseArrayString(QString o) throw();
    EndPoint *parseObjectString(QString o) throw();
    bool equal(EndPoint *o);

    QList<QString> *getPleaseSend() const;
    void setPleaseSend(QList<QString> *newPleaseSend);
    QString getEndpoint() const;
    void setEndpoint(const QString &newEndpoint);
};

#endif // ENDPOINT_H

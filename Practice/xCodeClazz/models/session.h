#ifndef SESSION_H
#define SESSION_H

#include "models/god/modelconventions.h"

class Session : public ModelConventions<Session>
{
    Q_OBJECT
public:
    explicit Session(QObject *parent = nullptr);
    Session(const QString &starts, const QString &ends);

private:
    QString starts;
    QString ends;

private:
    typedef struct FIELDS {
        QString starts = "starts";
        QString ends = "ends";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Session *> parseJSONArray(QJsonArray o) throw();
    Session *parseJSONObject(QJsonObject o) throw();
    QList<Session *> parseArrayString(QString o) throw();
    Session *parseObjectString(QString o) throw();
    bool equal(Session *o);
    void copy(Session *o);

public:
    const QString &getStarts() const;
    void setStarts(const QString &newStarts);
    const QString &getEnds() const;
    void setEnds(const QString &newEnds);
};

#endif // SESSION_H

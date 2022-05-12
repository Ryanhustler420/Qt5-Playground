#ifndef SIUNIT_H
#define SIUNIT_H

#include "models/god/modelconventions.h"

class SiUnit : public ModelConventions<SiUnit>
{
    Q_OBJECT
public:
    explicit SiUnit(QObject *parent = nullptr);
    SiUnit(const QString &id, const QString &title);

private:
    QString _id;
    QString title;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString title = "title";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<SiUnit *> parseJSONArray(QJsonArray o) throw();
    SiUnit *parseJSONObject(QJsonObject o) throw();
    QList<SiUnit *> parseArrayString(QString o) throw();
    SiUnit *parseObjectString(QString o) throw();
    bool equal(SiUnit *o);

    const QString &getId() const;
    void setId(const QString &newId);

    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
};

#endif // SIUNIT_H

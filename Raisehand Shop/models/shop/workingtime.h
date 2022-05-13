#ifndef WORKINGTIME_H
#define WORKINGTIME_H

#include "models/god/modelconventions.h"

class WorkingTime : public ModelConventions<WorkingTime>
{
    Q_OBJECT
public:
    explicit WorkingTime(QObject *parent = nullptr);
    WorkingTime(const QString &open, const QString &close);

private:
    QString open;
    QString close;

private:
    typedef struct FIELDS {
        QString open = "open";
        QString close = "close";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<WorkingTime *> parseJSONArray(QJsonArray o) throw();
    WorkingTime *parseJSONObject(QJsonObject o) throw();
    QList<WorkingTime *> parseArrayString(QString o) throw();
    WorkingTime *parseObjectString(QString o) throw();
    bool equal(WorkingTime *o);
    const QString &getOpen() const;
    void setOpen(const QString &newOpen);
    const QString &getClose() const;
    void setClose(const QString &newClose);
};

#endif // WORKINGTIME_H

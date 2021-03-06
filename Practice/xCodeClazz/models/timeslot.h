#ifndef TIMESLOT_H
#define TIMESLOT_H

#include "models/god/modelconventions.h"

class TimeSlot : public ModelConventions<TimeSlot>
{
    Q_OBJECT
public:
    explicit TimeSlot(QObject *parent = nullptr);
    TimeSlot(const QString &from, const QString &to, QList<QString> *weeks);

private:
    QString from;
    QString to;
    QList<QString> *weeks;

private:
    typedef struct FIELDS {
        QString from = "from";
        QString to = "to";
        QString weeks = "weeks";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<TimeSlot *> parseJSONArray(QJsonArray o);
    QVariantList parseJSONArrayToVariantList(QJsonArray o);
    TimeSlot *parseJSONObject(QJsonObject o);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(TimeSlot *o);
    QJsonObject getAsJson() const;
    QJsonArray getAsJsonArray(QList<TimeSlot *> t) const;

    void operator = (const TimeSlot &o) {
        this->from = o.from;
        this->to = o.to;
        this->weeks = o.weeks;
    }

public:
    const QString &getFrom() const;
    void setFrom(const QString &newFrom);
    const QString &getTo() const;
    void setTo(const QString &newTo);
    QList<QString> *getWeeks() const;
    void setWeeks(QList<QString> *newWeeks);

};

#endif // TIMESLOT_H

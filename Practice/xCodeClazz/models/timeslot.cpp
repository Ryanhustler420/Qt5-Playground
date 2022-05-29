#include "models/timeslot.h"

TimeSlot::TimeSlot(const QString &from, const QString &to, QList<QString> *weeks) :
    from(from),
    to(to),
    weeks(weeks)
{
    this->className = "TimeSlot";
    this->fields = new _fields();
}

const QString &TimeSlot::getTo() const
{
    return to;
}

void TimeSlot::setTo(const QString &newTo)
{
    to = newTo;
}

QList<QString> *TimeSlot::getWeeks() const
{
    return weeks;
}

void TimeSlot::setWeeks(QList<QString> *newWeeks)
{
    weeks = newWeeks;
}

const QString &TimeSlot::getFrom() const
{
    return from;
}

void TimeSlot::setFrom(const QString &newFrom)
{
    from = newFrom;
}


QList<QString> TimeSlot::getAllFields()
{

}

QString TimeSlot::getPackageName()
{
    return this->className;
}

QList<TimeSlot *> TimeSlot::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{

}

QVariantList TimeSlot::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

TimeSlot *TimeSlot::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{

}

QVariant TimeSlot::parseJSONObjectToVariant(QJsonObject o)
{

}

bool TimeSlot::equal(TimeSlot *o)
{
    return this->from == o->from;
}

void TimeSlot::copy(TimeSlot *o)
{

}

#include "models/timeslot.h"

TimeSlot::TimeSlot(QObject *parent)
{
    this->className = "TimeSlot";
    this->fields = new _fields();
}

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

QList<TimeSlot> *TimeSlot::parseJSONArray(QJsonArray o)
{
    QList<TimeSlot> *list = new QList<TimeSlot>();
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        // list->append(*parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList TimeSlot::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

TimeSlot *TimeSlot::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    TimeSlot *n = new TimeSlot();

    try {
        if (o.contains(fields->from)) {
            n->setFrom(o.value(fields->from).toString());
        } else {
            n->setFrom(fallbackValue);
        }
    }  catch (QString error) {
        n->setFrom(fallbackValue);
    }

    try {
        if (o.contains(fields->to)) {
            n->setTo(o.value(fields->to).toString());
        } else {
            n->setTo(fallbackValue);
        }
    }  catch (QString error) {
        n->setTo(fallbackValue);
    }

    try {
        if (o.contains(fields->weeks)) {
            n->setWeeks(parseOnlyStringJSONArray(o.value(fields->weeks).toArray()));
        } else {
            n->setWeeks(nullptr);
        }
    }  catch (QString error) {
        n->setWeeks(nullptr);
    }

    return n;
}

QVariant TimeSlot::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool TimeSlot::equal(TimeSlot *o)
{
    return this->from == o->from;
}

void TimeSlot::copy(TimeSlot *o)
{
    this->from = o->from;
    this->to = o->to;
    this->weeks = o->weeks;
}

QJsonObject TimeSlot::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->from, this->from);
    mainObject.insert(this->fields->to, this->to);
    mainObject.insert(this->fields->weeks, this->weeks->join(", "));
    return mainObject;
}

QJsonArray TimeSlot::getAsJsonArray(QList<TimeSlot> *t) const
{
    QJsonArray array;
    for (int var = 0; var < t->size(); ++var) array.append(t->at(var).getAsJson());
    return array;
}

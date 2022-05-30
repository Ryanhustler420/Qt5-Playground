#include "models/session.h"

Session::Session(QObject *parent)
{
    this->className = "Session";
    this->fields = new _fields();
}

Session::Session(const QString &starts, const QString &ends)
{
    this->starts = starts;
    this->ends = ends;

    this->className = "Session";
    this->fields = new _fields();
}

const QString &Session::getEnds() const
{
    return ends;
}

void Session::setEnds(const QString &newEnds)
{
    ends = newEnds;
}

const QString &Session::getStarts() const
{
    return starts;
}

void Session::setStarts(const QString &newStarts)
{
    starts = newStarts;
}

QList<QString> Session::getAllFields()
{

}

QString Session::getPackageName()
{
    return this->className;
}

QList<Session*> Session::parseJSONArray(QJsonArray o)
{
    QList<Session*> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Session::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

Session *Session::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    Session *n = new Session();

    try {
        if (o.contains(fields->starts)) {
            n->setStarts(o.value(fields->starts).toString());
        } else {
            n->setStarts(fallbackValue);
        }
    }  catch (QString error) {
        n->setStarts(fallbackValue);
    }

    try {
        if (o.contains(fields->ends)) {
            n->setEnds(o.value(fields->ends).toString());
        } else {
            n->setEnds(fallbackValue);
        }
    }  catch (QString error) {
        n->setEnds(fallbackValue);
    }

    return n;
}

QVariant Session::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool Session::equal(Session *o)
{
    return o == this;
}

void Session::copy(Session *o)
{
    this->starts = o->starts;
    this->ends = o->ends;
}

QJsonObject Session::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->starts, this->starts);
    mainObject.insert(this->fields->ends, this->ends);
    return mainObject;
}

QJsonArray Session::getAsJsonArray(QList<Session> *t) const
{
    QJsonArray array;
    for (int var = 0; var < t->size(); ++var) array.append(t->at(var).getAsJson());
    return array;
}

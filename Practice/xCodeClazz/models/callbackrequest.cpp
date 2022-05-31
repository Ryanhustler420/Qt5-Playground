#include "models/callbackrequest.h"

CallbackRequest::CallbackRequest(QObject *parent)
{
    this->className = "CallbackRequest";
    this->fields = new _fields();
}

CallbackRequest::CallbackRequest(const QString &id, const QString &course, Course *ALTcourse, const QString &name, const QString &phone, const QString &school, const QString &createdAt, const QString &updatedAt, bool isReviewed) :
    _id(id),
    course(course),
    ALTcourse(ALTcourse),
    name(name),
    phone(phone),
    school(school),
    createdAt(createdAt),
    updatedAt(updatedAt),
    isReviewed(isReviewed)
{
    this->className = "CallbackRequest";
    this->fields = new _fields();
}

const QString &CallbackRequest::getCourse() const
{
    return course;
}

void CallbackRequest::setCourse(const QString &newCourse)
{
    course = newCourse;
}

Course *CallbackRequest::getALTcourse() const
{
    return ALTcourse;
}

void CallbackRequest::setALTcourse(Course *newALTcourse)
{
    ALTcourse = newALTcourse;
}

const QString &CallbackRequest::getName() const
{
    return name;
}

void CallbackRequest::setName(const QString &newName)
{
    name = newName;
}

const QString &CallbackRequest::getPhone() const
{
    return phone;
}

void CallbackRequest::setPhone(const QString &newPhone)
{
    phone = newPhone;
}

const QString &CallbackRequest::getSchool() const
{
    return school;
}

void CallbackRequest::setSchool(const QString &newSchool)
{
    school = newSchool;
}

const QString &CallbackRequest::getCreatedAt() const
{
    return createdAt;
}

void CallbackRequest::setCreatedAt(const QString &newCreatedAt)
{
    createdAt = newCreatedAt;
}

const QString &CallbackRequest::getUpdatedAt() const
{
    return updatedAt;
}

void CallbackRequest::setUpdatedAt(const QString &newUpdatedAt)
{
    updatedAt = newUpdatedAt;
}

bool CallbackRequest::getIsReviewed() const
{
    return isReviewed;
}

void CallbackRequest::setIsReviewed(bool newIsReviewed)
{
    isReviewed = newIsReviewed;
}

const QString &CallbackRequest::id() const
{
    return _id;
}

void CallbackRequest::setId(const QString &newId)
{
    _id = newId;
}

QList<QString> CallbackRequest::getAllFields()
{

}

QString CallbackRequest::getPackageName()
{
    return this->className;
}

QList<CallbackRequest *> CallbackRequest::parseJSONArray(QJsonArray o)
{
    QList<CallbackRequest *> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList CallbackRequest::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

CallbackRequest *CallbackRequest::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    CallbackRequest *n = new CallbackRequest();

    try {
        if (o.contains(fields->_id)) {
            n->setId(o.value(fields->_id).toString());
        } else {
            n->setId(fallbackValue);
        }
    }  catch (QString error) {
        n->setId(error);
    }

    try {
        if (o.contains(fields->course)) {
            if (mongo.isValidMongoID(fields->course))
                n->setCourse(o.value(fields->course).toString());
            else n->setALTcourse((new Course())->parseJSONObject(o.value(fields->course).toObject()));
        } else if (o.contains(fields->ALTcourse)) {
            if (mongo.isValidMongoID(o.value(fields->ALTcourse).toString()))
                n->setCourse(o.value(fields->ALTcourse).toString());
            else n->setALTcourse((new Course())->parseJSONObject(o.value(fields->ALTcourse).toObject()));
        } else {
            n->setCourse(fallbackValue);
        }
    }  catch (QString error) {
        n->setALTcourse(nullptr);
        n->setCourse(error);
    }

    try {
        if (o.contains(fields->name)) {
            n->setName(o.value(fields->name).toString());
        } else {
            n->setName(fallbackValue);
        }
    }  catch (QString error) {
        n->setName(error);
    }

    try {
        if (o.contains(fields->phone)) {
            n->setPhone(o.value(fields->phone).toString());
        } else {
            n->setPhone(fallbackValue);
        }
    }  catch (QString error) {
        n->setPhone(error);
    }

    try {
        if (o.contains(fields->school)) {
            n->setSchool(o.value(fields->school).toString());
        } else {
            n->setSchool(fallbackValue);
        }
    }  catch (QString error) {
        n->setSchool(error);
    }

    try {
        if (o.contains(fields->createdAt)) {
            n->setCreatedAt(o.value(fields->createdAt).toString());
        } else {
            n->setCreatedAt(fallbackValue);
        }
    }  catch (QString error) {
        n->setCreatedAt(error);
    }

    try {
        if (o.contains(fields->updatedAt)) {
            n->setUpdatedAt(o.value(fields->updatedAt).toString());
        } else {
            n->setUpdatedAt(fallbackValue);
        }
    }  catch (QString error) {
        n->setUpdatedAt(error);
    }

    try {
        if (o.contains(fields->isReviewed)) {
            n->setIsReviewed(o.value(fields->isReviewed).toBool());
        } else {
            n->setIsReviewed(false);
        }
    }  catch (QString error) {
        n->setIsReviewed(false);
    }

    return n;
}

QVariant CallbackRequest::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool CallbackRequest::equal(CallbackRequest *o)
{
    return o->id() == this->id();
}

QJsonObject CallbackRequest::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->_id, this->_id);
    mainObject.insert(this->fields->course, this->course);
    mainObject.insert(this->fields->ALTcourse, this->ALTcourse->getAsJson());
    mainObject.insert(this->fields->name, this->name);
    mainObject.insert(this->fields->phone, this->phone);
    mainObject.insert(this->fields->school, this->school);
    mainObject.insert(this->fields->createdAt, this->createdAt);
    mainObject.insert(this->fields->updatedAt, this->updatedAt);
    mainObject.insert(this->fields->isReviewed, this->isReviewed);
    return mainObject;
}

QJsonArray CallbackRequest::getAsJsonArray(QList<CallbackRequest *> t) const
{
    QJsonArray array;
    for (int var = 0; var < t.size(); ++var) array.append(t.at(var)->getAsJson());
    return array;
}

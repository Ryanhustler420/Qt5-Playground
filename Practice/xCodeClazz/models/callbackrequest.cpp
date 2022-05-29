#include "models/callbackrequest.h"

CallbackRequest::CallbackRequest(const QString &id, const QString &course, Course *ALTcourse, const QString &name, const QString &phone, const QString &school, const QString &createdAt, const QString &updatedAt, bool isReviewed) : _id(id),
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
    this->field = new _fields();
}

QList<QString> CallbackRequest::getAllFields()
{

}

QString CallbackRequest::getPackageName()
{
    return this->className;
}

QList<CallbackRequest *> CallbackRequest::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{

}

QVariantList CallbackRequest::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

CallbackRequest *CallbackRequest::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{

}

QVariant CallbackRequest::parseJSONObjectToVariant(QJsonObject o)
{

}

bool CallbackRequest::equal(CallbackRequest *o)
{
    return o->id() == this->id();
}

void CallbackRequest::copy(CallbackRequest *o)
{

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

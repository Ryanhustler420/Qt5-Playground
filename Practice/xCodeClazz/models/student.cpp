#include "models/student.h"

Student::Student(const QString &_id, const QString &school, const QString &name, const QString &imageUrl, const QString &imageContainer, int age, const QString &clazz, QList<Payment> *payments, QList<QString> *courses, QList<Course> *ALTCourses, TimeSlot *timeSlot, QList<QString> *phoneNumbers, const QString &joinDate, Fee *fees, int batchNumber, const QString &email) :
    _id(_id),
    school(school),
    name(name),
    imageUrl(imageUrl),
    imageContainer(imageContainer),
    age(age),
    clazz(clazz),
    payments(payments),
    courses(courses),
    ALTCourses(ALTCourses),
    timeSlot(timeSlot),
    phoneNumbers(phoneNumbers),
    joinDate(joinDate),
    fees(fees),
    batchNumber(batchNumber),
    email(email)
{
    this->className = "Student";
    this->field = new _fields();
}

QList<QString> Student::getAllFields()
{

}

QString Student::getPackageName()
{
    return this->className;
}

QList<Student *> Student::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{

}

QVariantList Student::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{

}

Student *Student::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{

}

QVariant Student::parseJSONObjectToVariant(QJsonObject o)
{

}

bool Student::equal(Student *o)
{
    return o->id() == this->id();
}

void Student::copy(Student *o)
{

}

const QString &Student::id() const
{
    return _id;
}

void Student::setId(const QString &newId)
{
    _id = newId;
}

QList<Payment> *Student::getPayments() const
{
    return payments != nullptr ? payments : new QList<Payment>();
}

void Student::setPayments(QList<Payment> *newPayments)
{
    payments = newPayments;
}

const QString &Student::getEmail() const
{
    return email;
}

void Student::setEmail(const QString &newEmail)
{
    email = newEmail;
}

int Student::getBatchNumber() const
{
    return batchNumber;
}

void Student::setBatchNumber(int newBatchNumber)
{
    batchNumber = newBatchNumber;
}

Fee *Student::getFees() const
{
    return fees;
}

void Student::setFees(Fee *newFees)
{
    fees = newFees;
}

const QString &Student::getJoinDate() const
{
    return joinDate;
}

void Student::setJoinDate(const QString &newJoinDate)
{
    joinDate = newJoinDate;
}

QList<QString> *Student::getPhoneNumbers() const
{
    return phoneNumbers != nullptr ? phoneNumbers : new QList<QString>();
}

void Student::setPhoneNumbers(QList<QString> *newPhoneNumbers)
{
    phoneNumbers = newPhoneNumbers;
}

TimeSlot *Student::getTimeSlot() const
{
    return timeSlot;
}

void Student::setTimeSlot(TimeSlot *newTimeSlot)
{
    timeSlot = newTimeSlot;
}

QList<Course> *Student::getALTCourses() const
{
    return ALTCourses != nullptr ? ALTCourses : new QList<Course>();
}

void Student::setALTCourses(QList<Course> *newALTCourses)
{
    ALTCourses = newALTCourses;
}

QList<QString> *Student::getCourses() const
{
    return courses != nullptr ? courses : new QList<QString>();
}

void Student::setCourses(QList<QString> *newCourses)
{
    courses = newCourses;
}

const QString &Student::getClazz() const
{
    return clazz;
}

void Student::setClazz(const QString &newClazz)
{
    clazz = newClazz;
}

int Student::getAge() const
{
    return age;
}

void Student::setAge(int newAge)
{
    age = newAge;
}

const QString &Student::getImageContainer() const
{
    return imageContainer;
}

void Student::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &Student::getImageUrl() const
{
    return imageUrl;
}

void Student::setImageUrl(const QString &newImageUrl)
{
    imageUrl = newImageUrl;
}

const QString &Student::getName() const
{
    return name;
}

void Student::setName(const QString &newName)
{
    name = newName;
}

const QString &Student::getSchool() const
{
    return school;
}

void Student::setSchool(const QString &newSchool)
{
    school = newSchool;
}

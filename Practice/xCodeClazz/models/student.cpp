#include "models/student.h"

Student::Student(QObject *parent)
{
    this->className = "Student";
    this->fields = new _fields();
}

Student::Student(const QString &_id, const QString &school, const QString &name, const QString &imageUrl, const QString &imageContainer, int age, const QString &clazz, QList<Payment *> payments, QList<QString> *courses, QList<Course *> ALTCourses, TimeSlot *timeSlot, QList<QString> *phoneNumbers, const QString &joinDate, Fee *fees, int batchNumber, const QString &email) :
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
    this->fields = new _fields();
}

const QString &Student::id() const
{
    return _id;
}

void Student::setId(const QString &newId)
{
    _id = newId;
}

QList<Payment *> Student::getPayments() const
{
    return payments;
}

void Student::setPayments(QList<Payment *> newPayments)
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
    return phoneNumbers;
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

QList<Course *> Student::getALTCourses() const
{
    return ALTCourses;
}

void Student::setALTCourses(QList<Course *> newALTCourses)
{
    ALTCourses = newALTCourses;
}

QList<QString> *Student::getCourses() const
{
    return courses;
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

QList<QString> Student::getAllFields()
{

}

QString Student::getPackageName()
{
    return this->className;
}

QList<Student *> Student::parseJSONArray(QJsonArray o)
{
    QList<Student *> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        parseJSONObject(o.at(i).toObject());
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Student::parseJSONArrayToVariantList(QJsonArray o)
{
    return o.toVariantList();
}

Student *Student::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    Student *n = new Student();

    try {
        if (o.contains(fields->_id)) {
            n->setId(o.value(fields->_id).toString());
        } else {
            n->setId(fallbackValue);
        }
    }  catch (QString error) {
        n->setId(fallbackValue);
    }

    try {
        if (o.contains(fields->school)) {
            n->setSchool(o.value(fields->school).toString());
        } else {
            n->setSchool(fallbackValue);
        }
    }  catch (QString error) {
        n->setSchool(fallbackValue);
    }

    try {
        if (o.contains(fields->name)) {
            n->setName(o.value(fields->name).toString());
        } else {
            n->setName(fallbackValue);
        }
    }  catch (QString error) {
        n->setName(fallbackValue);
    }

    try {
        if (o.contains(fields->imageUrl)) {
            n->setImageUrl(o.value(fields->imageUrl).toString());
        } else {
            n->setImageUrl(fallbackValue);
        }
    }  catch (QString error) {
        n->setImageUrl(fallbackValue);
    }

    try {
        if (o.contains(fields->imageContainer)) {
            n->setImageContainer(o.value(fields->imageContainer).toString());
        } else {
            n->setImageContainer(fallbackValue);
        }
    }  catch (QString error) {
        n->setImageContainer(fallbackValue);
    }

    try {
        if (o.contains(fields->age)) {
            n->setAge(o.value(fields->age).toInt());
        } else {
            n->setAge(fallbackZero);
        }
    }  catch (QString error) {
        n->setAge(fallbackZero);
    }

    try {
        if (o.contains(fields->age)) {
            n->setAge(o.value(fields->age).toInt());
        } else {
            n->setAge(fallbackZero);
        }
    }  catch (QString error) {
        n->setAge(fallbackZero);
    }

    try {
        if (o.contains(fields->clazz)) {
            n->setClazz(o.value(fields->clazz).toString());
        } else {
            n->setClazz(fallbackValue);
        }
    }  catch (QString error) {
        n->setClazz(fallbackValue);
    }

    try {
        if (o.contains(fields->payments)) {
            // you can only store Pointer data type in array and not the object
            Payment p;
            n->setPayments(p.parseJSONArray(o.value(fields->payments).toArray()));
        } else {
            n->setPayments(QList<Payment *>());
        }
    }  catch (QString error) {
        n->setPayments(QList<Payment *>());
    }

    try {
        if (o.contains(fields->courses)) {
            if (mongo.hasMongoIds(o.value(fields->courses).toArray()))
                n->setCourses(parseOnlyStringJSONArray(o.value(fields->courses).toArray()));
            else n->setALTCourses((new Course())->parseJSONArray(o.value(fields->courses).toArray()));
        } else if (o.contains(fields->ALTCourses)) {
            if (mongo.isValidMongoID(o.value(fields->ALTCourses).toString()))
                n->setCourses(parseOnlyStringJSONArray(o.value(fields->courses).toArray()));
            else n->setALTCourses((new Course())->parseJSONArray(o.value(fields->courses).toArray()));
        } else {
            n->setCourses(nullptr);
        }
    }  catch (QString error) {
        n->setALTCourses(QList<Course *>());
        n->setCourses(new QList<QString>());
    }

    try {
        if (o.contains(fields->timeSlot)) {
            TimeSlot p;
            n->setTimeSlot(p.parseJSONObject(o.value(fields->timeSlot).toObject()));
        } else {
            n->setTimeSlot(nullptr);
        }
    }  catch (QString error) {
        n->setTimeSlot(nullptr);
    }

    try {
        if (o.contains(fields->phoneNumbers)) {
            n->setPhoneNumbers(parseOnlyStringJSONArray(o.value(fields->phoneNumbers).toArray()));
        } else {
            n->setPhoneNumbers(nullptr);
        }
    }  catch (QString error) {
        n->setPhoneNumbers(nullptr);
    }

    try {
        if (o.contains(fields->joinDate)) {
            n->setJoinDate(o.value(fields->joinDate).toString());
        } else {
            n->setJoinDate(nullptr);
        }
    }  catch (QString error) {
        n->setJoinDate(nullptr);
    }

    try {
        if (o.contains(fields->fees)) {
            Fee f;
            n->setFees(f.parseJSONObject(o.value(fields->fees).toObject()));
        } else {
            n->setFees(nullptr);
        }
    }  catch (QString error) {
        n->setFees(nullptr);
    }

    try {
        if (o.contains(fields->batchNumber)) {
            n->setBatchNumber(o.value(fields->batchNumber).toInt());
        } else {
            n->setBatchNumber(fallbackZero);
        }
    }  catch (QString error) {
        n->setBatchNumber(fallbackZero);
    }

    try {
        if (o.contains(fields->email)) {
            n->setEmail(o.value(fields->email).toString());
        } else {
            n->setEmail(fallbackValue);
        }
    }  catch (QString error) {
        n->setEmail(fallbackValue);
    }

    return n;
}

QVariant Student::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

bool Student::equal(Student *o)
{
    return o->id() == this->id();
}

QJsonObject Student::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->_id, this->_id);
    mainObject.insert(this->fields->age, this->age);
    mainObject.insert(this->fields->name, this->name);
    mainObject.insert(this->fields->clazz, this->clazz);
    mainObject.insert(this->fields->email, this->email);
    mainObject.insert(this->fields->school, this->school);
    mainObject.insert(this->fields->imageUrl, this->imageUrl);
    mainObject.insert(this->fields->joinDate, this->joinDate);
    mainObject.insert(this->fields->batchNumber, this->batchNumber);
    mainObject.insert(this->fields->imageContainer, this->imageContainer);
    mainObject.insert(this->fields->fees, this->fees->getAsJson());
    mainObject.insert(this->fields->courses, json.toJsonArray(this->courses));
    mainObject.insert(this->fields->timeSlot, this->timeSlot->getAsJson());
    mainObject.insert(this->fields->phoneNumbers, json.toJsonArray(this->phoneNumbers));
    mainObject.insert(this->fields->courses, (new Course())->getAsJsonArray(this->ALTCourses));
    mainObject.insert(this->fields->payments, (new Payment())->getAsJsonArray(this->payments));
    return mainObject;
}

QJsonArray Student::getAsJsonArray(QList<Student *> t) const
{
    QJsonArray array;
    for (int var = 0; var < t.size(); ++var) array.append(t.at(var)->getAsJson());
    return array;
}

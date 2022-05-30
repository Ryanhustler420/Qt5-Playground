#include "models/student.h"

Student::Student(QObject *parent)
{
    this->className = "Student";
    this->fields = new _fields();
}

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

QList<QString> Student::getAllFields()
{

}

QString Student::getPackageName()
{
    return this->className;
}

QList<Student*> Student::parseJSONArray(QJsonArray o)
{
    QList<Student*> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Student::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
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
            // TODO:
            // n->setPayments((new Payment())->parseJSONArray(o.value(fields->payments).toArray()));
        } else {
            n->setPayments(nullptr);
        }
    }  catch (QString error) {
        n->setPayments(nullptr);
    }

    //    QList<Payment> *payments;
    //    QList<QString> *courses;
    //    QList<Course> *ALTCourses;
    //    TimeSlot *timeSlot;
    //    QList<QString> *phoneNumbers;
    //    QString joinDate;
    //    Fee *fees;
    //    int batchNumber;
    //    QString email;

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

void Student::copy(Student *o)
{
    this->_id = o->_id;
    this->school = o->school;
    this->name = o->name;
    this->imageUrl = o->imageUrl;
    this->imageContainer = o->imageContainer;
    this->age = o->age;
    this->clazz = o->clazz;
    this->payments = o->payments;
    this->courses = o->courses;
    this->ALTCourses = o->ALTCourses;
    this->timeSlot = o->timeSlot;
    this->phoneNumbers = o->phoneNumbers;
    this->joinDate = o->joinDate;
    this->fees = o->fees;
    this->batchNumber = o->batchNumber;
    this->email = o->email;
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
    mainObject.insert(this->fields->courses, this->courses->join(", "));
    mainObject.insert(this->fields->timeSlot, this->timeSlot->getAsJson());
    mainObject.insert(this->fields->phoneNumbers, this->phoneNumbers->join(", "));
    mainObject.insert(this->fields->courses, (new Course())->getAsJsonArray(this->ALTCourses));
    mainObject.insert(this->fields->payments, (new Payment())->getAsJsonArray(this->payments));

    return mainObject;
}

QJsonArray Student::getAsJsonArray(QList<Student> *t) const
{
    QJsonArray array;
    for (int var = 0; var < t->size(); ++var) array.append(t->at(var).getAsJson());
    return array;
}

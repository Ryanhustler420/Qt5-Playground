#ifndef STUDENT_H
#define STUDENT_H

#include "models/god/modelconventions.h"
#include "models/timeslot.h"
#include "models/payment.h"
#include "models/course.h"
#include "models/fee.h"

class Student : public ModelConventions<Student>
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);
    Student(const QString &_id, const QString &school, const QString &name, const QString &imageUrl, const QString &imageContainer, int age, const QString &clazz, QList<Payment> *payments, QList<QString> *courses, QList<Course> *ALTCourses, TimeSlot *timeSlot, QList<QString> *phoneNumbers, const QString &joinDate, Fee *fees, int batchNumber, const QString &email);

private:
    QString _id;
    QString school;
    QString name;
    QString imageUrl;
    QString imageContainer;
    int age;
    QString clazz;
    QList<Payment> *payments;
    QList<QString> *courses;
    QList<Course> *ALTCourses;
    TimeSlot *timeSlot;
    QList<QString> *phoneNumbers;
    QString joinDate;
    Fee *fees;
    int batchNumber;
    QString email;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString school = "school";
        QString name = "name";
        QString imageUrl = "imageUrl";
        QString imageContainer = "imageContainer";
        QString age = "age";
        QString clazz = "clazz";
        QString payments = "payments";
        QString courses = "courses";
        QString ALTCourses = "ALTCourses";
        QString timeSlot = "timeSlot";
        QString phoneNumbers = "phoneNumbers";
        QString joinDate = "joinDate";
        QString fees = "fees";
        QString batchNumber = "batchNumber";
        QString email = "email";
    } _fields;

    _fields *field;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Student *> parseJSONArray(QJsonArray o) throw(ExceptionThrow);
    QVariantList parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow);
    Student *parseJSONObject(QJsonObject o) throw(ExceptionThrow);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(Student *o);
    void copy(Student *o);

public:
    const QString &getSchool() const;
    void setSchool(const QString &newSchool);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getImageUrl() const;
    void setImageUrl(const QString &newImageUrl);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    int getAge() const;
    void setAge(int newAge);
    const QString &getClazz() const;
    void setClazz(const QString &newClazz);
    QList<QString> *getCourses() const;
    void setCourses(QList<QString> *newCourses);
    QList<Course> *getALTCourses() const;
    void setALTCourses(QList<Course> *newALTCourses);
    TimeSlot *getTimeSlot() const;
    void setTimeSlot(TimeSlot *newTimeSlot);
    QList<QString> *getPhoneNumbers() const;
    void setPhoneNumbers(QList<QString> *newPhoneNumbers);
    const QString &getJoinDate() const;
    void setJoinDate(const QString &newJoinDate);
    Fee *getFees() const;
    void setFees(Fee *newFees);
    int getBatchNumber() const;
    void setBatchNumber(int newBatchNumber);
    const QString &getEmail() const;
    void setEmail(const QString &newEmail);
    QList<Payment> *getPayments() const;
    void setPayments(QList<Payment> *newPayments);
    const QString &id() const;
    void setId(const QString &newId);
};

#endif // STUDENT_H

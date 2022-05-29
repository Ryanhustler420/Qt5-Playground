#ifndef CALLBACKREQUEST_H
#define CALLBACKREQUEST_H

#include "models/god/modelconventions.h"
#include "models/course.h"

class CallbackRequest : public ModelConventions<CallbackRequest>
{
    Q_OBJECT
public:
    explicit CallbackRequest(QObject *parent = nullptr);
    CallbackRequest(const QString &id, const QString &course, Course *ALTcourse, const QString &name, const QString &phone, const QString &school, const QString &createdAt, const QString &updatedAt, bool isReviewed);

private:
    QString _id;
    QString course;
    Course *ALTcourse;
    QString name;
    QString phone;
    QString school;
    QString createdAt;
    QString updatedAt;
    bool isReviewed;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString course = "course";
        QString ALTcourse = "ALTcourse";
        QString name = "name";
        QString phone = "phone";
        QString school = "school";
        QString createdAt = "createdAt";
        QString updatedAt = "updatedAt";
        QString isReviewed = "isReviewed";
    } _fields;

    _fields *field;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<CallbackRequest *> parseJSONArray(QJsonArray o) throw(ExceptionThrow);
    QVariantList parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow);
    CallbackRequest *parseJSONObject(QJsonObject o) throw(ExceptionThrow);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(CallbackRequest *o);
    void copy(CallbackRequest *o);

public:
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getCourse() const;
    void setCourse(const QString &newCourse);
    Course *getALTcourse() const;
    void setALTcourse(Course *newALTcourse);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getPhone() const;
    void setPhone(const QString &newPhone);
    const QString &getSchool() const;
    void setSchool(const QString &newSchool);
    const QString &getCreatedAt() const;
    void setCreatedAt(const QString &newCreatedAt);
    const QString &getUpdatedAt() const;
    void setUpdatedAt(const QString &newUpdatedAt);
    bool getIsReviewed() const;
    void setIsReviewed(bool newIsReviewed);
};

#endif // CALLBACKREQUEST_H

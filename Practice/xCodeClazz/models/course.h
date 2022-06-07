#ifndef COURSE_H
#define COURSE_H

#include "models/god/modelconventions.h"
#include "models/session.h"

class Course : public ModelConventions<Course>
{
    Q_OBJECT
public:
    explicit Course(QObject *parent = nullptr);
    Course(const QString &_id, const QString &title, const QString &subtitle, const QString &duration, const QString &thumbnailUrl, const QString &imageContainer, QList<QString> *features, int price, bool hasActive, int spaceLeft, int spaceFull, Session *session);

private:
    QString _id;
    QString title;
    QString subtitle;
    QString duration;
    QString thumbnailUrl;
    QString imageContainer;
    QList<QString> *features;
    int price;
    bool hasActive;
    int spaceLeft;
    int spaceFull;
    Session *session;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString title = "title";
        QString subtitle = "subtitle";
        QString duration = "duration";
        QString thumbnailUrl = "thumbnailUrl";
        QString imageContainer = "imageContainer";
        QString features = "features";
        QString price = "price";
        QString hasActive = "hasActive";
        QString spaceLeft = "spaceLeft";
        QString spaceFull = "spaceFull";
        QString session = "session";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Course *> parseJSONArray(QJsonArray o);
    QVariantList parseJSONArrayToVariantList(QJsonArray o);
    Course *parseJSONObject(QJsonObject o);
    QVariant parseJSONObjectToVariant(QJsonObject o);
    bool equal(Course *o);
    QJsonObject getAsJson() const;
    QJsonArray getAsJsonArray(QList<Course *> t) const;

    void operator = (const Course &course) {
        this->_id = course._id;
        this->title = course.title;
        this->subtitle = course.subtitle;
        this->duration = course.duration;
        this->thumbnailUrl = course.thumbnailUrl;
        this->imageContainer = course.imageContainer;
        this->features = course.features;
        this->price = course.price;
        this->hasActive = course.hasActive;
        this->spaceLeft = course.spaceLeft;
        this->spaceFull = course.spaceFull;
        this->session = course.session;
    }

public:
    const QString &id() const;
    void setId(const QString &newId);
    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
    const QString &getSubtitle() const;
    void setSubtitle(const QString &newSubtitle);
    const QString &getDuration() const;
    void setDuration(const QString &newDuration);
    const QString &getThumbnailUrl() const;
    void setThumbnailUrl(const QString &newThumbnailUrl);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
    QList<QString> *getFeatures() const;
    void setFeatures(QList<QString> *newFeatures);
    int getPrice() const;
    void setPrice(int newPrice);
    bool getHasActive() const;
    void setHasActive(bool newHasActive);
    int getSpaceLeft() const;
    void setSpaceLeft(int newSpaceLeft);
    int getSpaceFull() const;
    void setSpaceFull(int newSpaceFull);
    Session *getSession() const;
    void setSession(Session *newSession);
};

#endif // COURSE_H

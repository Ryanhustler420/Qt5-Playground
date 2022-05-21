#include "models/course.h"

Course::Course(QObject *parent) : ModelConventions<Course>()
{
    this->className = "Course";
    this->field = new _fields();
}

Course::Course(const QString &title, const QString &subtitle, const QString &duration, const QString &thumbnailUrl, const QString &imageContainer, QList<QString> *features, int price, bool hasActive, int spaceLeft, int spaceFull, Session *session)
{
    this->title = title;
    this->subtitle = subtitle;
    this->duration = duration;
    this->thumbnailUrl = thumbnailUrl;
    this->imageContainer = imageContainer;
    this->features = features;
    this->price = price;
    this->hasActive = hasActive;
    this->spaceLeft = spaceLeft;
    this->spaceFull = spaceFull;
    this->session = session;

    this->className = "Course";
    this->field = new _fields();
}

Session *Course::getSession() const
{
    return session;
}

void Course::setSession(Session *newSession)
{
    session = newSession;
}

int Course::getSpaceFull() const
{
    return spaceFull;
}

void Course::setSpaceFull(int newSpaceFull)
{
    spaceFull = newSpaceFull;
}

int Course::getSpaceLeft() const
{
    return spaceLeft;
}

void Course::setSpaceLeft(int newSpaceLeft)
{
    spaceLeft = newSpaceLeft;
}

bool Course::getHasActive() const
{
    return hasActive;
}

void Course::setHasActive(bool newHasActive)
{
    hasActive = newHasActive;
}

int Course::getPrice() const
{
    return price;
}

void Course::setPrice(int newPrice)
{
    price = newPrice;
}

QList<QString> *Course::getFeatures() const
{
    return features;
}

void Course::setFeatures(QList<QString> *newFeatures)
{
    features = newFeatures;
}

const QString &Course::getImageContainer() const
{
    return imageContainer;
}

void Course::setImageContainer(const QString &newImageContainer)
{
    imageContainer = newImageContainer;
}

const QString &Course::getThumbnailUrl() const
{
    return thumbnailUrl;
}

void Course::setThumbnailUrl(const QString &newThumbnailUrl)
{
    thumbnailUrl = newThumbnailUrl;
}

const QString &Course::getDuration() const
{
    return duration;
}

void Course::setDuration(const QString &newDuration)
{
    duration = newDuration;
}

const QString &Course::getSubtitle() const
{
    return subtitle;
}

void Course::setSubtitle(const QString &newSubtitle)
{
    subtitle = newSubtitle;
}

const QString &Course::getTitle() const
{
    return title;
}

void Course::setTitle(const QString &newTitle)
{
    title = newTitle;
}


QList<QString> Course::getAllFields()
{

}

QString Course::getPackageName()
{
    return this->className;
}

QList<Course *> Course::parseJSONArray(QJsonArray o) throw()
{

}

Course *Course::parseJSONObject(QJsonObject o) throw()
{

}

QList<Course *> Course::parseArrayString(QString o) throw()
{

}

Course *Course::parseObjectString(QString o) throw()
{

}

bool Course::equal(Course *o)
{
    return o == this;
}

void Course::copy(Course *course)
{
    this->title = course->title;
    this->subtitle = course->subtitle;
    this->duration = course->duration;
    this->thumbnailUrl = course->thumbnailUrl;
    this->imageContainer = course->imageContainer;
    this->features = course->features;
    this->price = course->price;
    this->hasActive = course->hasActive;
    this->spaceLeft = course->spaceLeft;
    this->spaceFull = course->spaceFull;
    this->session = course->session;
}

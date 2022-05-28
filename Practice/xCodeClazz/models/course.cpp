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

QList<Course *> Course::parseJSONArray(QJsonArray o) throw(ExceptionThrow)
{
    QList<Course *> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Course::parseJSONArrayToVariantList(QJsonArray o) throw(ExceptionThrow)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

QVariant Course::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
}

Course *Course::parseJSONObject(QJsonObject o) throw(ExceptionThrow)
{
    if (o.isEmpty()) return nullptr;
    Course *n = new Course();

    try {
        if (o.contains(field->title)) {
            n->setTitle(o.value("title").toString());
        } else {
            n->setTitle(fallbackValue);
            throw (new ExceptionThrow(field->title));
        }
    }  catch (QString error) {
        n->setTitle(error);
    }

    try {
        if (o.contains(field->subtitle)) {
            n->setSubtitle(o.value("subtitle").toString());
        } else {
            n->setSubtitle(fallbackValue);
            throw (new ExceptionThrow(field->subtitle));
        }
    }  catch (QString error) {
        n->setSubtitle(error);
    }

    try {
        if (o.contains(field->duration)) {
            n->setDuration(o.value("duration").toString());
        } else {
            n->setDuration(fallbackValue);
            throw (new ExceptionThrow(field->duration));
        }
    }  catch (QString error) {
        n->setDuration(error);
    }

    try {
        if (o.contains(field->thumbnailUrl)) {
            n->setThumbnailUrl(o.value("thumbnailUrl").toString());
        } else {
            n->setThumbnailUrl(fallbackValue);
            throw (new ExceptionThrow(field->thumbnailUrl));
        }
    }  catch (QString error) {
        n->setThumbnailUrl(error);
    }

    try {
        if (o.contains(field->imageContainer)) {
            n->setImageContainer(o.value("imageContainer").toString());
        } else {
            n->setImageContainer(fallbackValue);
            throw (new ExceptionThrow(field->imageContainer));
        }
    }  catch (QString error) {
        n->setImageContainer(error);
    }

    QList<QString> res;
    try {
        if (o.contains(field->features)) {
            n->setFeatures(parseOnlyStringJSONArray(o.value("features").toArray()));
        } else {
            n->setFeatures(nullptr);
            throw (new ExceptionThrow(field->features));
        }
    }  catch (QString error) {
        n->setFeatures(nullptr);
    }

    try {
        if (o.contains(field->price)) {
            n->setPrice(o.value("price").toInt());
        } else {
            n->setPrice(fallbackZero);
            throw (new ExceptionThrow(field->price));
        }
    }  catch (QString error) {
        n->setPrice(fallbackZero);
    }

    try {
        if (o.contains(field->hasActive)) {
            n->setHasActive(o.value("hasActive").toInt());
        } else {
            n->setHasActive(false);
            throw (new ExceptionThrow(field->hasActive));
        }
    }  catch (QString error) {
        n->setHasActive(false);
    }

    try {
        if (o.contains(field->spaceLeft)) {
            n->setSpaceLeft(o.value("spaceLeft").toInt());
        } else {
            n->setSpaceLeft(fallbackZero);
            throw (new ExceptionThrow(field->spaceLeft));
        }
    }  catch (QString error) {
        n->setSpaceLeft(fallbackZero);
    }

    try {
        if (o.contains(field->spaceFull)) {
            n->setSpaceLeft(o.value("spaceFull").toInt());
        } else {
            n->setSpaceLeft(fallbackZero);
            throw (new ExceptionThrow(field->spaceFull));
        }
    }  catch (QString error) {
        n->setSpaceLeft(fallbackZero);
    }

    try {
        if (o.contains(field->session)) {
            n->setSession((new Session())->parseJSONObject(o.value("session").toObject()));
        } else {
            n->setSession(nullptr);
            throw (new ExceptionThrow(field->session));
        }
    }  catch (QString error) {
        n->setSession(nullptr);
    }

    return n;
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

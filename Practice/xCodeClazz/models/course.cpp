#include "models/course.h"

Course::Course(QObject *parent)
{
    this->className = "Course";
    this->fields = new _fields();
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
    this->fields = new _fields();
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

QList<Course*> Course::parseJSONArray(QJsonArray o)
{
    QList<Course*> list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObject(o.at(i).toObject()));
    }
    return list;
}

QVariantList Course::parseJSONArrayToVariantList(QJsonArray o)
{
    QVariantList list;
    if (o.empty()) return list;
    for(int i = 0; i < o.size(); i++) {
        list.append(parseJSONObjectToVariant(o.at(i).toObject()));
    }
    return list;
}

Course *Course::parseJSONObject(QJsonObject o)
{
    if (o.isEmpty()) return nullptr;
    Course *n = new Course();

    try {
        if (o.contains(fields->title)) {
            n->setTitle(o.value(fields->title).toString());
        } else {
            n->setTitle(fallbackValue);
        }
    }  catch (QString error) {
        n->setTitle(error);
    }

    try {
        if (o.contains(fields->subtitle)) {
            n->setSubtitle(o.value(fields->subtitle).toString());
        } else {
            n->setSubtitle(fallbackValue);
        }
    }  catch (QString error) {
        n->setSubtitle(error);
    }

    try {
        if (o.contains(fields->duration)) {
            n->setDuration(o.value(fields->duration).toString());
        } else {
            n->setDuration(fallbackValue);
        }
    }  catch (QString error) {
        n->setDuration(error);
    }

    try {
        if (o.contains(fields->thumbnailUrl)) {
            n->setThumbnailUrl(o.value(fields->thumbnailUrl).toString());
        } else {
            n->setThumbnailUrl(fallbackValue);
        }
    }  catch (QString error) {
        n->setThumbnailUrl(error);
    }

    try {
        if (o.contains(fields->imageContainer)) {
            n->setImageContainer(o.value(fields->imageContainer).toString());
        } else {
            n->setImageContainer(fallbackValue);
        }
    }  catch (QString error) {
        n->setImageContainer(error);
    }

    QList<QString> res;
    try {
        if (o.contains(fields->features)) {
            n->setFeatures(parseOnlyStringJSONArray(o.value(fields->features).toArray()));
        } else {
            n->setFeatures(nullptr);
        }
    }  catch (QString error) {
        n->setFeatures(nullptr);
    }

    try {
        if (o.contains(fields->price)) {
            n->setPrice(o.value(fields->price).toInt());
        } else {
            n->setPrice(fallbackZero);
        }
    }  catch (QString error) {
        n->setPrice(fallbackZero);
    }

    try {
        if (o.contains(fields->hasActive)) {
            n->setHasActive(o.value(fields->hasActive).toInt());
        } else {
            n->setHasActive(false);
        }
    }  catch (QString error) {
        n->setHasActive(false);
    }

    try {
        if (o.contains(fields->spaceLeft)) {
            n->setSpaceLeft(o.value(fields->spaceLeft).toInt());
        } else {
            n->setSpaceLeft(fallbackZero);
        }
    }  catch (QString error) {
        n->setSpaceLeft(fallbackZero);
    }

    try {
        if (o.contains(fields->spaceFull)) {
            n->setSpaceLeft(o.value(fields->spaceFull).toInt());
        } else {
            n->setSpaceLeft(fallbackZero);
        }
    }  catch (QString error) {
        n->setSpaceLeft(fallbackZero);
    }

    try {
        if (o.contains(fields->session)) {
            n->setSession((new Session())->parseJSONObject(o.value(fields->session).toObject()));
        } else {
            n->setSession(nullptr);
        }
    }  catch (QString error) {
        n->setSession(nullptr);
    }

    return n;
}

QVariant Course::parseJSONObjectToVariant(QJsonObject o)
{
    if (o.isEmpty()) return QVariant();
    QVariant v(o);
    return v;
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

QJsonObject Course::getAsJson() const
{
    QJsonObject mainObject;
    mainObject.insert(this->fields->title, this->title);
    mainObject.insert(this->fields->subtitle, this->subtitle);
    mainObject.insert(this->fields->duration, this->duration);
    mainObject.insert(this->fields->thumbnailUrl, this->thumbnailUrl);
    mainObject.insert(this->fields->imageContainer, this->imageContainer);
    mainObject.insert(this->fields->features, this->features->join(", "));
    mainObject.insert(this->fields->price, this->price);
    mainObject.insert(this->fields->hasActive, this->hasActive);
    mainObject.insert(this->fields->spaceLeft, this->spaceLeft);
    mainObject.insert(this->fields->spaceFull, this->spaceFull);
    mainObject.insert(this->fields->session, this->session->getAsJson());
    return mainObject;
}

QJsonArray Course::getAsJsonArray(QList<Course> *t) const
{
    QJsonArray array;
    for (int var = 0; var < t->size(); ++var) array.append(t->at(var).getAsJson());
    return array;
}

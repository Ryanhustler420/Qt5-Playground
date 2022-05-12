#include "models\category.h"

Category::Category(const QString &id, const QString &title, QList<QString> *canAccessBy, int indexPosition)
{
    this->_id = id;
    this->title = title;
    this->canAccessBy = canAccessBy;
    this->indexPosition = indexPosition;

    this->className = "Category";
    this->fields = new _fields();
}

const QString &Category::getId() const
{
    return _id;
}

void Category::setId(const QString &newId)
{
    _id = newId;
}

const QString &Category::getTitle() const
{
    return title;
}

void Category::setTitle(const QString &newTitle)
{
    title = newTitle;
}

const QList<QString> *Category::getCanAccessBy() const
{
    return canAccessBy != nullptr ? canAccessBy : new QList<QString>();
}

void Category::setCanAccessBy(QList<QString>* newCanAccessBy)
{
    canAccessBy = newCanAccessBy;
}

int Category::getIndexPosition() const
{
    return indexPosition;
}

void Category::setIndexPosition(int newIndexPosition)
{
    indexPosition = newIndexPosition;
}

QList<QString> Category::getAllFields()
{

}

QString Category::getPackageName()
{
    return this->className;
}

QList<Category *> Category::parseJSONArray(QJsonArray o) throw()
{

}

Category *Category::parseJSONObject(QJsonObject o) throw()
{

}

QList<Category *> Category::parseArrayString(QString o) throw()
{

}

Category *Category::parseObjectString(QString o) throw()
{

}

bool Category::equal(Category *o)
{
    return o == this;
}

/* Helper Methods */

bool Category::canNormalUserAccess()
{
    return getCanAccessBy()->contains(NORMAL);
}

bool Category::canMasterUserAccess()
{
    return getCanAccessBy()->contains(MASTER);
}

QString Category::getBulletConcatenatedCategoryNames(QList<Category>* categories)
{
    if (categories == nullptr) return NOT_MENTIONED;
    QByteArray sb;
    for (int var = 0; var < categories->size(); ++var) {
        sb.append(categories->at(var).getTitle()).append(" ").append(" * ").append(" ");
    }
    return sb;
}

bool Category::hasTitle(QString what)
{
    if (what == nullptr) return false;
    return this->getTitle().toLower().startsWith(what.toLower());
}

bool Category::hasLabel(QString what)
{
    return this->hasTitle(what);
}

bool Category::isGeneric()
{
    return this->getTitle().compare(GENERIC);
}

QList<int>* Category::getAllTheIndexes(QList<Category>* categories)
{
    QList<int> *_categories = new QList<int>();
    if (categories != nullptr)
        for (int var = 0; var < categories->size(); ++var) {
            _categories->append(categories->at(var).getIndexPosition());
        }
    else _categories->append(-1);
    return _categories;
}

QList<QString>* Category::onlyIDS(QList<Category>* categories)
{
    QList<QString> *_categories = new QList<QString>();
    for (int var = 0; var < categories->size(); ++var) {
        _categories->append(categories->at(var).getId());
    }
    return _categories;
}

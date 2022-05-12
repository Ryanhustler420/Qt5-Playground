#ifndef CATEGORY_H
#define CATEGORY_H

#include "models/god/modelconventions.h"
#include "shareable/constants.h"

#define GENERICID "6003d3d486d574250c7bfb9b"
#define GENERIC "Generic"

class Category : public ModelConventions<Category>
{
    Q_OBJECT
public:
    explicit Category(QObject *parent = nullptr);
    Category(const QString &id, const QString &title, QList<QString> *canAccessBy, int indexPosition);

private:
    QString _id;
    QString title;
    QList<QString> *canAccessBy;
    int indexPosition;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString title = "title";
        QString canAccessBy = "canAccessBy";
        QString indexPosition = "indexPosition";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Category *> parseJSONArray(QJsonArray o) throw();
    Category *parseJSONObject(QJsonObject o) throw();
    QList<Category *> parseArrayString(QString o) throw();
    Category *parseObjectString(QString o) throw();
    bool equal(Category *o);

    const QString &getId() const;
    void setId(const QString &newId);
    const QString &getTitle() const;
    void setTitle(const QString &newTitle);
    const QList<QString> *getCanAccessBy() const;
    void setCanAccessBy(QList<QString>* newCanAccessBy);
    int getIndexPosition() const;
    void setIndexPosition(int newIndexPosition);

    bool canNormalUserAccess();
    bool canMasterUserAccess();
    QString getBulletConcatenatedCategoryNames(QList<Category>* categories);
    bool hasTitle(QString what);
    bool hasLabel(QString what);
    bool isGeneric();
    static QList<int>* getAllTheIndexes(QList<Category>* categories);
    static QList<QString>* onlyIDS(QList<Category>* categories);
};

#endif // CATEGORY_H

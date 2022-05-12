#ifndef CONTRIBUTOR_H
#define CONTRIBUTOR_H

#include "models/god/modelconventions.h"

class Contributor : public ModelConventions<Contributor>
{
    Q_OBJECT
public:
    explicit Contributor(QObject *parent = nullptr);
    Contributor(const QString &id, const QString &name, const QString &imageUrl, const QString &imageContainer);

private:
    QString _id;
    QString name;
    QString imageUrl;
    QString imageContainer;

private:
    typedef struct FIELDS {
        QString _id = "_id";
        QString name = "name";

        QString imageUrl = "imageUrl";
        QString imageContainer = "imageContainer";
    } _fields;

    _fields *fields;

signals:

    // ModelConventions interface
public:
    QList<QString> getAllFields();
    QString getPackageName();
    QList<Contributor *> parseJSONArray(QJsonArray o) throw();
    Contributor *parseJSONObject(QJsonObject o) throw();
    QList<Contributor *> parseArrayString(QString o) throw();
    Contributor *parseObjectString(QString o) throw();
    bool equal(Contributor *o);

    const QString &id() const;
    void setId(const QString &newId);
    const QString &getName() const;
    void setName(const QString &newName);
    const QString &getImageUrl() const;
    void setImageUrl(const QString &newImageUrl);
    const QString &getImageContainer() const;
    void setImageContainer(const QString &newImageContainer);
};

#endif // CONTRIBUTOR_H
